#include <iostream>
#include <chrono>
#include <thread>

auto now() { return std::chrono::steady_clock::now(); }

auto awake_time()
{
    using std::chrono::operator""ms;
    return now() + 2000ms;
}

int main()
{
    // std::cout << "Hello, waiter...\n"
    //           << std::flush;
    // const auto start{now()};
    std::cout << "start" << std::endl;
    std::this_thread::sleep_until(awake_time());
    std::cout << "end" << std::endl;
    // std::chrono::duration<double, std::milli> elapsed{now() - start};
    // std::cout << "Waited " << elapsed.count() << " ms\n";
}