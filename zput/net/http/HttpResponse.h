#ifndef ZPUT_NET_HTTPRESPONSE
#define ZPUT_NET_HTTPRESPONSE


#include <iostream>
#include <map>

namespace zput
{
namespace net
{

class Buffer;
class HttpResponse
{
public:
    enum HttpStatusCode
    {
        kUnknown,
        k200Ok = 200,
        k301MovedPermanently = 301,
        k400BadRequest = 400,
        k404NotFound = 404,
    };

    explicit HttpResponse(bool close)
        : statusCode(kUnknown),
        closeConnection(close)
    {
    }

    void setStatusCode(HttpStatusCode code)
    {
        statusCode = code;
    }

    void setStatusMessage(const std::string& message)
    {
        statusMessage = message;
    }

    void setCloseConnection(bool on)
    {
        closeConnection = on;
    }

    bool getCloseConnection() const
    {
        return closeConnection;
    }

    void setContentType(const std::string& contentType)
    {
        addHeader("Content-Type", contentType);
    }


    void addHeader(const std::string& key, const std::string& value)
    {
        headers[key] = value;
    }

    void setBody(const std::string& body)
    {
        this->body = body;
    }

    void appendToBuffer(Buffer* output) const;

private:
    std::map<std::string, std::string> headers;
    HttpStatusCode statusCode;
    std::string statusMessage;
    bool closeConnection;
    std::string body;
};

}
}

#endif
