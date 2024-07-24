#pragma once

#include "monitor.h"
#include <string>
#include <unordered_map>
#include <boost/chrono.hpp>
#include "monitor_info.pb.h"
#include "utils/read_file.h"
#include "utils/utils.h"
namespace monitor
{
    class CpuSoftIrqMonitor : public MonitorInter
    {

        struct SoftIrq
        {
            std::string cpu_name;
            int64_t hi;                                         // 高优先级软中断计数
            int64_t timer;                                      // 定时器软中断计数
            int64_t net_tx;                                     // 网络发送软中断计数
            int64_t net_rx;                                     // 网络接收软中断计数
            int64_t block;                                      // 块设备软中断计数
            int64_t irq_poll;                                   // 中断轮询软中断计数
            int64_t tasklet;                                    // 任务软中断计数
            int64_t sched;                                      // 调度软中断计数
            int64_t hrtimer;                                    // 高分辨率定时器软中断计数
            int64_t rcu;                                        // RCU软中断计数
            boost::chrono::steady_clock::time_point time_point; // 时间点
        };

    public:
        CpuSoftIrqMonitor() {}
        void UpdataOnce(monitor::proto::MonitorInfo *monitor_info);
        void Stop() override {}

    private:
        std::unordered_map<std::string, struct SoftIrq> _cpu_softirq;
    };
}