#include "mysqlconn.h"
#include <string>
#include <chrono>
databaseConnect::databaseConnect()
{
    // mysql 环境初始化
    _conn = mysql_init(nullptr);
    // mysql 字符集设置 utf8
    mysql_set_character_set(_conn, "utf8");
}

databaseConnect::~databaseConnect()
{
    // mysql 环境关闭
    if (_conn != nullptr)
    {
        mysql_close(_conn);
    }
    freeResult();
}

bool databaseConnect::connect(std::string user, std::string passwd, std::string dbName, std::string ip, unsigned short port)
{
    MYSQL *ptr = mysql_real_connect(_conn, ip.c_str(), user.c_str(), passwd.c_str(), dbName.c_str(), port, nullptr, 0);
    if(ptr == nullptr)
    {
        std::cout<<"数据库连接失败---------"<<std::endl;
    }
    return ptr != nullptr;
}

bool databaseConnect::update(std::string sql)
{
    if (mysql_query(_conn, sql.c_str()))
        return false;
    return true;
}

bool databaseConnect::query(std::string sql)
{
    freeResult(); // 保存结果时，清空上一次的结果
    if (mysql_query(_conn, sql.c_str()))
        return false;
    _result = mysql_store_result(_conn);
    return true;
}

bool databaseConnect::next()
{
    if (_result != nullptr)
    {
        _row = mysql_fetch_row(_result);
        if (_row != nullptr)
            return true;
    }
    return false;
}

std::string databaseConnect::value(int index)
{
    int listCount = mysql_num_fields(_result);
    if (index >= listCount || index < 0)
        return std::string();
    char *val = _row[index];                                    // 返回值为char* 有'\0'
    unsigned long length = mysql_fetch_lengths(_result)[index]; // 取出第index列的属性长度
    return std::string(val, length);                            // 去除'\0'
}

bool databaseConnect::transaction()
{
    return mysql_autocommit(_conn, false);
}

bool databaseConnect::commit()
{
    return mysql_commit(_conn);
}

bool databaseConnect::rollback()
{
    return mysql_rollback(_conn);
}

void databaseConnect::freeResult()
{
    if (_result)
    {
        mysql_free_result(_result);
        _result = nullptr;
    }
}

void databaseConnect::refreshAliveTime()
{
    _alivetime = std::chrono::steady_clock::now();
}

long long databaseConnect::getAliveTime()
{
    std::chrono::nanoseconds res = std::chrono::steady_clock::now() - _alivetime;
    std::chrono::milliseconds millisec = std::chrono::duration_cast<std::chrono::milliseconds>(res);
    return millisec.count();
}