#ifndef INC_SCOPEDCLEARER_H
#define INC_SCOPEDCLEARER_H

template<class container>
class scoped_clearer
{
    public:
        explicit scoped_clearer(container & c);
        ~scoped_clearer();

    private:
        container & d_container;
};

////////////////////////////////////////////////////////////////////////////////
template<class container>
inline scoped_clearer<container>::scoped_clearer(container & c)
    : d_container(c)
{
}
////////////////////////////////////////////////////////////////////////////////
template<class container>
inline scoped_clearer<container>::~scoped_clearer()
{
    d_container.clear();
}
////////////////////////////////////////////////////////////////////////////////

#endif // INC_SCOPEDCLEARER_H
