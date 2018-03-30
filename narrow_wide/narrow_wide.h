#ifndef NARROW_WIDE_H__DDK
#define NARROW_WIDE_H__DDK

#include <string>


std::string narrow_from_wide(std::wstring const & wstr);
std::wstring wide_from_narrow(std::string const & str);

#endif /* NARROW_WIDE_H__DDK */
