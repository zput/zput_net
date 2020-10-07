#include <net/Timer.h>
#include <sstream>

using namespace zput::net;
using namespace std;

Timer::Timer(uint32_t interval,const TimerCallback& funcHandle)
    :intervalMs(interval),
    handle(funcHandle)
{
    update();
}


struct timeval Timer::getTimeOut()
{
    struct timeval timeOut = now;
    timeOut.tv_sec +=intervalMs/1000;
    timeOut.tv_usec += (intervalMs%1000)*1000;
    return timeOut;
}

struct timespec Timer::getTimeInterval()
{
    int64_t interval = getTimeOutMSecond() - getNowTimeMSecond();
    if(interval<=10)
        interval = 10;
    struct timespec timerInterval ;
    timerInterval.tv_sec =interval/1000;
    timerInterval.tv_nsec = (interval%1000)*1000000;
    return timerInterval;
}



void Timer::update()
{
    struct  timezone   tz;
    gettimeofday(&now,&tz);
}

uint64_t Timer::getTimeOutMSecond()
{
    struct timeval timeOut = getTimeOut();
    uint64_t mSecond = timeOut.tv_sec *1000 + timeOut.tv_usec/1000;
    return mSecond;
}

void Timer::setHandle(const TimerCallback& func)
{
    handle = func;
}

uint64_t Timer::getNowTimeMSecond()
{
    struct  timezone   tz;
    struct timeval nowDate;
    gettimeofday(&nowDate,&tz);
    uint64_t ms = (nowDate.tv_sec)*1000+  nowDate.tv_usec/1000;
    return ms;
}

string Timer::getNowTimeDate()
{
    time_t timep;
    struct tm *p;
    time(&timep);
    p = localtime(&timep);
    stringstream stream;
    stream<<(1900+p->tm_year)<<" "<<(1+p->tm_mon)<<"/"<<p->tm_mday<<" "<<p->tm_hour<<":"<<p->tm_min<<":"<<p->tm_sec<<endl;
    return stream.str();
}


void Timer::timerHandle()
{
    if(handle)
    {
        handle();
    }
}
