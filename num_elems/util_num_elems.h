#ifndef UTIL_NUM_ELEMS_H
#define UTIL_NUM_ELEMS_H

#include <cstddef>


namespace util
{
    template <typename T, std::size_t N>
    constexpr std::size_t num_elems(T const (&)[N]) noexcept
    {
        return N;
    }
}

#endif /* UTIL_NUM_ELEMS_H */
