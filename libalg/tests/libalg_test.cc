#include <gtest/gtest.h>
TEST(HelloTest, BasicAssertions){
    EXPECT_STRNE("hello", "wolrd");
    EXPECT_EQ(7*6, 42);
}

TEST(CoolTest, BasicAssertions){
    EXPECT_STRNE("hello", "wolrd");
    EXPECT_EQ(7*6, 42);
}

