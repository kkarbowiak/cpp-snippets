#include "timestamp.h"

#include <cstdio>  // std::size_t, std::sprintf(), std::vsnprintf()
#include <ctime>
#include <sys/timeb.h>
#include <cstring> // std::memcpy()


namespace tstp
{
////////////////////////////////////////////////////////////////////////////////
std::string getTimestamp()
{
    char buffer[32];

    struct timeb timeb_str;
    struct tm time_str;

    ftime(&timeb_str);
    std::memcpy(&time_str, std::localtime(&timeb_str.time), sizeof(time_str));

    (void) std::sprintf(buffer, "%02d:%02d:%02d.%03d", time_str.tm_hour, time_str.tm_min, time_str.tm_sec, timeb_str.millitm);

    return std::string(buffer);
}
////////////////////////////////////////////////////////////////////////////////
}
