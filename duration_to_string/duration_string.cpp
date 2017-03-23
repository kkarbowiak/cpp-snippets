#include "duration_string.h"


////////////////////////////////////////////////////////////////////////////////
std::string to_string(std::chrono::hours hh)
{
    return std::to_string(hh.count());
}
////////////////////////////////////////////////////////////////////////////////
std::string to_string(std::chrono::minutes mm)
{
    return
        to_string(std::chrono::duration_cast<std::chrono::hours>(mm))
        + ":"
        + std::to_string(mm.count() % 60);
}
////////////////////////////////////////////////////////////////////////////////
std::string to_string(std::chrono::seconds ss)
{
    return
        to_string(std::chrono::duration_cast<std::chrono::minutes>(ss))
        + ":"
        + std::to_string(ss.count() % 60);
}
////////////////////////////////////////////////////////////////////////////////
std::string to_string(std::chrono::milliseconds ms)
{
    return
        to_string(std::chrono::duration_cast<std::chrono::seconds>(ms))
        + "."
        + std::to_string(ms.count() % 1000);
}
////////////////////////////////////////////////////////////////////////////////
std::string to_string(std::chrono::microseconds us)
{
    return
        to_string(std::chrono::duration_cast<std::chrono::seconds>(us))
        + "."
        + std::to_string(us.count() % 1000000);
}
////////////////////////////////////////////////////////////////////////////////
std::string to_string(std::chrono::nanoseconds ns)
{
    return
        to_string(std::chrono::duration_cast<std::chrono::seconds>(ns))
        + "."
        + std::to_string(ns.count() % 1000000000);
}
////////////////////////////////////////////////////////////////////////////////
