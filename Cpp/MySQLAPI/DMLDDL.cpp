#include <iostream>
#include <mysql/jdbc.h>

// 执行表库的增删改语句

int main()
{
    try
    {
        sql::Driver *driver = nullptr;
        sql::Connection *connect = nullptr;

        driver = sql::mysql::get_driver_instance();
        connect = driver->connect("tcp://Host:Port/Database", "Username", "Password");

        std::cout << state->executeUpdate("SQL") << std::endl;

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
