#include <iostream>
#include <mysql/jdbc.h>

// 执行查询的语句

int main()
{
    try
    {
        sql::Driver *driver = nullptr;
        sql::Connection *connect = nullptr;

        driver = sql::mysql::get_driver_instance();
        connect = driver->connect("tcp://Host:Port/Database", "Username", "Password");

        result = state->executeQuery("SQL");
        while (result->next())
        {
            std::cout << result->getInt(1) << std::endl;
        }

        connect->close();
        delete connect;
    }
    catch (sql::SQLException &e)
    {
        std::cout << "# CODE  : [" << e.getErrorCode() << "]" << std::endl;
        std::cout << "# STATE : [" << e.getSQLStateCStr() << "]" << std::endl;
        std::cout << "# ERR   : [" << e.what() << "]" << std::endl;
    }

    return 0;
}
