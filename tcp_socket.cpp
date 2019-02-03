#include "tcp_socket.h"

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>

#include <iostream>

void DEBUG(std::string message)
{
    std::cout << "DEBUG : " << message << std::endl;
}

tcp_socket::tcp_socket()
{
    m_Info = new sockaddr_in;
    memset(m_Info, 0, sizeof(m_Info));
    m_Info->sin_family = AF_INET;
    DEBUG("Create...");
}

tcp_socket::~tcp_socket()
{
}

void tcp_socket::bind(const char * adress, int port)
{
    //struct hostent * he;
   // he = gethostbyname(adress);

   m_Info->sin_port = htons(port);
   inet_pton(m_Info->sin_family, adress, &m_Info->sin_addr);

   //m_Info->sin_addr.s_addr = inet_addr(adress);
   if(::bind(m_socketdf, (struct sockaddr *)m_Info, sizeof(sockaddr_in)) < 0)
    {
         perror("bind");
         return;
    }
    DEBUG("Binding...");
}

void tcp_socket::connect(const char * adress, int port)
{
    //struct hostent * he;
   // he = gethostbyname(adress);

    m_Info->sin_port = htons(port);
    inet_pton(m_Info->sin_family, adress, &(m_Info->sin_addr));

    if(::connect(m_socketdf, (struct sockaddr *)m_Info, sizeof(struct sockaddr_in)) < 0)
    {
         perror("connect");
         return;
    }
    DEBUG("Connecting...");
}

void tcp_socket::listen(int maxQueue)
{
    if( ::listen(m_socketdf, maxQueue) != 0)
    {
        perror("listen");
        return;
    }
    DEBUG("Listening...");
}

int tcp_socket::accept()
{
    DEBUG("Starting to accept");
    int newSock;
    socklen_t size = sizeof(struct sockaddr_in);
    if( (newSock = ::accept(m_socketdf, (struct sockaddr *)m_Info, &size)) < 0)
    {
        perror("accept");
    }
    DEBUG("1 client Accepted...");
    return newSock;
}

int tcp_socket::send(const char * data, unsigned int length, int flags)
{
    int total = 0;
    int n;

    while(total < length)
    {
        n = ::send(m_socketdf, data, length-total, flags);
        if(n < 0)
        {
            perror("send");
        }
        total += n;
    }

    DEBUG("Sending...");
    return (n==-1 ? -1 : total);
}

int tcp_socket::receive(char * data, unsigned int length, int flags)
{
    int total = 0;
    int n;

    while(total < length)
    {
        n = ::recv(m_socketdf, data, length-total, flags);
        if(n < 0)
        {
          perror("send");
        }
        total += n;
    }
    DEBUG("Receining...");

    return (n==-1 ? -1 : total);
}

void tcp_socket::close()
{
    if(::close(m_socketdf) < 0)
    {
        perror("close");
    }
    DEBUG("Closed....");
}

void tcp_socket::openSocket()
{
    m_socketdf = ::socket(m_Info->sin_family, SOCK_STREAM, 0);
    if(m_socketdf < 0)
    {
        perror("open");
    }
    DEBUG("Opening...");
}

void tcp_socket::setSocket(int socket)
{
    m_socketdf = socket;
}
