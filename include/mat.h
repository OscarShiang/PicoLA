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

    float &operator()(size_t row, size_t col)
    {
        if (row >= m_nrow || col >= m_ncol) {
            throw std::invalid_argument("Dimension mismatch");
        }
        return m_buf[index(row, col)];
    }

    float operator()(size_t row, size_t col) const
    {
        if (row >= m_nrow || col >= m_ncol) {
            throw std::invalid_argument("Dimension mismatch");
        }
        return m_buf[index(row, col)];
    }

    mat &operator=(const mat &m)
    {
        if (m_nrow != m.nrow() || m_ncol != m.ncol()) {
            throw std::invalid_argument("Dimension mismatch");
        }
        if (&m != this) {
            memcpy(m_buf, m.m_buf, sizeof(float) * m_nelem);
        }
        return *this;
    }

    mat &operator=(const std::vector<std::vector<float> > &m)
    {
        // FIXME: This function is only useful for unit-testing.
        //        Could be useless in practice (No std::vector for embedded devices)
        if (m_nrow != m.size() || m_ncol != m[0].size()) {
            throw std::invalid_argument("Dimension mismatch");
        }

        // Assume to follow row major at the begining
        for (size_t i = 0; i < m.size(); i++) {
            memcpy(&m_buf[i * m_ncol], m[i].data(),
                   sizeof(float) * m[i].size());
        }
        return *this;
    }

private:
    size_t index(size_t row, size_t col) const
    {
        // TODO: Should we implement transpose illusion?
        if (!false) {
            return row * m_ncol + col;
        } else {
            return col * m_nrow + row;
        }
    }

    size_t m_nrow = R;
    size_t m_ncol = C;
    size_t m_nelem = R * C;

    bool m_transpose = false;

    float m_buf[R * C];
};

} // namespace picola

#endif /* __PICOLA_MAT_H__ */
