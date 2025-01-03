#include <gtest/gtest.h>
#include <sstream>

#include "vec.h"

TEST(Vec, Size) {
    picola::vec<3> v1;

    EXPECT_EQ(v1.size(), 3);
}

TEST(Vec, OStream) {
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

TEST(Vec, Add) {
    picola::vec<3> v1({5, 6, 7});
    picola::vec<3> v2({6, 7, 8});

    v1 = v1 + v2;

    std::stringstream ss;
    ss << v1;

    EXPECT_EQ(ss.str(), "11 13 15");

    // Constant
    v1 = v1 + 3.5;

    ss.str("");
    ss << v1;

    EXPECT_EQ(ss.str(), "14.5 16.5 18.5");
}

TEST(Vec, Sub) {
    picola::vec<3> v1({1.2, 1.3, 1.4});
    picola::vec<3> v2({1, 1, 1});

    v1 = v1 - v2;

    std::stringstream ss;
    ss << v1;

    EXPECT_EQ(ss.str(), "0.2 0.3 0.4");

    // Constant
    v1 = v1 - 10.2;

    ss.str("");
    ss << v1;

    EXPECT_EQ(ss.str(), "-10 -9.9 -9.8");
}

TEST(Vec, Mul) {
    picola::vec<3> v1({5, 4, 3});
    picola::vec<3> v2({2, 3, 4});

    float val = v1 * v2;

    EXPECT_EQ(val, 34);

    v1 = v1 * 0.5;

    std::stringstream ss;
    ss << v1;

    EXPECT_EQ(ss.str(), "2.5 2 1.5");
}

TEST(Vec, Div) {
    picola::vec<3> v1({100, 200, 300});

    v1 = v1 / 100;

    std::stringstream ss;
    ss << v1;

    EXPECT_EQ(ss.str(), "1 2 3");
}
