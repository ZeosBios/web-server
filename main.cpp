#include "manager.h"


int main()
{
    char html[] = "HTTP/1.1 200 OK\r\n"
    "Connection: close\r\n"
    "Content-type: text/html\r\n"
    "\r\n"
    "<html>\r\n"
    "<head>\r\n"
    "<title>Hello, world!</title>\r\n"
    "<h1>I'm web-server on C++!</h1>\r\n"
    "</head>\r\n"
    "<body>\r\n"
    "<h1>Hello, world!</h1>\r\n"
    "</body>\r\n"
    "</html>\r\n\r\n";

    manager mngr;
    mngr.entry(html);
    mngr.receive();


   return 0;
}
