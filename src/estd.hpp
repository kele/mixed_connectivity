#pragma once

#include <stdexcept>

namespace estd
{

void throw_assert(bool condition, std::exception e = std::logic_error("throw_assert"))
{
    if (!condition)
        throw e;
}

void throw_assert(bool condition, std::string s)
{
    if (!condition)
        throw std::logic_error(s);
}

} // namespace estd
