#include <ctime>
#include <iostream>
#include <string>
#include <thread>
#include <boost/array.hpp>
#include <boost/asio/deadline_timer.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/asio/read_until.hpp>
#include <boost/asio/streambuf.hpp>
#include <boost/asio/write.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <memory>

using boost::asio::deadline_timer;
using boost::asio::ip::tcp;
#define BOOST_ASIO_HAS_MOVE 1

class NetClient {
public:
	NetClient(boost::asio::io_service &svc)
		: socket(svc)
	{

	}

	~NetClient() {

	}

	bool connect(tcp::resolver::iterator it)
	{
		this->socket.async_connect(it->endpoint(), boost::bind(&NetClient::handle, this, _1, it));
		return true;
	}

	void handle(const boost::system::error_code &err, tcp::resolver::iterator it)
	{
		if (!this->socket.is_open())
		{
			std::cout << "socket is not open\n";
		}
		else if (err)
		{
			std::cout << "err " << err.message() << "\n";
			this->socket.close();

			this->connect(++it);
		}
		else
		{
			std::cout << "connected " << it->endpoint() << "\n";
		}
	}

	void send(std::string const& message) {
		boost::system::error_code err;

		boost::asio::write(this->socket, boost::asio::buffer(message), err);

		if (err) {
			std::cout << err.message() << std::endl;
		}
	}

private:
	boost::asio::io_service io_service;
	tcp::socket socket;
};


/*
 *
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


void Log(const std::string &message)
{
	std::cout << "1\n";
}
void Log(std::string &&message)
{
	std::cout << "2\n";
	std::cout << std::move(message);
}

int main(int argc, char* argv[])
{

	auto print = [] (int value) -> void { std::cout << std::to_string(value) << std::endl; };

	Log("C++ Socket Program Started at " + make_datetime_string());
	std::string f = "f";
	Log(f);
	Log("f");

	return 0;
	boost::asio::io_service svc;
	tcp::resolver r(svc);
	tcp::resolver::query q("http://visir.is");
	tcp::resolver::iterator it = r.resolve(q);

	std::cout << it->endpoint() << std::endl;


	return 0;

	NetClient nc(svc);

	std::string input = "";
	Log("Creating NetClient");



	while (input != "q") {
		std::cout << "Input: " << std::endl;
		std::cin >> input;

		std::cout << "sending: " << input << std::endl;
		nc.send(input);
	}





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
 *
 */
 */
