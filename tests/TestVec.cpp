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

TEST(TestVec, AddTest) {
    picola::vec<3> v1({5, 6, 7});
    picola::vec<3> v2({6, 7, 8});

    v1 = v1 + v2;

    std::stringstream ss;
    ss << v1;

    EXPECT_EQ(ss.str(), "11 13 15");
}

TEST(TestVec, SubTest) {
    picola::vec<3> v1({1.2, 1.3, 1.4});
    picola::vec<3> v2({1, 1, 1});

    v1 = v1 - v2;

    std::stringstream ss;
    ss << v1;

    EXPECT_EQ(ss.str(), "0.2 0.3 0.4");
}
