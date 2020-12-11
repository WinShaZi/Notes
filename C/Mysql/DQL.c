#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

int main(int argc, char const *argv[])
{
    MYSQL *db = NULL;          // mysql连接对象
    MYSQL_RES *result = NULL;  // 查询返回结果集
    MYSQL_ROW row = NULL;      // 查询返回的一行结果
    MYSQL_FIELD *field = NULL; // 字段名
    int num_fields = 0;        // 查询返回字段数量
    int num_rows = 0;          // 查询返回行数

    db = mysql_init(NULL);
    if (db == NULL)
    {
        printf("Error %u: %s\n", mysql_errno(db), mysql_error(db));
        exit(1);
    }
    if (mysql_real_connect(db, "localhost", "root", "asdf", "testdb", 3306, NULL, 0) == NULL)
    {
        printf("Error %u: %s\n", mysql_errno(db), mysql_error(db));
        exit(1);
    }
    if (mysql_query(db, "SELECT * FROM temp"))
    {
        printf("Error %u: %s\n", mysql_errno(db), mysql_error(db));
        exit(1);
    }

    // 获取查询结果
    result = mysql_store_result(db);
    // 按行获取查询结果
    num_rows = mysql_num_rows(result);
    // 获取字段数量
    num_fields = mysql_num_fields(result);

    printf("%d row %d column\n", num_rows, num_fields);
    while ((row = mysql_fetch_row(result)))
    {
        for (int i = 0; i < num_fields; i++)
        {
            if (i == 0)
            {
                // 获取字段名
                while (field = mysql_fetch_field(result))
                {
                    printf("%s ", field->name);
                }
                printf("\n");
            }
            printf("%s ", row[i] ? row[i] : "NULL");
        }
    }
    mysql_free_result(result);

    mysql_close(db);

    return 0;
}
