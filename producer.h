#ifndef PRODUCER_H
#define PRODUCER_H

#include "buffer.h"

class producer
{
public:
    producer(std::shared_ptr<buffer> buff);
    virtual ~producer();
    void run(char * msg);

private:
    std::shared_ptr<buffer> m_buff;
};

#endif // PRODUCER_H
