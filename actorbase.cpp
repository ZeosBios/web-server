#include "actorbase.h"
#include <string.h>

actorbase::actorbase(int sockdf)
    : halt_flag(false)
    , m_message_queue()
    , m_sockdf(sockdf)
{}

actorbase::~actorbase() = default;

void actorbase::entry(char * msg)
{
    std::lock_guard<std::mutex> lock(m_mtx);
    if (halt_flag) return;
    m_message_queue.push(msg);
}

void actorbase::receive()
{
    char * msg;
    {
        std::lock_guard<std::mutex> lock(m_mtx);

        if (halt_flag)
            return;
        if (m_message_queue.empty())
            return;

        msg = m_message_queue.front();
        m_message_queue.pop();
    }

    process_message(msg);
}

void actorbase::to_halt()
{
    std::lock_guard<std::mutex> lock(m_mtx);
    halt_flag = true;
}
