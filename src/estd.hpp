#pragma once

#include <stdexcept>

namespace estd
{

inline void throw_assert(bool condition, std::exception e = std::logic_error("throw_assert"))
{
    if (!condition)
        throw e;
}

inline void throw_assert(bool condition, std::string s)
{
    if (!condition)
        throw std::logic_error(s);
}

template<class T>
class mutref
{
public:
    explicit mutref(T & obj)
        : me(obj)
    {
    }

    operator T&()
    {
        return me;
    }

    T* operator->()
    {
        return &me;
    }
private:
    T& me;
};

template<class T>
mutref<T> mut(T &obj) { return mutref<T>(obj); }

} // namespace estd
