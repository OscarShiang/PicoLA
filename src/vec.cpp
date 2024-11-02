#include <cstring>
#include <stdexcept>

#include "vec.h"

namespace picola
{

template <size_t dim> vec<dim>::vec()
{
    memset(m_buf, 0, sizeof(float) * dim);
}

template <size_t dim>
float &vec<dim>::operator() (size_t idx)
{
    if (idx >= m_dim) {
        throw std::out_of_range("Dimension mismatch");
    } else {
        return m_buf[idx];
    }
}

template <size_t dim>
float vec<dim>::operator() (size_t idx) const
{
    if (idx >= m_dim) {
        throw std::out_of_range("Dimension mismatch");
    } else {
        return m_buf[idx];
    }
}

template <size_t dim>
std::ostream &operator<<(std::ostream &os, const vec<dim> &v)
{
    os << v.m_buf[0];
    for (size_t i = 1; i < v.m_dim; ++i) {
        os << " " << v.m_buf[i];
    }
    return os;
}

} /* namespace picola */
