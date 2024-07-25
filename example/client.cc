#include "mprpcapplication.h"
#include "monitor_info.pb.h"
#include "monitor.h"
#include "cpu_load.h"
#include <memory>
#include <thread>
#include <vector>



int main(int argc, char **argv)
{
    MprpcApplication::Init(argc, argv);
    monitor::proto::RpcManager_Stub stub(new MprpcChannel());
    MpRpcContrller contrller;
    monitor::proto::MonitorInfo monitor_info;
    stub.GetMonitorInfo(&contrller,nullptr,&monitor_info,nullptr);
    auto cpu_load = monitor_info.mutable_cpu_load();
    std::cout<<cpu_load->lavg_1()<<std::endl;
    std::cout<<cpu_load->lavg_3()<<std::endl;
    std::cout<<cpu_load->lavg_15()<<std::endl;
}