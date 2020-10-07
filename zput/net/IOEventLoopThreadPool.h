#ifndef ZPUT_NET_IOEVENTLOOPTHREADPOOL
#define ZPUT_NET_IOEVENTLOOPTHREADPOOL

#include <vector>
#include <memory>

#include <net/IOEventLoopThread.h>
#include <net/IOEventLoop.h>

namespace zput
{
namespace net
{
class IOEventLoopThreadPool
{
public:
    IOEventLoopThreadPool(IOEventLoop* loop);
    void AddTheNumberOfLoopThread();
    void init(int num );
    bool isStarted();
    void setThreadNum(uint16_t num);

    IOEventLoop* getOneLoopFromPool();
    IOEventLoop* getOneLoopFromPoolWithHash(int hashCode);

private:
    IOEventLoop* mainLoop;
    bool started;
    uint16_t threadNum;
    uint32_t threadIndex;
    std::vector<std::shared_ptr<IOEventLoopThread> >threadPool;
    std::vector<IOEventLoop* > eventLoopPool;
};

}
}

#endif // ZPUT_NET_IOEVENTLOOPTHREADPOOL
