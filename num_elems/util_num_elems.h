#ifndef UTIL_NUM_ELEMS_H
#define UTIL_NUM_ELEMS_H

#include <cstddef>


namespace util
{
    template <typename T, std::size_t N>
    inline std::size_t num_elems(T (&)[N])
    {
        return N;
    }
}

#endif /* UTIL_NUM_ELEMS_H */
