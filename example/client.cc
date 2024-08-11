#include "mprpcapplication.h"
#include "monitor_info.pb.h"
#include "mprpcchannel.h"
#include "monitor.h"
#include "cpu_load.h"
// #include"mysql_monitor.h"
#include <memory>
#include <thread>
#include <vector>
#include <iostream>
#include <iomanip>
#define HOST "localhost"
#define USER "monitor"
#define PASSWD "123456"
#define DBHAME "monitor"

int main(int argc, char **argv)
{
    MprpcApplication::Init(argc, argv);
    monitor::proto::RpcManager_Stub stub(new MprpcChannel());
    // MpRpcContrller contrller;
    ::monitor::proto::machine request;
    monitor::proto::MonitorInfo monitor_info;
    char buf[64] = {0};
    std::cin >> buf;
    for (;;)
    {

        request.set_name(buf);
        stub.GetMonitorInfo(nullptr, &request, &monitor_info, nullptr);
        // mysql_monitor mysql(HOST,USER,PASSWD,DBHAME);
        // mysql.insert(&monitor_info);
        auto cpu_load = monitor_info.mutable_cpu_load();
        std::cout << "user name: " << monitor_info.name() << std::endl;
        // auto net = monitor_info.net_info();

        std::cout << "CpuLoad: " << std::endl;
        std::cout << "   " << cpu_load->lavg_1() << "  " << cpu_load->lavg_3() << "  " << cpu_load->lavg_15() << std::endl;
        std::cout << "CpuStat: " << std::endl;
        for (int i = 0; i < monitor_info.cpu_stat_size(); i++)
        {
            printf("%%%07s :", monitor_info.cpu_stat(i).cpu_name().c_str());
            std::cout << std::fixed << std::setprecision(2) << monitor_info.cpu_stat(i).cpu_precent() << " ";
            std::cout << std::fixed << std::setprecision(2) << monitor_info.cpu_stat(i).user_precent() << "  ";
            std::cout << std::fixed << std::setprecision(2) << monitor_info.cpu_stat(i).system_precent() << "  ";
            std::cout << std::fixed << std::setprecision(2) << monitor_info.cpu_stat(i).nice_precent() << "  ";
            std::cout << std::fixed << std::setprecision(2) << monitor_info.cpu_stat(i).idle_precent() << "  ";
            std::cout << std::fixed << std::setprecision(2) << monitor_info.cpu_stat(i).iowait_precent() << "  ";
            std::cout << std::fixed << std::setprecision(2) << monitor_info.cpu_stat(i).irq_precent() << "  ";
            std::cout << std::fixed << std::setprecision(2) << monitor_info.cpu_stat(i).softirp_precent() << "  ";
            std::cout << std::endl;
        }
        std::cout << "NetInfo: " << std::endl;
        for (int i = 0; i < monitor_info.net_info_size(); i++)
        {
            printf("%07s :", monitor_info.net_info(i).name().c_str());
            std::cout << std::fixed << std::setprecision(2) << monitor_info.net_info(i).recv_rate() << "kb/s  ";
            std::cout << std::fixed << std::setprecision(2) << monitor_info.net_info(i).send_rate() << "kb/s  ";
            std::cout << std::fixed << std::setprecision(2) << monitor_info.net_info(i).recv_packets_rate() << "kb/s  ";
            std::cout << std::fixed << std::setprecision(2) << monitor_info.net_info(i).send_packets_rate() << "kb/s  ";
            std::cout << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    }
}