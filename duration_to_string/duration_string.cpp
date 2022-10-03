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
////////////////////////////////////////////////////////////////////////////////
std::string to_string(std::chrono::hours hh)
{
    return std::to_string(hh.count());
}
////////////////////////////////////////////////////////////////////////////////
std::string to_string(std::chrono::minutes mm)
{
    std::ostringstream oss;
    oss << to_string(std::chrono::duration_cast<std::chrono::hours>(mm));
    oss << ":";
    oss << std::setw(2) << std::setfill('0') << (mm.count() % 60);
    return oss.str();
}
////////////////////////////////////////////////////////////////////////////////
std::string to_string(std::chrono::seconds ss)
{
    std::ostringstream oss;
    oss << to_string(std::chrono::duration_cast<std::chrono::minutes>(ss));
    oss << ":";
    oss << std::setw(2) <<  std::setfill('0') << (ss.count() % 60);
    return oss.str();
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
