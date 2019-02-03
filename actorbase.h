#ifndef ACTORBASE_H
#define ACTORBASE_H

#include <mutex>
#include <queue>
#include <atomic>
#include <string.h>

class actorbase
{
public:
    actorbase(int sockdf);

    virtual ~actorbase();

    void entry(char * msg);

    void receive();

protected:
	std::atomic_bool halt_flag;

    void to_halt();

    int m_sockdf;

private:
    std::mutex m_mtx;
    std::queue<char *> m_message_queue;

    virtual void process_message(char * msg) = 0;
};
#endif
