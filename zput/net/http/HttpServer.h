#ifndef ZPUT_NET_HTTPSERVER
#define ZPUT_NET_HTTPSERVER

#include <net/TcpServer.h>
#include <net/http/HttpResponse.h>
#include <net/http/HttpRequest.h>


namespace zput
{
namespace net
{

class HttpServer : public zput::net::TcpServer
{
public:
    HttpServer(zput::net::IOEventLoop* loop,zput::net::SocketAddr& addr);
    //HttpServer类总是被继承，虚析构相对安全。
    virtual ~HttpServer();
private:
    virtual void connectCallback(std::shared_ptr<TcpConnect> tcpConnect);
    virtual void messageCallback(std::shared_ptr<TcpConnect>, Buffer&);
    virtual void writeCompletCallback(std::shared_ptr<TcpConnect> tcpConnect) ;
    virtual void connectCloseCallback(std::shared_ptr<TcpConnect>);

    virtual void httpCallback(const HttpRequest&, HttpResponse*);

    void onRequest( std::shared_ptr<TcpConnect> conn, const HttpRequest& req);
};

}
}
#endif // ZPUT_NET_HTTPSERVER
