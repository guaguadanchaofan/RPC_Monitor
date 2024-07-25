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
    //MpRpcContrller contrller;
    std::vector<std::shared_ptr<monitor::MonitorInter>> runners_;
    runners_.emplace_back(new monitor::CpuLoadMonitor());
    char *name = getenv("USER");
    for (;;)
    {
        monitor::proto::Code code;
        monitor::proto::MonitorInfo monitor_info;
        monitor_info.set_name(std::string(name));
        for (auto &runner : runners_)
        {
            runner->UpdataOnce(&monitor_info);
        }
        stub.SetMonitorInfo(nullptr, &monitor_info, &code, nullptr);
        sleep(1);
        //std::this_thread::sleep_for(std::chrono::seconds(3));
    }
    return 0;
}