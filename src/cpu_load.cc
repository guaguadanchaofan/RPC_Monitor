#include"cpu_load.h"
#include"read_file.h"
#include"monitor_info.pb.h"
namespace monitor
{
    void CpuLoadMonitor::UpdataOnce(monitor::proto::MonitorInfo* monitor_info)
    {
        ReadFile cpu_load_file(std::string("/proc/loadavg"));
        std::vector<std::string> cpu_load;
        cpu_load_file.ReadLine(&cpu_load);
        load_avg_1 = std::stof(cpu_load[0]);  //stof字符串转浮点
        load_avg_3 = std::stof(cpu_load[1]);
        load_avg_15 = std::stof(cpu_load[2]);
        monitor::proto::CpuLoad* cpu_load_msg = monitor_info->mutable_cpu_load();
        cpu_load_msg->set_lavg_1(load_avg_1);
        cpu_load_msg->set_lavg_3(load_avg_3);
        cpu_load_msg->set_lavg_15(load_avg_15);
        return;
    }
}


