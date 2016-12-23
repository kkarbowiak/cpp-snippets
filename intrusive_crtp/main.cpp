#include "mydata.h"

#include <iostream>
#include <iomanip> 


void print(MyData const * md)
{
    std::cout << "MyData [0x" << std::hex << std::setw(8) << std::setfill('0') << (unsigned long int)md << "]";
    if (md)
    {
        std::cout << " '" << md->mText << "'";
        std::cout << " p<0x" << std::hex << std::setw(8) << std::setfill('0') << (unsigned long int)md->prev << ">";
        std::cout << " n<0x" << std::hex << std::setw(8) << std::setfill('0') << (unsigned long int)md->next << ">";
    }
    std::cout << std::endl;
}

void printChain(MyData const * md)
{
    while (md)
    {
        print(md);

        md = md->next;
    }
    
    print(md);
}

int main()
{
    MyData md1("md1");
    MyData md2("md2");
    MyData md3("md3");
    MyData md4("md4");

    md1.next = &md2;
    md2.next = &md3;
    md3.next = &md4;

    md2.prev = &md1;
    md3.prev = &md2;
    md4.prev = &md3;

    printChain(&md1);

    return 0;
}
