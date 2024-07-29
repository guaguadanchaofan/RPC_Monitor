#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <mysql/mysql.h>
#include <iostream>

#define HOST "localhost"
#define USER "root"
#define PASSWD "VEVE5217.."
#define DBHAME "test_db"
class mysql_util
{
public:
    static MYSQL *mysql_create(const std::string &host,
                               const std::string &user,
                               const std::string &pass,
                               const std::string &name,
                               u_int16_t port)
    {
        MYSQL *mysql = mysql_init(nullptr);
        if (mysql == nullptr)
        {
            std::cout << "Init mysql instance failed!" << std::endl;
            return nullptr;
        }
        if (mysql_real_connect(mysql,
                               host.c_str(),
                               user.c_str(),
                               pass.c_str(),
                               name.c_str(),
                               port, nullptr, 0)==nullptr)
        {
            std::cout << "mysql_real_connect  failed!" << std::endl;
            std::cout<<mysql_error(mysql);
            return nullptr;
        }
        mysql_set_character_set(mysql,"utf8");
        return mysql;
    }
    static void mysql_destroy(MYSQL* mysql)
    {
        if(mysql != nullptr)
        {
            mysql_close(mysql);
        }
        return;
    }
    static bool mysql_exec(MYSQL* mysql, const std::string &sql)
    {
        int ret = mysql_query(mysql,sql.c_str());
        if(ret!= 0)
        {
            std::cout<<sql<<std::endl;
            std::cout<<mysql_error(mysql)<<std::endl;
            return false;
        }
        return true;
    }
};
