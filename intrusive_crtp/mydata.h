#ifndef MYDATA_H
#define MYDATA_H

#include "intruder.h"

#include <string>


class MyData : public intruder<MyData>
{
    public:
        MyData(std::string const & text) : mText(text) {}

    public:
        std::string mText;
};

#endif /* MYDATA_H */
