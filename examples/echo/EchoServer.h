#ifndef ZPUT_DOME_ECHOSERVER
#define ZPUT_DOME_ECHOSERVER

#include <net/TcpServer.h>



class EchoServer : public zput::net::TcpServer
{
public:
    EchoServer(zput::net::IOEventLoop* loop,zput::net::SocketAddr& addr);
    //考虑到tcpConnect可能关闭后内存被自动释放，传shared_ptr比较安全。
    virtual void connectCallback(std::shared_ptr<zput::net::TcpConnect> tcpConnect);
    virtual void messageCallback(std::shared_ptr<zput::net::TcpConnect>, zput::net::Buffer&);
    virtual void writeCompletCallback(std::shared_ptr<zput::net::TcpConnect> tcpConnect) ;
    virtual void connectCloseCallback( std::shared_ptr<zput::net::TcpConnect>);
};

#endif // ZPUT_DOME_ECHOSERVER
