#ifndef __PICOLA_MAT_H__
#define __PICOLA_MAT_H__

#include <cstring>
#include <vector>

namespace picola
{

template <size_t R, size_t C> class mat {
public:
    mat()
    {
        memset(m_buf, 0, sizeof(float) * R * C);
    }

    mat(std::vector<std::vector<float> > &m)
    {
        // FIXME: This function is only useful for unit-testing.
        //        Could be useless in practice (No std::vector for embedded devices)
        if (m_nrow != m.size() || m_ncol != m[0].size()) {
            throw std::invalid_argument("Dimension mismatch");
        }

        // Assume to follow row major at the begining
        for (size_t i = 0; i < m.size(); i++) {
            memcpy(&m_buf[i * m_nrow], m[i].data(),
                   sizeof(float) * m[i].size());
        }
    }

    size_t nrow()
    {
        return m_nrow;
    }

    size_t ncol()
    {
        return m_ncol;
    }

    size_t nelem()
    {
        return m_nelem;
    }

private:
    size_t m_nrow = R;
    size_t m_ncol = C;
    size_t m_nelem = R * C;

    bool m_transpose = false;

    float m_buf[R * C];
};

} // namespace picola

#endif /* __PICOLA_MAT_H__ */
