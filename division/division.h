#ifndef INC_DIVISION_H
#define INC_DIVISION_H

namespace dv
{
    template<typename T>
    struct division
    {
        T quot;
        T rem;
    };
}

namespace dv
{
    template<typename T>
    division<T> divide(T numerator, T denominator);
}

namespace dv
{
////////////////////////////////////////////////////////////////////////////////
template<typename T>
inline division<T> divide(T numerator, T denominator)
{
    division<T> result;

    result.quot = numerator / denominator;
    result.rem = numerator % denominator;

    return result;
}
////////////////////////////////////////////////////////////////////////////////
}

#endif /* INC_DIVISION_H */
