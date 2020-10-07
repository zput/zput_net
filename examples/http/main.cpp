#include <iostream>
#include <base/LogInterface.h>
#include <net/IOEventLoop.h>
#include <net/IOEventLoopThread.h>
#include "HttpServerDemo.h"

using namespace std;
using namespace zput::net;

int main()
{
    //创建主循环事件分发器
    IOEventLoop loop;

    //监听地址和端口
    SocketAddr addr(true,8080);

    //创建服务器
    HttpServerDemo server(&loop,addr);

    //设置线程池大小
    server.setThreadPoolSize(2);

    //服务器开始运行
    server.start();

    //事件循环机制运行
    loop.run();
}
