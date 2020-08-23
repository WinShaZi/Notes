#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <memory>
#include <new>

using namespace std;

struct destination
{
    destination(const string& ip, const string& port) : m_ip(ip), m_port(port) {}
    string m_ip, m_port;
};
struct connection
{
    connection(string& ip, string& port) : m_ip(ip), m_port(port) {}
    string m_ip, m_port;
};

connection connect(destination* pdes)
{
    shared_ptr<connection> spConn (new connection(pdes->m_ip, pdes->m_port));
    cout << "create a connection " << spConn.use_count() << " to " << pdes->m_ip << " : " << pdes->m_port << endl;
    return *spConn;
}

void disconnection(connection pConn)
{
    cout << "close the connection " << pConn.m_ip << " : " << pConn.m_port << endl;
}

void end_connection(connection* p)
{
    disconnection(*p);
}

void f(destination* d)
{
    connection c = connect(d);
    shared_ptr<connection> p (&c, end_connection);
}


int main()
{	
	destination d ("192.21.4.110", "8088");
    f(&d);
	
	system("pause");
	return 0;
}