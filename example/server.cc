#include "mprpcapplication.h"
#include "monitor_info.pb.h"
#include "monitor.h"
#include "cpu_load.h"
#include"rpcprovider.h"
#include <memory>
#include <thread>
#include <vector>
namespace monitor
{
    class RpcManagerInter : public monitor::proto::RpcManager
    {
        void SetMonitorInfo(::google::protobuf::RpcController *controller,
                            const ::monitor::proto::MonitorInfo *request,
                            monitor::proto::Code *response,
                            ::google::protobuf::Closure *done)
        {
            _monitorinfo.Clear();
            response->set_code(1);
            _monitorinfo = *request;
            done->Run();
        }
        void GetMonitorInfo(::google::protobuf::RpcController *controller,
                            const monitor::proto::Code *request,
                            ::monitor::proto::MonitorInfo *response,
                            ::google::protobuf::Closure *done)
        {
            *response = _monitorinfo;
            done->Run();
        }
    private:
        monitor::proto::MonitorInfo _monitorinfo;
    };
}
int main(int argc, char **argv)
{
    MprpcApplication::Init(argc, argv);
    RpcProvider provider;
    provider.NotifyService(new monitor::RpcManagerInter());
    provider.Run();
    return 0;
}