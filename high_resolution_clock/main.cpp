#include <iostream>
#include <chrono>

int main()
{
    using namespace std;
    using namespace std::chrono;

    high_resolution_clock::time_point const t1 = high_resolution_clock::now();
    high_resolution_clock::time_point const t2 = high_resolution_clock::now();
    high_resolution_clock::time_point const t3 = high_resolution_clock::now();
    high_resolution_clock::time_point const t4 = high_resolution_clock::now();
    high_resolution_clock::time_point const t5 = high_resolution_clock::now();
    high_resolution_clock::time_point const t6 = high_resolution_clock::now();

    cout << time_point_cast<nanoseconds>(t1).time_since_epoch().count() << std::endl;
    cout << time_point_cast<nanoseconds>(t2).time_since_epoch().count() << std::endl;
    cout << time_point_cast<nanoseconds>(t3).time_since_epoch().count() << std::endl;
    cout << time_point_cast<nanoseconds>(t4).time_since_epoch().count() << std::endl;
    cout << time_point_cast<nanoseconds>(t5).time_since_epoch().count() << std::endl;
    cout << time_point_cast<nanoseconds>(t6).time_since_epoch().count() << std::endl;

    return 0;
}
