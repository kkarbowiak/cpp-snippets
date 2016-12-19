#ifndef SPECS_H
#define SPECS_H

#include <string>
#include <memory>

class SpecsImpl;

class Specs
{
    public:
        Specs();
        Specs(Specs const & other);

        template<typename T>
        explicit Specs(T const & value);

        Specs & operator=(Specs const & other);

        std::string getName() const;
        std::string getType() const;
        int getValue() const;

    private:
        std::unique_ptr<SpecsImpl> mImpl;
};

class SpecsImpl
{
    public:
        virtual ~SpecsImpl() {}

        virtual SpecsImpl * clone() const = 0;

        virtual std::string getName() const = 0;
        virtual std::string getType() const = 0;
        virtual int getValue() const = 0;
};

template<typename T>
class InternalImpl : public SpecsImpl
{
    public:
        explicit InternalImpl(T const & value);

        ~InternalImpl() override;

        InternalImpl * clone() const override;

        std::string getName() const override;
        std::string getType() const override;
        int getValue() const override;

    private:
        T mValue;
};


////////////////////////////////////////////////////////////////////////////////
template<typename T>
inline Specs::Specs(T const & value)
    : mImpl(new InternalImpl<T>(value))
{
}
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
template<typename T>
inline InternalImpl<T>::InternalImpl(T const & value)
    : mValue(value)
{
}
////////////////////////////////////////////////////////////////////////////////
template<typename T>
inline InternalImpl<T>::~InternalImpl()
{
}
////////////////////////////////////////////////////////////////////////////////
template<typename T>
inline InternalImpl<T> * InternalImpl<T>::clone() const
{
    return new InternalImpl(mValue);
}
////////////////////////////////////////////////////////////////////////////////
template<typename T>
inline std::string InternalImpl<T>::getName() const
{
    return mValue.getName();
}
////////////////////////////////////////////////////////////////////////////////
template<typename T>
inline std::string InternalImpl<T>::getType() const
{
    return mValue.getType();
}
////////////////////////////////////////////////////////////////////////////////
template<typename T>
inline int InternalImpl<T>::getValue() const
{
    return mValue.getValue();
}
////////////////////////////////////////////////////////////////////////////////

#endif // SPECS_H
