#pragma once
#include "monitor.h"
#include <unordered_map>
#include "monitor_info.pb.h"
#include <boost/chrono.hpp>
namespace monitor
{
    class NetMonitor : public MonitorInter
    {
    public:
        struct NetInfo
        {
            std::string name;                                  // 网络接口的名称
            int64_t rcv_bytes;                                 // 接收的字节数
            int64_t rcv_packets;                               // 接收的数据包数
            int64_t err_in;                                    // 接收时的错误数
            int64_t drop_in;                                   // 接收时的丢包数
            int64_t snd_bytes;                                 // 发送的字节数
            int64_t snd_packets;                               // 发送的数据包数
            int64_t err_out;                                   // 发送时的错误数
            int64_t drop_out;                                  // 发送时的丢包数
            boost::chrono::steady_clock::time_point timepoint; // 时间点，用于记录时间
        };
        NetMonitor() {}
        void UpdataOnce(monitor::proto::MonitorInfo *monitor_info);
        void Stop() override {}

    private:
        std::unordered_map<std::string, struct NetInfo> _net_info;
    };
}