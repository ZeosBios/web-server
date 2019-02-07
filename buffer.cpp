#include "buffer.h"

buffer::buffer()
{}

buffer::~buffer() = default;

void buffer::add(char * msg)
{
    while (true)
    {
        std::unique_lock<std::mutex> locker(m_mu);
        m_cond.wait(locker, [this](){return m_buffer.size() < m_size;});
        m_buffer.push_back(msg);
        locker.unlock();
        m_cond.notify_all();
        return;
    }
}

char * buffer::remove()
{
    while (true)
    {
        std::unique_lock<std::mutex> locker(m_mu);
        m_cond.wait(locker, [this](){return m_buffer.size() > 0;});
        char * back = m_buffer.back();
        m_buffer.pop_back();
        locker.unlock();
        m_cond.notify_all();
        return back;
    }
}
