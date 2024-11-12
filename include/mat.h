#ifndef __PICOLA_MAT_H__
#define __PICOLA_MAT_H__

#include <cstring>
#include <vector>
#include <ostream>

namespace picola
{

template <size_t R, size_t C> class mat {
public:
    mat()
    {
        memset(m_buf, 0, sizeof(float) * R * C);
    }

    size_t nrow() const
    {
        return m_nrow;
    }

    size_t ncol() const
    {
        return m_ncol;
    }

    size_t nelem() const
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

    mat &operator+(const mat &m)
    {
        if (m_nrow != m.nrow() || m_ncol != m.ncol()) {
            throw std::invalid_argument("Dimension mismatch");
        }

        for (size_t i = 0; i < m_nrow; i++) {
            for (size_t j = 0; j < m_ncol; j++) {
                m_buf[index(i, j)] += m.m_buf[index(i, j)];
            }
        }
        return *this;
    }

    mat &operator-(const mat &m)
    {
        if (m_nrow != m.nrow() || m_ncol != m.ncol()) {
            throw std::invalid_argument("Dimension mismatch");
        }

        for (size_t i = 0; i < m_nrow; i++) {
            for (size_t j = 0; j < m_ncol; j++) {
                m_buf[index(i, j)] -= m.m_buf[index(i, j)];
            }
        }
        return *this;
    }

    mat &operator*(const float val)
    {
        for (size_t i = 0; i < m_nrow; i++) {
            for (size_t j = 0; j < m_ncol; j++) {
                m_buf[index(i, j)] *= val;
            }
        }
        return *this;
    }

    mat &operator/(const float val)
    {
        if (val == 0) {
            throw std::range_error("Divide by zero");
        }

        for (size_t i = 0; i < m_nrow; i++) {
            for (size_t j = 0; j < m_ncol; j++) {
                m_buf[index(i, j)] /= val;
            }
        }
        return *this;
    }

    template <size_t A, size_t B>
    mat<R, B> operator*(const mat<A, B> &m)
    {
        if (m_ncol != m.nrow()) {
            throw std::invalid_argument("Dimension mismatch");
        }

        mat<R, B> retm;
        for (size_t i = 0; i < m_nrow; i++) {
            for (size_t k = 0; k < m.ncol(); k++) {
                float val = 0;
                for (size_t j = 0; j < m_ncol; j++) {
                    val += m_buf[index(i, j)] * m(j, k);
                }
                std::cout << val << std::endl;
                retm(i, k) = val;
            }
        }

        return retm;
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

template <size_t R, size_t C>
std::ostream &operator<<(std::ostream &os, const mat<R, C> &m)
{
    for (size_t i = 0; i < m.nrow(); i++) {
        os << m(i, 0);
        for (size_t j = 1; j < m.ncol(); j++) {
            os << '\t' << m(i, j);
        }
        if (i != m.nrow() - 1) {
            os << '\n';
        }
    }
    return os;
}

} // namespace picola

#endif /* __PICOLA_MAT_H__ */
