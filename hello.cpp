#include <iostream>
#include <mysql.h>
using namespace std;
int main()
{
    MYSQL mysql;
    MYSQL_RES *res;
    MYSQL_ROW row;

    mysql_init(&mysql);

    mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");

    if (mysql_real_connect(&mysql, "192.168.172.128", "liao", "962464", "database_test", 3306, NULL, 0) == 0)
    {
        cout << "����ԭ��:" << mysql_error(&mysql) << endl;
        ;
        cout << "����ʧ��" << endl;
        exit(-1);
    }

    int ret = mysql_query(&mysql, "INSERT INTO Student values(4," liruoyan ",2);");
    cout << "ret:" << ret << endl;

    res = mysql_store_result(&mysql);

    while (row = mysql_fetch_row(res))
    {
        cout << row[0] << "\t" << row[1] << "\t" << row[2] << "\t" << endl;
    }

    mysql_free_result(res);
}