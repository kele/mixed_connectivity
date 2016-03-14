#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>


// TODO: does not work for a subset of size 0 :(((
template<class T>
class SubsetGenerator final
{
public:
    void init(std::vector<T> v, size_t size)
    {
        if (size > v.size())
            throw std::out_of_range("Subset size is too large.");

        m_v = std::move(v);
        m_size = size;

        init_first();
    }

    std::vector<T> get() const
    {
        std::vector<T> results;
        for (size_t i = 0; i < m_v.size(); i++)
            if (m_present[i])
                results.push_back(m_v[i]);
        return results;
    }

    bool next()
    {
        auto to_move = std::find(m_present.begin(), m_present.end(), true);
        auto encountered = 0;
        while (to_move + 1 != m_present.end())
        {
            if (*(to_move + 1) == false)
                break;
            else
            {
                to_move++;
                encountered++;
            }
        }
        if (to_move + 1 == m_present.end())
            return false;

        *(to_move + 1) = true;
        *to_move = false;

        std::fill(m_present.begin(), to_move, false);
        std::fill_n(m_present.begin(), encountered, true);

        return true;
    }

private:
    void init_first()
    {
        m_present.resize(m_v.size());
        std::fill(m_present.begin(), m_present.end(), false);
        std::fill_n(m_present.begin(), m_size, true);
    }

    std::vector<T> m_v;
    std::vector<bool> m_present;
    size_t m_size;
};
