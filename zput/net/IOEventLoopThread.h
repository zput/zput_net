#ifndef ZPUT_IOEVENTLOOPTHREAD
#define ZPUT_IOEVENTLOOPTHREAD

#include <base/Thread.h>
#include <condition_variable>
#include <net/IOEventLoop.h>


namespace zput
{

namespace net
{
class IOEventLoopThread : public base::Thread
{
public :
    IOEventLoopThread();
    virtual void run();
    IOEventLoop* getLoopInThread();
private:
    IOEventLoop* loop;
    std::mutex mutex;
    std::condition_variable condtion;
};

}

}

#endif // ZPUT_IOEVENTLOOPTHREAD
