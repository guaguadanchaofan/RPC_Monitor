#include "mprpcapplication.h"
#include "monitor_info.pb.h"
#include "monitor.h"
#include "cpu_load.h"
#include "lockqueue.h"
#include "rpcprovider.h"
#include <memory>
#include <thread>
#include <vector>
#include <unordered_map>
#include "ConnectionPool.h"

#define INSERT_CPULOAD "insert into cpu_load values('%s',now(),%f,%f,%f);"
namespace monitor
{
    class RpcManagerInter : public monitor::proto::RpcManager
    {
    public:
        RpcManagerInter(ConnectionPool *conn) : _conn(conn)
        {
        }
        void SetMonitorInfo(::google::protobuf::RpcController *controller,
                            const ::monitor::proto::MonitorInfo *request,
                            monitor::proto::Code *response,
                            ::google::protobuf::Closure *done)
        {
            //_monitorinfo.Clear();
            response->set_code(1);
            auto machine = request->name();
            _monitorMap[machine] = *request;
            _monitorQ.Push(*request); // 加入到消息队列中
            //_monitorinfo = *request;
            done->Run();
        }
        void GetMonitorInfo(::google::protobuf::RpcController *controller,
                            const monitor::proto::machine *request,
                            ::monitor::proto::MonitorInfo *response,
                            ::google::protobuf::Closure *done)
        {
            std::string machine = request->name();
            *response = _monitorMap[machine];
            done->Run();
        }
        void checkMonitor()
        {
            while (true)
            {
                monitor::proto::MonitorInfo info = _monitorQ.Pop();
                if (info.cpu_load().lavg_1()> 0.1)
                {
                    std::shared_ptr<databaseConnect> conn = _conn->getConnection();
                    //auto cpu_load = _monitorMap[name].cpu_load();
                    float lavg_1 = info.cpu_load().lavg_1();
                    float lavg_3 = info.cpu_load().lavg_3();
                    float lavg_15 = info.cpu_load().lavg_15();
                    char sql[4096] = {0};
                    sprintf(sql, INSERT_CPULOAD, info.name().c_str(), lavg_1, lavg_3, lavg_15);
                    if (conn->update(sql))
                    {
                        std::cout << "=======success==========" << std::endl;
                    }
                    else
                    {
                        std::cout << "=========error==========" << std::endl;
                        std::cout << sql << std::endl;
                    }
                }
            }
        }

    private:
        // monitor::proto::MonitorInfo _monitorinfo;
        ConnectionPool *_conn;                                                    // 连接池
        LockQueue<monitor::proto::MonitorInfo> _monitorQ;                         // 消息队列
        std::unordered_map<std::string, monitor::proto::MonitorInfo> _monitorMap; // 映射表
    };
}
int main(int argc, char **argv)
{
    MprpcApplication::Init(argc, argv);
    RpcProvider provider;
    ConnectionPool *conn = ConnectionPool::getConnectPool();
    monitor::RpcManagerInter* inter = new monitor::RpcManagerInter(conn);
    //std::thread check(monitor::RpcManagerInter::checkMonitor, inter);
    std::thread check(std::bind(&monitor::RpcManagerInter::checkMonitor, inter));
    //check.detach();
    provider.NotifyService(inter);
    provider.Run();
    return 0;
}