#include "ConnectionPool.h"
#include <jsoncpp/json/json.h>
#include <fstream>
#include <thread>

ConnectionPool *ConnectionPool::getConnectPool()
{
    static ConnectionPool poll;
    return &poll;
}

bool ConnectionPool::parseJsonFile()
{
    std::ifstream ifs("dbconf.json");
    Json::Reader rd;
    Json::Value root;
    rd.parse(ifs, root);
    if (root.isObject())
    {
        _ip = root["ip"].asString();
        _port = root["port"].asInt();
        _user = root["user"].asString();
        _passwd = root["passwd"].asString();
        _dbName = root["dbName"].asString();
        _minSize = root["minSize"].asInt();
        _maxSize = root["maxSize"].asInt();
        _maxIdTime = root["maxIdTime"].asInt();
        _timeout = root["timeout"].asInt();
        return true;
    }
    else
    {
        return false;
    }
}
void ConnectionPool::produceConnection()
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(_mutexQ);
        while (_connectQ.size() >= _minSize)
        {
            _cond.wait(lock);
        }
        addConnection();
    }
}
void ConnectionPool::recycleConnection()
{
    while(true)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        while(_connectQ.size() > _minSize)
        {
            databaseConnect* conn = _connectQ.front();
            if( conn->getAliveTime() >= _maxIdTime)
            {
                _connectQ.pop();
                delete conn;
            }
            else
            {
                break;
            }       
        }
    }
}
void ConnectionPool::addConnection()
{
    databaseConnect *conn = new databaseConnect;
    conn->connect(_user, _passwd, _dbName, _ip, _port);
    conn->refreshAliveTime();
    _connectQ.push(conn);
}
ConnectionPool::ConnectionPool()
{
    if (!parseJsonFile())
    {
        return;
    }
    for (int i = 0; i < _minSize; ++i)
    {
        addConnection();
    }
    std::thread producer(&ConnectionPool::produceConnection);
    std::thread recycler(&ConnectionPool::recycleConnection);
    producer.detach();
    recycler.detach();
}