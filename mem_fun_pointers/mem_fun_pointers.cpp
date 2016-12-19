#include <iostream>

struct Base
{
    virtual void say()
    {
        std::cout << "Base::say()" << std::endl;
    }
};

struct Der : Base
{
    virtual void say()
    {
        std::cout << "Der::say()" << std::endl;
    }
};

typedef void (Base::*bmem_fn)();
typedef void (Der::*dmem_fn)();

int main()
{
    Base b;
    Der d;

    bmem_fn mfb = &Base::say;
    dmem_fn mfd = &Der::say;

    (b.*mfb)();
    //(b.*mfd)();

    (d.*mfb)();
    (d.*mfd)();
}
