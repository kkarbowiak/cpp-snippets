#include "algorithms.h"

#include <iostream>
#include <typeinfo>


template<typename T>
auto print_type()
{
    std::cout << typeid(T).name() << "\n";
    if constexpr (any_of(std::is_same_v<T, char>, std::is_same_v<T, signed char>, std::is_same_v<T, unsigned char>))
    {
        std::cout << "it is a kind of char type\n";
    }

    if constexpr (any_of(std::is_same_v<T, long>, std::is_same_v<T, unsigned long>))
    {
        std::cout << "it is a long type\n";
    }

    if constexpr (any_of(std::is_same_v<T, unsigned char>, std::is_same_v<T, unsigned short>, std::is_same_v<T, unsigned>, std::is_same_v<T, unsigned long>, std::is_same_v<T, unsigned long long>))
    {
        std::cout << "it is an unsigned type\n";
    }

    std::cout << "\n\n";
}

int main()
{
    print_type<char>();
    print_type<signed char>();
    print_type<unsigned char>();
    print_type<int>();
    print_type<long>();
    print_type<unsigned>();
}
