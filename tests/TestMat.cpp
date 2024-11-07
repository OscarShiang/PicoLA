#include <gtest/gtest.h>

#include "mat.h"

TEST(Mat, Size)
{
    picola::mat<3, 4> m1;

    EXPECT_EQ(m1.nrow(), 3);
    EXPECT_EQ(m1.ncol(), 4);
    EXPECT_EQ(m1.nelem(), 12);
}
