#pragma once
#include <unordered_map>
#include <string>

// rpcserverip rpserverport zookeeperip zookeeperport
// 框架读取配置文件类
class MprpcConfig
{
public:
    // 负责解析加载配置文件
    void LoadConfigFile(const char *confif_file);
    // 查询配置项信息
    std::string Load(std::string key);
    // 去掉字符串空格
    void Trim(std::string &key);

private:
    std::unordered_map<std::string, std::string> _configMap;
};