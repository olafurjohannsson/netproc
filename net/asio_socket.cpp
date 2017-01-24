


#include <iostream>
#include <random>
#include <functional>
#include <ctime>
#include <boost/asio.hpp>


class TcpClient
{
public:
	TcpClient(boost::asio::io_service &io)
	{

	}
};



bool test1(const std::string &t)
{
	return t.empty();
}

bool test2(std::string &&t)
{
	return std::move(t).empty();
}

template<typename func>
double measure(func fn, uint32_t times)
{
	clock_t begin = clock();

	for (uint32_t i = 0; i < times; i++) {
		fn();
	}

	clock_t end = clock();
	return double(end - begin) / CLOCKS_PER_SEC;
}

int main()
{

	auto f1 = measure([] () -> void {
		auto fff1 = std::to_string (rand());
		bool ff1 = test1(fff1);
	}, 10000000);

	std::cout << f1 << std::endl;

	auto f2 = measure([] () -> void {
		bool ff2 = test2(std::to_string (rand()));
	}, 10000000);

	std::cout << f2 << std::endl;



	return 0;



}
