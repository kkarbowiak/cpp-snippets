#include "narrow_wide.h"

#include <locale>
#include <codecvt>


std::string narrow_from_wide(std::wstring const & wstr)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;

    return converter.to_bytes(wstr);
}

std::wstring wide_from_narrow(std::string const & str)
{
    std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> converter;

    return converter.from_bytes(str);
}
