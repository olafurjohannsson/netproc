
#include "utils.cpp"


#include <iostream>
#include <vector>

#include <boost/thread.hpp>
#include <boost/chrono.hpp>



void wait(int seconds)
{
	boost::this_thread::sleep_for(boost::chrono::seconds{seconds});
}


int main()
{
    std::cout << "Starting app on " << utils::datetime_string() << std::endl;

    while (true)
    {
    	std::cout << utils::datetime_string() << std::endl;
    	wait(2);
    }







    return 0;
}


/*
 *
 * C++ receives data on a listening socket, it puts that data in a queue.
 * The format of the data is JSON and has a Timestamp, Id, DataPacket properties.
 * It creates a thread pool of 4 threads, or future objects, that process the data concurrently via a lambda or callback that is sent in the ctor.
 *
 * Best to use boost::asio
 *
 */
