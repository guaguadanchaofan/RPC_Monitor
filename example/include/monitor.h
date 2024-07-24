#pragma once
#include"monitor_info.pb.h"


namespace monitor
{
    class MonitorInter
    {
    public:
        MonitorInter(){}
        virtual ~MonitorInter(){}
        virtual void UpdataOnce(monitor::proto::MonitorInfo* monitor_info)=0; 
        virtual void Stop()=0;
    };
}