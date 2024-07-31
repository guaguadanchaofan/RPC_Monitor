#pragma once
#include <queue>
#include "mysqlconn.h"
#include <string>
#include <mutex>
#include <queue>
#include <condition_variable>

class ConnectionPool
{
public:
  static ConnectionPool *getConnectPool();
  ConnectionPool(const ConnectionPool &) = delete;
  ConnectionPool &operator=(const ConnectionPool &) = delete;
  std::shared_ptr<databaseConnect> getConnection();
  ~ConnectionPool();

private:
  ConnectionPool(); // 懒汉模式——用到时创建
  bool parseJsonFile();
  void produceConnection();
  void recycleConnection();
  void addConnection();

private:
  std::string _ip;
  std::string _user;
  std::string _passwd;
  std::string _dbName;
  uint16_t _port;

  // 连接池中，可连接数范围
  int _minSize;
  int _maxSize;
  // 超时时间
  int _timeout;
  int _maxIdTime;

  std::queue<databaseConnect *> _connectQ; // 队列存放数据库连接
  std::mutex _mutexQ;                      // 操作连接池锁住
  std::condition_variable _cond;           // 生产者消费者，控制连接池连接个数
};