#pragma once
#include "monitor.h"
#include "monitor_info.pb.h"
namespace monitor
{
    class MemMonitor : public MonitorInter
    {
    public:
        struct MenInfo
        {
            int64_t total;
            int64_t free;
            int64_t avail;
            int64_t buffers;
            int64_t cached;
            int64_t swap_cached;
            int64_t active;
            int64_t in_active;
            int64_t active_anon;
            int64_t inactive_anon;
            int64_t active_file;
            int64_t inactive_file;
            int64_t dirty;
            int64_t writeback;
            int64_t anon_pages;
            int64_t mapped;
            int64_t kReclaimable; // 可回收内存大小
            int64_t sReclaimable; // 可回收slab内存大小
            int64_t sUnreclaim;   // 不可回收slab内存大小
        };
        MemMonitor(){}
        void UpdataOnce(monitor::proto::MonitorInfo* monitor_info);
        void Stop() override {}
    };
}