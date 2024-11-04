#include <gtest/gtest.h>
#include <sstream>

#include "vec.h"

TEST(TestVec, NaiveTest) {
    EXPECT_STRNE("hello", "world");
    EXPECT_EQ(1 + 1, 2);
}

TEST(TestVec, SizeTest) {
    picola::vec<3> v1;

    EXPECT_EQ(v1.size(), 3);
}

TEST(TestVec, OStreamTest) {
    picola::vec<5> v1;

    v1(0) = 1;
    v1(1) = 2;
    v1(2) = 3;
    v1(3) = 4;
    v1(4) = 5;

    std::stringstream ss;
    ss << v1;

    EXPECT_EQ(ss.str(), "1 2 3 4 5");
}
