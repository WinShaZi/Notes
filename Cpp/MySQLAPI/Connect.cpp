#include <iostream>
#include <mysql/jdbc.h>

int main()
{
    try
    {
        sql::Driver *driver = nullptr;
        sql::Connection *connect = nullptr;

        driver = sql::mysql::get_driver_instance();
        // 第一种连接方式
        connect = driver->connect("tcp://Host:Port/Database", "Username", "Password");

        // 第二种连接方式
        // connect = driver->connect("tcp://Host:Port", "Username", "Password");
        // connect->setSchema("Database");

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