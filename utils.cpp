#include <ctime>
#include <iostream>
#include <string>
using namespace std;
//#include <future>
//#include <chrono>
// std::future<bool> f = std::async(is_prime, 444444443);
//std::chrono::milliseconds span(100);
class utils
{
public:
	static void datetime(int &year, int &month, int &day, int &hour, int &minute, int &second, char* zone)
	{
		time_t t = time(0);
		struct tm *now = localtime(&t);
		year = now->tm_year + 1900;
		month = now->tm_mon + 1;
		day = now->tm_mday;
		hour = now->tm_hour;
		minute = now->tm_min;
		second = now->tm_sec;
		if (zone != nullptr)
			strcpy(zone, now->tm_zone);
	}
	static std::string datetime_string()
	{
		int year, month, day, hour, minute, second;
		utils::datetime(year, month, day, hour, minute, second, nullptr);
		char buffer[128];
        memset(buffer, 0x00, sizeof(buffer));
		std::snprintf(buffer, sizeof(buffer), "%d.%d.%d %d:%d.%d", day, month, year, hour, minute, second);
		return std::string(buffer);
	}
	static bool is_prime(int x)
	{
	    for (int i = 2; i <x; i++) {
	        if (x % i == 0)
	            return false;
	    }
	    return true;
	}
};

#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <future>
#include <vector>
#include <chrono>

template <class T>
class network_listener
{
public:
	network_listener(int port)
	{
		this->port = port;
	}

	bool empty()
	{
		std::lock_guard<std::mutex> lock(this->m);
		return this->q.empty();
	}

	void push(T &&t)
	{
		std::cout << "void push(T &&t)\n";
		std::lock_guard<std::mutex> lock(this->m);
		this->q.push(std::move(t));
	}

	void push(T &t)
	{
		std::cout << "void push(T &t)\n";
		std::lock_guard<std::mutex> lock(this->m);
		this->q.push(t);
	}

	T& pop()
	{
		std::unique_lock<std::mutex> lock(this->m);
		if (!q.empty()) {
			T &t = std::move(this->q.front());
			return t.pop();
		}
		return nullptr;
	}

	void worker(int id, std::function fn)
	{
		std::unique_lock<std::mutex> ul(m);
		cv.wait(ul, [&] { return item_received; });

		std::cout << "worker " << id << ", has finished processing\n";
		this->item_processed = true;
		ul.unlock();
		cv.notify_one();
	}


private:
	int port;
	std::condition_variable cv;
	std::queue<T> q;
	std::mutex m;
	bool item_received = false;
	bool item_processed = false;
};
