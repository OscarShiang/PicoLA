#ifndef __PICOLA_VEC_H__
#define __PICOLA_VEC_H__

#include <iostream>
#include <cstring>
#include <stdexcept>
#include <vector>

namespace picola
{

template <size_t dim> class vec {
public:
    vec()
    {
        memset(m_buf, 0, sizeof(float) * dim);
    }

    vec(const std::vector<float> &v)
    {
        if (m_dim != v.size()) {
            throw new std::invalid_argument("Dimension mismatch");
        }

        memcpy(m_buf, v.data(), sizeof(float) * v.size());
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

    vec &operator=(const vec &v)
    {
        if (m_dim != v.size()) {
            throw new std::invalid_argument("Dimension mismatch");
        }

        memcpy(m_buf, v.m_buf, sizeof(float) * m_dim);

        return *this;
    }

    vec &operator+(const vec &v)
    {
        if (m_dim != v.size()) {
            throw new std::invalid_argument("Dimension mismatch");
        }

        // TODO: need to switch to faster implementation
        for (size_t i = 0; i < m_dim; i++) {
            m_buf[i] += v.m_buf[i];
        }
        return *this;
    }

    vec &operator-(const vec &v)
    {
        if (m_dim != v.size()) {
            throw new std::invalid_argument("Dimension mismatch");
        }

        // TODO: need to switch to faster implementation
        for (size_t i = 0; i < m_dim; i++) {
            m_buf[i] -= v.m_buf[i];
        }
        return *this;
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
