#ifndef ALGORITHMS_H
#define ALGORITHMS_H


template<class ... Args>
constexpr auto all_of(Args ... args)
{
    return (args && ...);
}

template<class ... Args>
constexpr auto any_of(Args ... args)
{
    return (args || ...);
}

#endif /* ALGORITHMS_H */
