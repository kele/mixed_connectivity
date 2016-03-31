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

    template<class U, typename = std::is_base_of<U, T>>
    operator mutref<U>()
    {
        return mutref<U>(me);
    }

    T& operator*()
    {
        return me;
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


template<class T>
class SaveAndRestore
{
public:
    explicit SaveAndRestore(mutref<T> obj)
        : m_obj(obj)
        , m_src(obj)
    {
    }

    ~SaveAndRestore()
    {
        *m_src = m_obj;
    }

private:
    T m_obj;
    mutref<T> m_src;
};

template<class T>
SaveAndRestore<T> save(mutref<T> obj) { return SaveAndRestore<T>(obj); }

} // namespace estd
