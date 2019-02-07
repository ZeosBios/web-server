#include "producer.h"

#include <iostream>
#include <thread>

producer::producer(std::shared_ptr<buffer> buff)
    : m_buff(buff)
{}

producer::~producer() = default;

void producer::run(char * msg)
{
    while (true)
    {
        m_buff->add(msg);
        std::lock_guard<std::mutex> lock(g_cout_mu);
        std::cout << "Produced: " << msg << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}
