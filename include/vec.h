#ifndef __PICOLA_VEC_H__
#define __PICOLA_VEC_H__

#include <iostream>

namespace picola
{

template <size_t dim> class vec {
public:
    vec();

    float &operator() (size_t idx);
    float operator() (size_t idx) const;

private:
    float m_buf[dim];
    size_t m_dim = dim;
};

template <size_t dim>
std::ostream &operator<<(std::ostream &os, const vec<dim> &v);

}

#endif /* __PICOLA_VEC_H__ */
