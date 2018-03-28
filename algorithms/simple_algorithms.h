#ifndef INC_ALGORITHMS_H
#define INC_ALGORITHMS_H

namespace algo
{
    template<class InputIterator, class Predicate>
    bool all_true(InputIterator first, InputIterator last, Predicate pred);

    template<class InputIterator, class Predicate>
    bool any_true(InputIterator first, InputIterator last, Predicate pred);

    template<class InputIterator, class Function, class Predicate>
    Function for_each_if(InputIterator first, InputIterator last, Function fn, Predicate pred);
}


namespace algo
{
////////////////////////////////////////////////////////////////////////////////
template<class InputIterator, class Predicate>
inline bool all_true(InputIterator first, InputIterator last, Predicate pred)
{
    bool result = true;

    for (; result && first != last; ++first)
    {
        result = result && pred(*first);
    }

    return result;
}
////////////////////////////////////////////////////////////////////////////////
template<class InputIterator, class Predicate>
inline bool any_true(InputIterator first, InputIterator last, Predicate pred)
{
    bool result = false;

    for (; !result && first != last; ++first)
    {
        result = result || pred(*first);
    }

    return result;
}
////////////////////////////////////////////////////////////////////////////////
template<class InputIterator, class Function, class Predicate>
inline Function for_each_if(InputIterator first, InputIterator last, Function fn, Predicate pred)
{
    while (first != last)
    {
        if (pred(*first))
        {
            fn(*first);
        }

        ++first;
    }

    return fn;
}
////////////////////////////////////////////////////////////////////////////////
}

#endif // INC_ALGORITHMS_H
