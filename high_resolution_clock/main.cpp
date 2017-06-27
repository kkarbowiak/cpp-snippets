#include <iostream>
#include <chrono>

int main()
{
    using namespace std::chrono;

    auto const t1 = high_resolution_clock::now();
    auto const t2 = high_resolution_clock::now();
    auto const t3 = high_resolution_clock::now();
    auto const t4 = high_resolution_clock::now();
    auto const t5 = high_resolution_clock::now();
    auto const t6 = high_resolution_clock::now();

    std::cout << time_point_cast<nanoseconds>(t1).time_since_epoch().count() << std::endl;
    std::cout << time_point_cast<nanoseconds>(t2).time_since_epoch().count() << std::endl;
    std::cout << time_point_cast<nanoseconds>(t3).time_since_epoch().count() << std::endl;
    std::cout << time_point_cast<nanoseconds>(t4).time_since_epoch().count() << std::endl;
    std::cout << time_point_cast<nanoseconds>(t5).time_since_epoch().count() << std::endl;
    std::cout << time_point_cast<nanoseconds>(t6).time_since_epoch().count() << std::endl;

    return 0;
}
