#ifndef ACTOR_H
#define ACTOR_H

#include "actorbase.h"

#include <thread>
#include <chrono>
#include <string.h>

class actor : public actorbase
{
public:
    actor(int sockdf);
    virtual ~actor();

    void halt();

protected:
    std::thread m_th;

private:
    void exec();
};
#endif // ACTOR_H*
