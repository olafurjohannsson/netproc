
#include <iostream>
#include <vector>

#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <random>
#include "utils.cpp"

const int magic = 4;

void wait(int seconds)
{
	boost::this_thread::sleep_for(boost: :chrono::seconds{seconds});
}


int main()
{
    std::cout << "Starting app on " << utils::datetime_string() << std::endl;
    network_listener<std::string> netlistener(8000);
    
    int i = 0;
    while (true)
    {
        std::string s = utils::datetime_string();

        netlistener.push(s);

        if (i == magic)
        {
            i = 0;

            while (!netlistener.empty()) {
                std::cout << "popping " << netlistener.pop() << std::endl;
                wait(1);
            }
        }


        i++;
    	std::cout << s << std::endl;
    	wait(1);
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
