#ifndef ZPUT_THREAD
#define ZPUT_THREAD

#include <thread>
#include <memory>
#include <condition_variable>


namespace base
{

class Thread
{
public :
    Thread();
    //Thread 类总是被继承，虚析构会安全。
    virtual ~Thread();
    void ReleaseRunableSignal();

    //
    static std::thread::id getNowThreadId();
    bool isStarted();
    //该函数为实际线程函数，子类需要实现。
    virtual void run()=0;
protected:
    //延迟函数只有在线程或者继承类中使用比较安全
    void sleepSeconds(int seconds);
private:
    //在该函数内阻塞，直到用ReleaseRunableSignal()函数。
    void judgeStateThenRun();
    bool started;
    std::mutex mutex;
    std::condition_variable  condtion;
    std::shared_ptr<std::thread> thread;

};


}

#endif // THREAD_H_INCLUDED
