#pragma once
#include <functional>

template<class T, class Container>
void for_each_two(std::function<void(T, T)> f, const Container &c)
{
    auto it = c.begin();
    auto it2 = it; ++it2;

    while (it2 != c.end())
    {
        f(*it, *it2);
        ++it; ++it2;
    }
}
