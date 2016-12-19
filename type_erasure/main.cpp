#include "Specs.h"

#include <string>
#include <iostream>


class SpecsProvider1
{
    public:
        std::string getName() const { return "SpecsProvider1"; }
        std::string getType() const { return "SP1"; }
        int getValue() const { return 1; }
};

class SpecsProvider2
{
    public:
        SpecsProvider2(std::string const & name, std::string const & type, int value) : mName(name), mType(type), mValue(value) {}

        std::string getName() const { return mName; }
        std::string getType() const { return mType; }
        int getValue() const { return mValue; }

    private:
        std::string const mName;
        std::string const mType;
        int const mValue;
};

class SpecsProvider3
{
    public:
        std::string getName() const { return "SpecsProvider3"; }

        int getValue() const { return 3; }
};


void printSpecs(Specs specs)
{
    std::cout << "[" << specs.getName() << ", " << specs.getType() << ", " << specs.getValue() << "]" << std::endl;
}

int main()
{
    SpecsProvider1 sp1;
    //SpecsProvider3 sp3;

    Specs specs1(sp1);
    Specs specs2(SpecsProvider2("SpecsProvider2", "SP2", 2));
    //Specs specs3(sp3);

    printSpecs(specs1);
    printSpecs(specs2);
    //printSpecs(specs3);

    return 0;
}
