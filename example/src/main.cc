#pragma once
#include <memory>
#include <thread>
#include <vector>

// #include "client/rpc_client.h"
#include "include/monitor/cpu_load.h"
#include "include/monitor/cpu_softirq.h"
#include "include/monitor/cpu_stat.h"
#include "include/monitor/monitor.h"
#include "monitor_info.pb.h"

// #include "include/monitor/mem_monitor.h"
// #include "include/monitor/monitor_inter.h"
// #include "include/monitor/net_monitor.h"
// #include "include/monitor_info.grpc.pb.h"

int main()
{
    std::vector<std::shared_ptr<monitor::MonitorInter>> runners_;
    runners_.emplace_back(new monitor::CpuSoftIrqMonitor());
    runners_.emplace_back(new monitor::CpuLoadMonitor());
    runners_.emplace_back(new monitor::CpuStatMonitor());

    return 0;
}
