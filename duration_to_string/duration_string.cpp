#include "duration_string.h"

#include <sstream>
#include <iomanip>
#include <cmath>


template<typename Duration>
std::string to_string_impl(Duration dur)
{
    std::ostringstream oss;
    oss << to_string(std::chrono::duration_cast<std::chrono::seconds>(dur));
    oss << ".";
    oss << std::setw(std::log10(Duration::period::den)) <<  std::setfill('0') << (dur.count() % Duration::period::den);
    return oss.str();
}

template<typename Duration1, typename Duration2>
std::string to_string_impl(Duration2 dur)
{
    std::ostringstream oss;
    oss << to_string(std::chrono::duration_cast<Duration1>(dur));
    oss << ":";
    oss << std::setw(2) << std::setfill('0') << (dur.count() % 60);
    return oss.str();
}
////////////////////////////////////////////////////////////////////////////////
std::string to_string(std::chrono::hours hh)
{
    return std::to_string(hh.count());
}
////////////////////////////////////////////////////////////////////////////////
std::string to_string(std::chrono::minutes mm)
{
    return to_string_impl<std::chrono::hours>(mm);
}
////////////////////////////////////////////////////////////////////////////////
std::string to_string(std::chrono::seconds ss)
{
    return to_string_impl<std::chrono::minutes>(ss);
}
////////////////////////////////////////////////////////////////////////////////
std::string to_string(std::chrono::milliseconds ms)
{
    return to_string_impl(ms);
}
////////////////////////////////////////////////////////////////////////////////
std::string to_string(std::chrono::microseconds us)
{
    return to_string_impl(us);
}
////////////////////////////////////////////////////////////////////////////////
std::string to_string(std::chrono::nanoseconds ns)
{
    return to_string_impl(ns);
}
////////////////////////////////////////////////////////////////////////////////
