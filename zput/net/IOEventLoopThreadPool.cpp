#include <net/IOEventLoopThreadPool.h>

using namespace zput::net;


IOEventLoopThreadPool::IOEventLoopThreadPool(IOEventLoop* loop)
    :mainLoop(loop),
    started(false),
    threadNum(0),
    threadIndex(0)
{
}


//这个线程池构造函数的时候就初始化了，下面应该是增加线程个数
void IOEventLoopThreadPool::AddTheNumberOfLoopThread()
{
    for(int i=0;i<threadNum;i++)
    {
        std::shared_ptr<IOEventLoopThread> thread(new IOEventLoopThread());
        thread->ReleaseRunableSignal();
        threadPool.push_back(thread);
        eventLoopPool.push_back(thread->getLoopInThread());
    }
    started = true;
}

void IOEventLoopThreadPool::AddTheNumberOfLoopThread(int num)
{
    setThreadNum(num);
    AddTheNumberOfLoopThread();
}

bool IOEventLoopThreadPool::isStarted()
{
    return started;
}

void IOEventLoopThreadPool::setThreadNum(uint16_t num)
{
    threadNum = num;
}


IOEventLoop* IOEventLoopThreadPool::getOneLoopFromPool()
{
    //如果线程池为空则返回主Loop
    if(eventLoopPool.empty())
        return mainLoop;

    threadIndex++;
    if(threadIndex>=eventLoopPool.size())
        threadIndex = 0;
    return eventLoopPool[threadIndex];
}

IOEventLoop* IOEventLoopThreadPool::getOneLoopFromPoolWithHash(int hashCode)
{
    //如果线程池为空则返回主Loop
    if(eventLoopPool.empty())
        return mainLoop;

    uint16_t index = hashCode%eventLoopPool.size();
    return eventLoopPool[index];

}
