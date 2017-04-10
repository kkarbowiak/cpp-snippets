#ifndef UTIL_NUM_ELEMS_H
#define UTIL_NUM_ELEMS_H

#include <cstddef>


namespace util
{
    template <typename T, std::size_t N>
    char (& num_elems_helper(T (& array)[N]))[N];
}

#define num_elems(array) (sizeof (util::num_elems_helper(array)))

#endif /* UTIL_NUM_ELEMS_H */
