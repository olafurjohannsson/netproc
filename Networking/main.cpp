#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <string>
#include <iostream>

class TcpSocket
{
    // SOCK_STREAM
};
class UdpSocket
{
    // SOCK_DGRAM
};
class RawSocket
{
    // SOCK_RAW
};

class Socket
{
  public:
    Socket()
    {
    }

    

    bool Connect(std::string address)
    {
    }

  private:
    int32_t sock_fd;
};

class SocketUtils
{
    public:
        // BSD function
        static uint32_t network_to_ascii(const std::string &address)
        {
            struct in_addr addr;
            bool failure = inet_aton(address.c_str(), &addr) == 0;
            if (!failure)
                return addr.s_addr;
            return NULL;
        }

        // BSD function
        static std::string ascii_to_network(uint32_t s_addr)
        {
            struct in_addr addr;
            addr.s_addr = s_addr;
            const char *s = inet_ntoa(addr);
            return std::string(s);
        }

        // POSIX
        static ()
        {
            char str[INET6_ADDRSTRLEN];
            inet_pton(int, const char*, void*);
        }
        
};

int main()
{
    std::string aa = "192.168.1.1";

    uint32_t a = SocketUtils::network_to_ascii(aa);
    std::string aaa = SocketUtils::ascii_to_network(a);

    printf("%d - %s\n", a, &aa[0]);

    return 0;
}
