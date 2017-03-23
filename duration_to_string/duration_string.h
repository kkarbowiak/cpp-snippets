#ifndef DURATION_STRING_H
#define DURATION_STRING_H

#include <chrono>
#include <string>


std::string to_string(std::chrono::hours hh);
std::string to_string(std::chrono::minutes mm);
std::string to_string(std::chrono::seconds ss);
std::string to_string(std::chrono::milliseconds ms);
std::string to_string(std::chrono::microseconds us);
std::string to_string(std::chrono::nanoseconds ns);

#endif /* DURATION_STRING_H */
