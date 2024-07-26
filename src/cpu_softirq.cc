#include "cpu_softirq.h"
#include <boost/chrono.hpp>
namespace monitor
{
    void CpuSoftIrqMonitor::UpdataOnce(monitor::proto::MonitorInfo *monitor_info)
    {
        ReadFile softirq_file(std::string("/proc/softirqs"));
        std::vector<std::string> one_softirq;          // 存储单行数据
        std::vector<std::vector<std::string>> softirq; // 存储总数居
        while (softirq_file.ReadLine(&one_softirq))
        {
            softirq.push_back(one_softirq);
            one_softirq.clear();
        }
        for (int i = 0; i < 10; ++i)
        {
            std::string name = softirq[0][i];
            struct SoftIrq info;
            info.cpu_name = name;
            info.hi = std::stoll(softirq[1][i + 1]);
            info.timer = std::stoll(softirq[2][i + 1]);
            info.net_tx = std::stoll(softirq[3][i + 1]);
            info.net_rx = std::stoll(softirq[4][i + 1]);
            info.block = std::stoll(softirq[5][i + 1]);
            info.irq_poll = std::stoll(softirq[6][i + 1]);
            info.tasklet = std::stoll(softirq[7][i + 1]);
            info.sched = std::stoll(softirq[8][i + 1]);
            info.hrtimer = std::stoll(softirq[9][i + 1]);
            info.rcu = std::stoll(softirq[10][i + 1]);
            info.time_point = boost::chrono::steady_clock::now();

            auto iter = _cpu_softirq.find(name);
            if (iter != _cpu_softirq.end()) // 找到了
            {
                struct SoftIrq old = iter->second;
                double period = Utils::SteadyTimeSecond(info.time_point, old.time_point);    // 计算间隔
                monitor::proto::CpuSoftirqs *one_softirq_msg = monitor_info->add_soft_irq(); // 添加新的软中断消息
                one_softirq_msg->set_cpu(info.cpu_name);
                one_softirq_msg->set_hi(info.hi);
                one_softirq_msg->set_net_tx(info.net_tx);
                one_softirq_msg->set_net_rx(info.net_rx);
                one_softirq_msg->set_block(info.block);
                one_softirq_msg->set_irq_poll(info.irq_poll);
                one_softirq_msg->set_tasklet(info.tasklet);
                one_softirq_msg->set_sched(info.sched);
                one_softirq_msg->set_hrtimer(info.hrtimer);
                one_softirq_msg->set_rcu(info.rcu);
            }
            _cpu_softirq[name] = info; //// 将当前软中断信息存储到cpu_softirqs_映射中
        }
        return;
    }
}
