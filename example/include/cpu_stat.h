#pragma once
#include "monitor.h"
#include <unordered_map>
#include <string>
namespace monitor
{
    class CpuStatMonitor : public MonitorInter
    {
        struct CpuStat
        {
            std::string cpu_name;
            float user;
            float system;
            float idle;
            float nice;
            float io_wait;
            float irq;
            float soft_irq;
            float steal;
            float guest;
            float guest_nice;
        };

    public:
        CpuStatMonitor() {}
        void UpdataOnce(monitor::proto::MonitorInfo *monitor_info);
        void Stop() override {}

    private:
        std::unordered_map<std::string, struct CpuStat> _cpu_stat;
    };
}