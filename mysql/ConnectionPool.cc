#include "ConnectionPool.h"
#include <jsoncpp/json/json.h>
#include <fstream>
#include <thread>

ConnectionPool *ConnectionPool::getConnectPool()
{
    static ConnectionPool pool;
    return &pool;
}

std::shared_ptr<databaseConnect> ConnectionPool::getConnection()
{
    std::unique_lock<std::mutex> lock(_mutexQ);
    while(_connectQ.empty())
    {
        //如果阻塞到了超时时间
        if(std::cv_status::timeout == _cond.wait_for(lock , std::chrono::milliseconds(_timeout)))
        {
            if(_connectQ.empty()) //如果还是为空
            {
                //return nullptr;
                continue;
            }
        }
    }
    //第二个参数可以用匿名函数指定删除器
    std::shared_ptr<databaseConnect> conn(_connectQ.front(),[this](databaseConnect* conn){
        std::lock_guard<std::mutex> locker(_mutexQ);
        conn->refreshAliveTime();//更新连接时间
        _connectQ.push(conn);
    });//拿到连接
    _connectQ.pop();                          //弹出连接
    _cond.notify_all();
    return conn;
}

ConnectionPool::~ConnectionPool()
{
    if(!_connectQ.empty())
    {

        auto tmp = _connectQ.front();
        _connectQ.pop();
        delete tmp;
    }
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
        _user = root["userName"].asString();
        _passwd = root["password"].asString();
        _dbName = root["dbName"].asString();
        _minSize = root["minSize"].asInt();
        _maxSize = root["maxSize"].asInt();
        _maxIdTime = root["maxIdleTime"].asInt();
        _timeout = root["timeout"].asInt();
        return true;
    }
    else
    {
        return false;
    }
}
void ConnectionPool::produceConnection() // 生产数据库连接
{
    while (true)
    {
        std::unique_lock<std::mutex> lock(_mutexQ);
        while (_connectQ.size() >= _minSize) // 连接够用
        {
            _cond.wait(lock); // 线程阻塞等待
        }
        addConnection(); // 生产新的连接
        _cond.notify_all();
    }
}
void ConnectionPool::recycleConnection() // 检测是否需要销毁
{
    while (true)
    {
        // 线程休眠3秒
        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        std::lock_guard<std::mutex> locker(_mutexQ);
        while (_connectQ.size() > _minSize)
        {
            databaseConnect *conn = _connectQ.front();
            if (conn->getAliveTime() >= _maxIdTime) // 判断连接存在时间
            {
                _connectQ.pop(); // 删除连接
                delete conn;     // 释放空间
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
    databaseConnect *conn = new databaseConnect;        // 创建连接对象
    //std::cout<<_user << " "<<_passwd << " "<< _ip << " " << _port << std::endl;
    conn->connect(_user, _passwd, _dbName, _ip, _port); // 调用连接函数
    conn->refreshAliveTime(); //记录对应时间戳
    _connectQ.push(conn); // 往队列里面push连接数据
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
    std::thread producer(&ConnectionPool::produceConnection,this); // 生产连接池的线程
    std::thread recycler(&ConnectionPool::recycleConnection,this); // 检测销毁的线程
    producer.detach();                                        // 线程分离  防止阻塞主线程
    recycler.detach();
}