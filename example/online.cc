#include <vector>
#include <thread>
#include <memory>
#include "mprpcapplication.h"
#include "monitor_info.pb.h"
#include "monitor.h"
#include "cpu_load.h"

int main(int argc, char **argv)
{
    MprpcApplication::Init(argc, argv);
    monitor::proto::RpcManager_Stub stub(new MprpcChannel());
    MpRpcContrller contrller;
    std::vector<std::shared_ptr<monitor::MonitorInter>> runners_;
    runners_.emplace_back(new monitor::CpuLoadMonitor());
    char *name = getenv("USER");
    std::thread workmoniotr([&]()
                            {
    for(;;)
    {
        monitor::proto::MonitorInfo monitor_info;
        monitor_info.set_name(std::string(name));
    for(auto &runner: runners_)
    {
         runner->UpdataOnce(&monitor_info);
    }
        stub.SetMonitorInfo(&contrller,&monitor_info,nullptr,nullptr);
    if (contrller.Failed())
    {
        std::cout<<contrller.ErrorText()<<std::endl;
    }
    else
    {

        std::cout << "rpc longin response success  " << std::endl;
    }
    } });
    return 0;
}