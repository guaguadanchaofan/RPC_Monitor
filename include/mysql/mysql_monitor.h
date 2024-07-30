#include "mysql_util.h"
#include<mutex>
#include<assert.h>
#include "monitor.h"
#include"monitor_info.pb.h"
class mysql_monitor
{
public:
    mysql_monitor(const std::string &host,
                  const std::string &username,
                  const std::string &password,
                  const std::string &dbname,
                  uint16_t port = 3306)
    {
        mysql_ =  mysql_util::mysql_create(host,username,password,dbname,port);
        assert(mysql_ != nullptr);
    }
    ~mysql_monitor()
    {
        mysql_util::mysql_destroy(mysql_);
        mysql_ == nullptr;
    }
    bool insert(monitor::proto::MonitorInfo* info)
    {
#define INSERT_CPULOAD "insert cpu_load values('%s',now(),%f,%f,%f);"
        std::string name = info->name();
        auto cpu_load = info->cpu_load();
        float lavg_1 = cpu_load.lavg_1();
        float lavg_3 = cpu_load.lavg_3();
        float lavg_15 = cpu_load.lavg_15();
        char sql[4096] = {0};
        sprintf(sql,INSERT_CPULOAD,name.c_str(),lavg_1,lavg_3,lavg_15);
        bool ret = mysql_util::mysql_exec(mysql_,sql);
        if(ret == false)
        {
            printf("insert info failed!!\n");
            return false;
        }
        std::cout<<"============================================"<<std::endl;
        return true;
    }

private:
    MYSQL *mysql_;  //操作句柄
    std::mutex mutex_;  //保护数据库访问
};
