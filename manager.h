#ifndef MANAGER_H
#define MANAGER_H

#include <memory>
#include "producer.h"
#include "consumer.h"
#include "actor.h"
#include "tcp_socket.h"

struct EchoActor : public actor
{
    EchoActor(int sockdf)
        :actor(sockdf)
    {}

    void process_message(char * msg)
    {
        std::shared_ptr<tcp_socket> client = std::make_shared<tcp_socket>();
        client->setSocket(m_sockdf);

        client->send(msg, strlen(msg), 0);

        int sizeBuff = 512;
        char buff[sizeBuff];
        memset(&buff, 0, sizeBuff);
        while(client->receive(buff, sizeBuff, 0))
        {
            client->send(buff, sizeof(buff), 0);
            memset(&buff, 0, sizeBuff);
        }

        client->close();
    }
};


class manager
{
public:
    manager();
    ~manager();

    void entry(char * msg);
    void receive();

private:
    std::shared_ptr<buffer>     m_buff{nullptr};
    std::shared_ptr<producer>   m_prod{nullptr};
    std::shared_ptr<consumer>   m_cons{nullptr};
    std::shared_ptr<EchoActor>  m_actr{nullptr};
    std::shared_ptr<tcp_socket> m_sock{nullptr};
};

#endif // MANAGER_H
