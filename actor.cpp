#include "actor.h"
#include <string.h>

actor::actor(int sockdf)
    : actorbase(sockdf)
    , m_th(&actor::exec, this)
{
}

actor::~actor()
{
    if (!halt_flag)
        halt();
}

void actor::halt()
{
    to_halt();
    m_th.join();
}

void actor::exec()
{
    while (!halt_flag)
    {
        receive();
        std::this_thread::sleep_for(std::chrono::nanoseconds(1));
    }
}
