#include <gtest/gtest.h>

#include "mat.h"

TEST(Mat, Size)
{
    picola::mat<3, 4> m1;

    EXPECT_EQ(m1.nrow(), 3);
    EXPECT_EQ(m1.ncol(), 4);
    EXPECT_EQ(m1.nelem(), 12);
}

TEST(Mat, Assign)
{
    picola::mat<2, 3> m1;
    m1 = { { 1, 2, 3 }, { 4, 5, 6 } };

    EXPECT_EQ(m1(0, 2), 3);
    EXPECT_EQ(m1(1, 1), 5);
    EXPECT_EQ(m1(1, 2), 6);

    m1(0, 2) = 10;
    EXPECT_EQ(m1(0, 2), 10);
    EXPECT_NE(m1(1, 0), 10);
}

TEST(Mat, Add)
{
    picola::mat<3, 2> m1;
    m1 = { { 1, 2 }, { 3, 4 }, { 5, 6 } };

    picola::mat<3, 2> m2;
    m2 = { { 1, 2 }, { 3, 4 }, { 5, 6 } };

    m1 = m1 + m2;

    EXPECT_EQ(m1(0, 0), 2);
    EXPECT_EQ(m1(1, 0), 6);
    EXPECT_EQ(m1(2, 1), 12);
}

TEST(Mat, Sub)
{
    picola::mat<4, 2> m1;
    m1 = { { 8, 7 }, { 6, 5 }, { 4, 3 }, { 2, 1 } };

    picola::mat<4, 2> m2;
    m2 = { { 1, 2 }, { 3, 4 }, { 5, 6 }, { 7, 8 } };

    m1 = m1 - m2;

    float ans[] = { 7, 3, -1, -5 };
    for (size_t i = 0; i < m1.nrow(); i++) {
        EXPECT_EQ(m1(i, 0), ans[i]);
    }
}

TEST(Mat, Mul)
{
    picola::mat<3, 2> m1;
    m1 = { { 1, 2 }, { 3, 4 }, { 5, 6 } };

    m1 = m1 * 5;

    EXPECT_EQ(m1(2, 1), 30);
}

TEST(Mat, Div)
{
    picola::mat<2, 2> m1;
    m1 = { { 1, 2 }, { 3, 4 } };

    m1 = m1 / 2;

    float ans[][2] = { { 0.5, 1 }, { 1.5, 2 } };
    for (size_t i = 0; i < m1.nrow(); i++) {
        for (size_t j = 0; j < m1.ncol(); j++) {
            EXPECT_EQ(m1(i, j), ans[i][j]);
        }
    }

    // Catch divide by zero issue
    EXPECT_THROW(m1 / 0, std::range_error);
}
