#include "duration_string.h"

#include <sstream>
#include <iomanip>


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
    std::ostringstream oss;
    oss << to_string(std::chrono::duration_cast<std::chrono::seconds>(ms));
    oss << ".";
    oss << std::setw(3) <<  std::setfill('0') << (ms.count() % std::chrono::milliseconds::period::den);
    return oss.str();
}
////////////////////////////////////////////////////////////////////////////////
std::string to_string(std::chrono::microseconds us)
{
    std::ostringstream oss;
    oss << to_string(std::chrono::duration_cast<std::chrono::seconds>(us));
    oss << ".";
    oss << std::setw(6) <<  std::setfill('0') << (us.count() % std::chrono::microseconds::period::den);
    return oss.str();
}
////////////////////////////////////////////////////////////////////////////////
std::string to_string(std::chrono::nanoseconds ns)
{
    std::ostringstream oss;
    oss << to_string(std::chrono::duration_cast<std::chrono::seconds>(ns));
    oss << ".";
    oss << std::setw(9) <<  std::setfill('0') << (ns.count() % std::chrono::nanoseconds::period::den);
    return oss.str();
}
////////////////////////////////////////////////////////////////////////////////
