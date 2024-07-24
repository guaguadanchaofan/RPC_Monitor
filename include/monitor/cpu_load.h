#pragma once

#include "monitor.h"

namespace monitor
{
    class CpuLoadMonitor : public MonitorInter
    {
    public:
        CpuLoadMonitor() {}
        void UpdataOnce(monitor::proto::MonitorInfo* monitor_info);
        void Stop()override{}

    private:
    float load_avg_1;
    float load_avg_3;
    float load_avg_15;
    };
}