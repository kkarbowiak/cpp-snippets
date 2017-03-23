#include "duration_string.h"

#include <iostream>
#include <vector>

template<class T>
void print(T v)
{
    for (auto t: v)
    {
        std::cout << t.count() << ":    " << to_string(t) << std::endl;
    }
}

int main()
{
    using std::chrono::hours;
    using std::chrono::minutes;
    using std::chrono::seconds;
    using std::chrono::milliseconds;
    using std::chrono::microseconds;
    using std::chrono::nanoseconds;
    std::vector<hours> hh = {hours(0), hours(1), hours(10), hours(24), hours(25)};
    std::vector<minutes> mm = {minutes(0), minutes(1), minutes(59), minutes(60), minutes(61), minutes(1439), minutes(1440), minutes(1441)};
    std::vector<seconds> ss = {seconds(0), seconds(59), seconds(60), seconds(61), seconds(3599), seconds(3600), seconds(3601)};
    std::vector<milliseconds> ms = {milliseconds(0), milliseconds(999), milliseconds(1000), milliseconds(1001), milliseconds(59999), milliseconds(60000), milliseconds(60001)};
    std::vector<microseconds> us = {microseconds(0), microseconds(999999), microseconds(1000000), microseconds(1000001)};
    std::vector<nanoseconds> ns = {nanoseconds(0), nanoseconds(999999999), nanoseconds(1000000000)};

    std::cout << "hours:\n";
    print(hh);
    std::cout << "\nminutes:\n";
    print(mm);
    std::cout << "\nseconds:\n";
    print(ss);
    std::cout << "\nmilliseconds:\n";
    print(ms);
    std::cout << "\nmicroseconds:\n";
    print(us);
    std::cout << "\nnanoseconds:\n";
    print(ns);
}
