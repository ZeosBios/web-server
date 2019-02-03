#include "buffer.h"

buffer::buffer()
{}

buffer::~buffer() = default;

void buffer::add(char * msg)
{
    while (true)
    {
        std::lock_guard<std::mutex> locker(m_mu);
        m_buffer.push_back(msg);
        return;
    }
}

char * buffer::remove()
{
    while (true)
    {
        std::lock_guard<std::mutex> locker(m_mu);
        char * back = m_buffer.back();
        m_buffer.pop_back();
        return back;
    }
}
