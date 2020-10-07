#ifndef ZPUT_NET_TIMER_QUEUE
#define ZPUT_NET_TIMER_QUEUE

#include <map>

#include <memory>
#include <functional>
#include <net/IOEvent.h>
#include <net/Timer.h>

#include <mutex>

namespace zput
{

namespace net
{
class IOEventLoop;

class TimerQueue
{
public:
    TimerQueue(IOEventLoop* eventLoop);
    ~TimerQueue();
    void addOniceTimer(const DefaultFunction& handle,uint32_t interval);
    void addEveryTimer(const DefaultFunction& handle,uint32_t interval);
    void runOniceAfter(const DefaultFunction& handle,int interval);
    void runEveryInterval(const DefaultFunction& handle,int interval);

private:
    IOEventLoop* loop;
    int timerFd;
    std::shared_ptr<IOEvent> event;
    std::mutex mutex;
    std::multimap<uint64_t,std::shared_ptr<Timer> > everyTimers;
    std::multimap<uint64_t,std::shared_ptr<Timer> > oniceTimers;

    int createTimeFd();
    void timerHandle();
    bool needResetTimer(std::multimap<uint64_t,std::shared_ptr<Timer> > & times,std::shared_ptr<Timer> timer);
    void resetTimer(std::shared_ptr<Timer> timer);
    void resetTimer();
    void readTimerfd();
};

}
}

#endif // ZPUT_NET_TIME_QUEUE
