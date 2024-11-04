#ifndef __PICOLA_VEC_H__
#define __PICOLA_VEC_H__

#include <iostream>
#include <cstring>
#include <stdexcept>

namespace picola
{

template <size_t dim> class vec {
public:
    vec()
    {
        memset(m_buf, 0, sizeof(float) * dim);
    }

    float &operator()(size_t idx)
    {
        if (idx >= m_dim) {
            throw std::out_of_range("Dimension mismatch");
        } else {
            return m_buf[idx];
        }
    }

    float operator()(size_t idx) const
    {
        if (idx >= m_dim) {
            throw std::out_of_range("Dimension mismatch");
        } else {
            return m_buf[idx];
        }
    }

    size_t size() const
    {
        return m_dim;
    }

private:
    float m_buf[dim];
    size_t m_dim = dim;
};

template <size_t dim>
std::ostream &operator<<(std::ostream &os, const vec<dim> &v)
{
    if (v.size() == 0) {
        return os;
    }

    os << v(0);
    for (size_t i = 1; i < v.size(); ++i) {
        os << " " << v(i);
    }
    return os;
}

}

#endif /* __PICOLA_VEC_H__ */
