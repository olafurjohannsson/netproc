#include <ctime>
#include <iostream>
#include <string>
#include <thread>
#include <boost/array.hpp>
#include <boost/asio.hpp>
#include <memory>

using boost::asio::ip::tcp;
#define BOOST_ASIO_HAS_MOVE 1

class NetClient {
public:
	NetClient(std::shared_ptr<boost::asio::io_service> svc, const std::string &host, const std::string &port)
		: io_service(svc), socket(*this->io_service.get())
	{
		if (io_service == nullptr)
			return;

		tcp::resolver resolver(*this->io_service.get());
		tcp::resolver::iterator endpoint = resolver.resolve(tcp::resolver::query(host, port));
		boost::asio::connect(this->socket, endpoint);

	}

	~NetClient() {

	}

	void send(std::string const& message) {
		this->socket.send(boost::asio::buffer(message));
	}

private:
	std::shared_ptr<boost::asio::io_service> io_service;
	tcp::socket socket;
};
