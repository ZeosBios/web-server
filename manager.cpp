#include "manager.h"

manager::manager()
    : m_buff(std::make_shared<buffer>())
    , m_prod(std::make_shared<producer>(m_buff))
    , m_cons(std::make_shared<consumer>(m_buff))
    , m_sock(std::make_shared<tcp_socket>())
{
    m_sock->openSocket();
}

manager::~manager() = default;

void manager::entry(char * msg)
{
    m_prod->run(msg);
}

void manager::receive()
{
    char * msg = m_cons->run();

    m_sock->bind("127.0.0.1", 12345);
    m_sock->listen(5);

    int newSock;
    while(newSock = m_sock->accept())
    {
        m_actr = std::make_shared<EchoActor>(newSock);
        m_actr->entry(msg);
    }
    m_actr->halt();

}

