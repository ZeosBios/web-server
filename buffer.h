#ifndef BUFFER_H
#define BUFFER_H

#include <deque>
#include <mutex>
#include <chrono>
#include <condition_variable>

static std::mutex g_cout_mu;


class buffer
{
public:
    buffer();
    virtual ~buffer();

    void add(char * msg);
    char * remove();

private:
    std::mutex m_mu;
    std::condition_variable_any m_cond;

    std::deque<char *> m_buffer;
    const unsigned int m_size = 10;
};

#endif // BUFFER_H
