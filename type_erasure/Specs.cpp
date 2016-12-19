#include "Specs.h"

#include <cstddef>
#include <cassert>


Specs::Specs()
    : mImpl()
{
}

Specs::Specs(Specs const & other)
    : mImpl(other.mImpl
        ? other.mImpl->clone()
        : nullptr)
{
}

Specs & Specs::operator=(Specs const & other)
{
    mImpl.reset(other.mImpl
        ? other.mImpl->clone()
        : nullptr);

    return *this;
}

std::string Specs::getName() const
{
    assert(mImpl);

    return mImpl->getName();
}

std::string Specs::getType() const
{
    assert(mImpl);

    return mImpl->getType();
}

int Specs::getValue() const
{
    assert(mImpl);

    return mImpl->getValue();
}
