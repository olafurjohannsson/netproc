
#include <iostream>
#include <vector>
#include <future>
#include <chrono>

bool is_prime(int x)
{
    for (int i = 2; i <x; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int main() 
{
    std::cout << "futures.cpp" << std::endl;

    std::future<bool> f = std::async(is_prime, 444444443);

    std::cout << "checking future" << std::endl;
    

    std::chrono::milliseconds span(100);


    return 0;
}
