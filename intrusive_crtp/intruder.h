#ifndef INTRUDER_H
#define INTRUDER_H

template<class T>
class intruder
{
    public:
        intruder();

    protected:
        ~intruder();

    public:
        T * prev;
        T * next;
};

////////////////////////////////////////////////////////////////////////////////
template<class T>
inline intruder<T>::intruder()
    : prev(0)
    , next(0)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class T>
inline intruder<T>::~intruder()
{
}
////////////////////////////////////////////////////////////////////////////////

#endif /* INTRUDER_H */
