#include <iostream>
#include <mysql/jdbc.h>

int main()
{
    try
    {
        sql::Driver *driver = nullptr;
        sql::Connection *connect = nullptr;
        sql::Statement *state = nullptr;
        sql::ResultSet *result = nullptr;

        driver = sql::mysql::get_driver_instance();
        connect = driver->connect("tcp://localhost:3306/testdb", "root", "asdf");

        state = connect->createStatement();

        if (state->execute("SELECT VERSION()")) // 执行有结果返回的语句返回true，其他为false
        {
            result = state->getResultSet();

            while (result->next())
            {
                std::cout << result->getInt(1) << std::endl;
            }
        }

        state->close();
        connect->close();

        delete state;
        delete result;
        delete connect;
        delete driver;
    }
    catch (sql::SQLException &e)
    {
        std::cout << "# CODE  : [" << e.getErrorCode() << "]" << std::endl;
        std::cout << "# STATE : [" << e.getSQLStateCStr() << "]" << std::endl;
        std::cout << "# ERR   : [" << e.what() << "]" << std::endl;
    }

    return 0;
}
