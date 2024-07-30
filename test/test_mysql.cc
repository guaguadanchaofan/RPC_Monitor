#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <mysql/mysql.h>

#define HOST "localhost"
#define USER "root"
#define PASSWD "VEVE5217.."
#define DBHAME "test_db"
void add(MYSQL *mysql)
{
    char *sql = (char*)"insert into stu values(null,18,'张三'),(null,17,'李四');";
    int ret = mysql_query(mysql, sql);
    if (ret != 0)
    {
        printf("mysql query error:%s\n", mysql_error(mysql));
        return;
    }
    return;
}
void del(MYSQL *mysql)
{
    char *sql = (char*)"delete from stu where name='张三';";
    int ret = mysql_query(mysql, sql);
    if (ret != 0)
    {
        printf("mysql query error:%s\n", mysql_error(mysql));
        return;
    }
    return;
}
void mod(MYSQL *mysql)
{
    char *sql = (char*)"update stu set age=15 where name='张三';";
    int ret = mysql_query(mysql, sql);
    if (ret != 0)
    {
        printf("mysql query error:%s\n", mysql_error(mysql));
        return;
    }
    return;
}
void get(MYSQL *mysql)
{
    char *sql = (char*)"select * from stu;";
    int ret = mysql_query(mysql, sql);
    if (ret != 0)
    {
        printf("mysql query error:%s\n", mysql_error(mysql));
        return;
    }
    MYSQL_RES *res = mysql_store_result(mysql);
    if (res == NULL)
    {
        printf("mysql store result error:%s\n", mysql_error(mysql));
        return;
    }
    int row = mysql_num_rows(res);
    int col = mysql_num_fields(res);
    printf("%10s%10s%10s\n", "ID", "年龄", "姓名");
    for (int i = 0; i < row; i++)
    {
        MYSQL_ROW row_data = mysql_fetch_row(res);
        for (int i = 0; i < col; i++)
        {
            printf("%10s", row_data[i]);
        }
        printf("\n");
    }
    mysql_free_result(res);
    return;
}
int main()
{
    MYSQL *mysql = mysql_init(NULL);
    if (mysql == NULL)
    {
        printf("init mysql handle failed!\n");
        return -1;
    }
    if (mysql_real_connect(mysql, HOST, USER, PASSWD, DBHAME, 3306, NULL, 0) == NULL)
    {
        printf("mysql connect error\n");
        return -1;
    }
    mysql_set_character_set(mysql, "utf8");
    printf("===================== add =========================\n");
    add(mysql);
    get(mysql);
    printf("===================== mod =========================\n");
    mod(mysql);
    get(mysql);
    printf("===================== del =========================\n");
    del(mysql);
    get(mysql);
    mysql_close(mysql);
    return 0;
}