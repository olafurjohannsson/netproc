
#include <ctime>
#include <iostream>
#include <string>
#include <future>
#include <thread>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <vector>
#include <memory>

using boost::asio::ip::tcp;

#include "NetClient.cpp"



std::shared_ptr<boost::asio::io_service> io_service;

std::string make_datetime_string()
{
    std::time_t now = time(0);
    return ctime(&now);
}

void client_thread() {
	NetClient nc(io_service, "127.0.0.1", std::to_string(8000));
	nc.send("client_thread\n");
}

void Log(std::string &&message)
{
	std::cout << std::move(message) << std::endl;
}

int main(int argc, char* argv[])
{
	Log("C++ Socket Program Started at " + make_datetime_string());
	std::string input = "";
	while (input != "q") {
		std::cout << "Input: " << std::endl;
		std::cin >> input;
		std::cout << input << std::endl;
	}



    std::thread t(client_thread);




    return 0;

    try {
        boost::asio::io_service io_service;
        tcp::endpoint endpoint(tcp::v4(), 8005);

        // listen for connection
        tcp::acceptor acceptor(io_service, endpoint);

        for (;;) {

        	// create socket and accept
        	tcp::socket socket(io_service);
        	acceptor.accept(socket);


            auto buff = boost::asio::buffer("test");

            boost::system::error_code ign_err;
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
