#include <vector>
#include <iostream>


typedef std::vector<int> vi_t;

void print(int i)
{
    std::cout << i << std::endl;
}

void printUp(vi_t const & v)
{
    vi_t::size_type n = 0;
    while (n != v.size())
    {
        print(v[n]); // Process v[n]

        ++n;
    }
}

void printDown(vi_t const & v)
{
    vi_t::size_type n = v.size();
    while (n != 0)
    {
        --n;

        print(v[n]); // Process v[n]
    }
}

int main()
{
    vi_t v;

    for (int i = 1; i <= 5; ++i)
    {
        v.push_back(i);
    }

    printUp(v);
    printDown(v);

    return 0;
}

