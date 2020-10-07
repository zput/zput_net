#ifndef ZPUT_DOME_HTTPSERVERDOME
#define ZPUT_DOME_HTTPSERVERDOME

#include <net/http/HttpServer.h>



class HttpServerDemo : public zput::net::HttpServer
{
public:
    HttpServerDemo(zput::net::IOEventLoop* loop,zput::net::SocketAddr& addr);

    virtual void httpCallback(const zput::net::HttpRequest&, zput::net::HttpResponse*);

};

#endif
