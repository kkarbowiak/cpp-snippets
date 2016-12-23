#ifndef INTRUDER_H
#define INTRUDER_H

template<class T>
class intruder
{
    public:
        intruder();

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

#endif /* INTRUDER_H */
