#include "net_monitor.h"
#include "read_file.h"
#include"utils.h"
namespace monitor
{
    void NetMonitor::UpdataOnce(monitor::proto::MonitorInfo *monitor_info)
    {
        ReadFile net_file(std::string("/proc/net/dev"));
        std::vector<std::string> net_data;
        while (net_file.ReadLine(&net_data))
        {
            std::string name = net_data[0];
            if (name.find(':') == name.size() - 1 && net_data.size() >= 10)
            {
                struct NetInfo net_info;
                name.pop_back();
                net_info.name = name;
                net_info.rcv_bytes = std::stoll(net_data[1]);
                net_info.rcv_packets = std::stoll(net_data[2]);
                net_info.err_in = std::stoll(net_data[3]);
                net_info.drop_in = std::stoll(net_data[4]);
                net_info.snd_bytes = std::stoll(net_data[9]);
                net_info.snd_packets = std::stoll(net_data[10]);
                net_info.err_out = std::stoll(net_data[11]);
                net_info.drop_out = std::stoll(net_data[12]);
                net_info.timepoint = boost::chrono::steady_clock::now();
                auto iter = _net_info.find(name);
                if (iter != _net_info.end())
                {
                    struct NetInfo old = iter->second;
                    double period =
                        Utils::SteadyTimeSecond(net_info.timepoint, old.timepoint);
                    auto one_net_msg = monitor_info->add_net_info();
                    one_net_msg->set_name(net_info.name);
                    one_net_msg->set_send_rate((net_info.snd_bytes - old.snd_bytes) /
                                               1024.0 / period);
                    one_net_msg->set_recv_rate((net_info.rcv_bytes - old.rcv_bytes) /
                                              1024.0 / period);
                    one_net_msg->set_send_packets_rate(
                        (net_info.snd_packets - old.snd_packets) / period);
                    one_net_msg->set_recv_packets_rate(
                        (net_info.rcv_packets - old.rcv_packets) / period);
                }
                _net_info[name] = net_info;
            }
            net_data.clear();
        }
        return;
    }
}