#include <vector>


struct BigStruct
{
    BigStruct(int /* a */, int /* b */, double /* c */, double /* d */) {}
};

int main()
{
    auto getBig = [](int a) { return BigStruct(a, 2, 3.14, 2.72); };

    std::vector<BigStruct> vec;

    vec.push_back(getBig(1));
    vec.push_back(getBig(2));
    vec.push_back(getBig(3));
    vec.push_back(getBig(4));
}
