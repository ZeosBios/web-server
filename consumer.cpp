#include "consumer.h"

#include <iostream>
#include <thread>

consumer::consumer(std::shared_ptr<buffer> buff)
    : m_buff(buff)
{
}

consumer::~consumer() = default;

char * consumer::run()
{
    while (true)
    {
        char * msg = m_buff->remove();
        g_cout_mu.lock();
        std::cout << "Consumed: " << msg << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        g_cout_mu.unlock();
        return msg;
    }
}
