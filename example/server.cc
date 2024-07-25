#include "mprpcapplication.h"
#include "monitor_info.pb.h"
#include "monitor.h"
#include "cpu_load.h"
#include <memory>
#include <thread>
#include <vector>
namespace monitor
{
    class RpcManagerInter : public monitor::proto::RpcManager
    {
        void SetMonitorInfo(::google::protobuf::RpcController *controller,
                            const ::monitor::proto::MonitorInfo *request,
                            google::protobuf::Empty *response,
                            ::google::protobuf::Closure *done)
        {
            _monitorinfo.Clear();
            _monitorinfo = *request;
        }
        void GetMonitorInfo(::google::protobuf::RpcController *controller,
                            const google::protobuf::Empty *request,
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