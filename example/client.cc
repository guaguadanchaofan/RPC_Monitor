#include "mprpcapplication.h"
#include "monitor_info.pb.h"
#include "mprpcchannel.h"
#include "monitor.h"
#include "cpu_load.h"
#include <memory>
#include <thread>
#include <vector>



int main(int argc, char **argv)
{
    MprpcApplication::Init(argc, argv);
    monitor::proto::RpcManager_Stub stub(new MprpcChannel());
    //MpRpcContrller contrller;
    ::monitor::proto::Code request;
    request.set_code(1);
    monitor::proto::MonitorInfo monitor_info;
    for(;;)
    {
        stub.GetMonitorInfo(nullptr,&request,&monitor_info,nullptr);
        auto cpu_load = monitor_info.mutable_cpu_load();
        std::cout<<"  one     min load :"<<cpu_load->lavg_1()<<std::endl;
        std::cout<<"  three   min load :"<<cpu_load->lavg_3()<<std::endl;
        std::cout<<"  fifteen min load :"<<cpu_load->lavg_15()<<std::endl;
        sleep(2);
    }
    
}