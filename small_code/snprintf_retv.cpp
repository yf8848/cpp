#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>

using namespace std;
const int MAX_SQL_LEN=20;

void ret_value()
{
    string table = "order.statement";
    string where = "where 1=1 limit 1";

    char szSql[MAX_SQL_LEN];
    int rv = snprintf(szSql, sizeof(szSql), "SELECT * FROM %s %s;", 
                table.c_str(), where.c_str());

    printf("snprintf value: %s\n",szSql);
    printf("length:[%d-%d]\n",rv, (int)strlen(szSql));

}

int main()
{
    ret_value();

    return 0;
}