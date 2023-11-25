#include <gtest/gtest.h>
TEST(AnotherTest, Assertions){
    EXPECT_STREQ("hello", "hello");
    EXPECT_EQ(7*6, 42);
}

TEST(alpha, Assertions){
    EXPECT_STREQ("hello", "hello");
    EXPECT_EQ(7*6, 42);
}

// TEST(beta, Assertions){
//     EXPECT_STREQ("hello", "hello");
//     int a{10};
//     EXPECT_EQ(1,2);
//     EXPECT_EQ(7*6, 42);
// }
// TEST(gamma, Assertions){
//     EXPECT_STREQ("hello", "hello");
//     int a{10};
//     EXPECT_EQ(1,2);
//     EXPECT_EQ(7*6, 42);
// }