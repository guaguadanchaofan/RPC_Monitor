#include "mprpcapplication.h"
#include "monitor_info.pb.h"
#include "monitor.h"
#include "cpu_load.h"
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
            std::thread check(&monitor::RpcManagerInter::checkMonitor, this, machine);
            check.detach();
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
        void checkMonitor(std::string name)
        {
            if (_monitorMap[name].cpu_load().lavg_1() > 0.5)
            {
                std::shared_ptr<databaseConnect> conn = _conn->getConnection();
                auto cpu_load = _monitorMap[name].cpu_load();
                float lavg_1 = cpu_load.lavg_1();
                float lavg_3 = cpu_load.lavg_3();
                float lavg_15 = cpu_load.lavg_15();
                char sql[4096] = {0};
                sprintf(sql, INSERT_CPULOAD, name.c_str(), lavg_1, lavg_3, lavg_15);
                if(conn->update(sql))
                {
                    std::cout<<"=======success=========="<<std::endl;
                }
                else
                {
                    std::cout<<"======= ERROR =========="<<std::endl;
                    std::cout << sql <<std::endl;
                }
            }
        }

    private:
        // monitor::proto::MonitorInfo _monitorinfo;
        ConnectionPool *_conn;
        std::unordered_map<std::string, monitor::proto::MonitorInfo> _monitorMap;
    };
}
int main(int argc, char **argv)
{
    MprpcApplication::Init(argc, argv);
    RpcProvider provider;
    ConnectionPool *conn = ConnectionPool::getConnectPool();
    provider.NotifyService(new monitor::RpcManagerInter(conn));
    provider.Run();
    return 0;
}