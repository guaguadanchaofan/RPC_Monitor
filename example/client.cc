#include "mprpcapplication.h"
#include "monitor_info.pb.h"
#include "mprpcchannel.h"
#include "monitor.h"
#include "cpu_load.h"
#include <memory>
#include <thread>
#include <vector>
#include<iostream>
#include<iomanip>

int main(int argc, char **argv)
{
    MprpcApplication::Init(argc, argv);
    monitor::proto::RpcManager_Stub stub(new MprpcChannel());
    // MpRpcContrller contrller;
    ::monitor::proto::Code request;
    request.set_code(1);
    monitor::proto::MonitorInfo monitor_info;
    for (;;)
    {
        stub.GetMonitorInfo(nullptr, &request, &monitor_info, nullptr);
        auto cpu_load = monitor_info.mutable_cpu_load();
        std::cout << "user name: " << monitor_info.name() << std::endl;
        // auto net = monitor_info.net_info();

        std::cout << "CpuLoad: " << std::endl;
        std::cout << "   " << cpu_load->lavg_1() << "  " << cpu_load->lavg_3() << "  " << cpu_load->lavg_15() << std::endl;
        std::cout << "CpuStat: " << std::endl;
        for (int i = 0; i < monitor_info.cpu_stat_size(); i++)
        {
            printf("%%%07s :", monitor_info.cpu_stat(i).cpu_name().c_str());
            std::cout <<std::fixed<<std::setprecision(2) <<monitor_info.cpu_stat(i).cpu_precent() << " ";
            std::cout << std::fixed<<std::setprecision(2) <<monitor_info.cpu_stat(i).user_precent() << "  ";
            std::cout << std::fixed<<std::setprecision(2) <<monitor_info.cpu_stat(i).system_precent() << "  ";
            std::cout << std::fixed<<std::setprecision(2) <<monitor_info.cpu_stat(i).nice_precent() << "  ";
            std::cout << std::fixed<<std::setprecision(2) <<monitor_info.cpu_stat(i).idle_precent() << "  ";
            std::cout <<std::fixed<<std::setprecision(2) << monitor_info.cpu_stat(i).iowait_precent() << "  ";
            std::cout << std::fixed<<std::setprecision(2) <<monitor_info.cpu_stat(i).irq_precent() << "  ";
            std::cout << std::fixed<<std::setprecision(2) <<monitor_info.cpu_stat(i).softirp_precent() << "  ";
            std::cout << std::endl;
        }
        std::cout << "NetInfo: " << std::endl;
        for (int i = 0; i < monitor_info.net_info_size(); i++)
        {
            printf("%07s :", monitor_info.net_info(i).name().c_str());
            std::cout <<std::fixed<<std::setprecision(2) << monitor_info.net_info(i).recv_rate() << "kb/s  ";
            std::cout << std::fixed<<std::setprecision(2) <<monitor_info.net_info(i).send_rate() << "kb/s  ";
            std::cout << std::fixed<<std::setprecision(2) <<monitor_info.net_info(i).recv_packets_rate() << "kb/s  ";
            std::cout <<std::fixed<<std::setprecision(2) << monitor_info.net_info(i).send_packets_rate() << "kb/s  ";
            std::cout << std::endl;
        }
        sleep(3);
    }
}