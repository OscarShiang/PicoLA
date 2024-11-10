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
