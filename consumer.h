#ifndef CONSUMER_H
#define CONSUMER_H

#include "buffer.h"

class consumer
{
public:
    consumer(std::shared_ptr<buffer> buff);
    virtual ~consumer();
    char * run();

private:
    std::shared_ptr<buffer> m_buff;
};

#endif // CONSUMER_H
