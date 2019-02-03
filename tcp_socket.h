#ifndef TCPSOCKET_H
#define TCPSOCKET_H

#include <netdb.h>
#include <string.h>

class tcp_socket
{
public:
    tcp_socket();
    virtual ~tcp_socket();

    void bind(const char * adress, int port);
    void connect(const char * adress, int port);
    void listen(int maxQueue);
    int  accept();
    int send(const char * data, unsigned int length, int flags);
    int receive(char * data, unsigned int length, int flags);
    void openSocket();
    void close();
    void setSocket(int socket);

private:
    struct sockaddr_in * m_Info;
    int m_socketdf;

};
#endif
