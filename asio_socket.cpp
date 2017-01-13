
#include <ctime>
#include <iostream>
#include <string>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

boost::asio::io_service io_service;

std::string make_datetime_string()
{
    std::time_t now = time(0);
    return ctime(&now);
}

int main(int argc, char* argv[])
{
    auto d = make_datetime_string();
    std::cout << "socket test started " << d << "\n";
    
    try {
        boost::asio::io_service io_service;
        tcp::endpoint endpoint(tcp::v4(), 8005);

        // listen for connection
        tcp::acceptor acceptor(io_service, endpoint);

        for (;;) {
            tcp::socket socket(io_service);
            acceptor.accept(socket);
            std::cout << "socket accepted\n";
            boost::system::error_code ign_err;
            auto buff = boost::asio::buffer("test");

            boost::asio::write(socket, buff,
                    boost::asio::transfer_all(),
                    ign_err);

        }
    }
    catch (std::exception& err)
    {
        std::cerr << err.what() << std::endl;
    }
    

    
    
    return 0;
}
