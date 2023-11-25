#include <gtest/gtest.h>
TEST(abc, Assertions){
    EXPECT_STREQ("hello", "hello");
    EXPECT_EQ(7*6, 42);
}
