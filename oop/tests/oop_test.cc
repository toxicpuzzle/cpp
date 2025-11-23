#include <gtest/gtest.h>
#include <sstream>
#include "../Ball/Ball.h"
#include "../IntPair/IntPair.h"
#include "../Point3d/Point3d.h"
#include "../RGBA/RGBA.h"
#include "../Stack/Stack.h"

/**
 * OOP Exercises Test Suite
 *
 * Tests for basic C++ OOP concepts including:
 * - Constructors and initialization
 * - Member functions
 * - Encapsulation
 * - Static members
 */

// ============================================================================
// Ball Class Tests
// ============================================================================

TEST(BallTest, DefaultConstructor) {
    Ball ball;
    EXPECT_EQ(ball.m_color, "black");
    EXPECT_FLOAT_EQ(ball.m_radius, 10.0f);
}

TEST(BallTest, ColorConstructor) {
    Ball ball("blue");
    EXPECT_EQ(ball.m_color, "blue");
    EXPECT_FLOAT_EQ(ball.m_radius, 0.0f);
}

TEST(BallTest, RadiusConstructor) {
    Ball ball(20.0f);
    EXPECT_EQ(ball.m_color, "red");
    EXPECT_FLOAT_EQ(ball.m_radius, 1.0f);
}

TEST(BallTest, FullConstructor) {
    Ball ball("green", 15.5f);
    EXPECT_EQ(ball.m_color, "green");
    EXPECT_FLOAT_EQ(ball.m_radius, 15.5f);
}

TEST(BallTest, DelegatingConstructors) {
    Ball ball1("yellow");
    EXPECT_EQ(ball1.m_color, "yellow");

    Ball ball2(25.0f);
    EXPECT_EQ(ball2.m_color, "red");
}

TEST(BallTest, PrintFunction) {
    Ball ball("purple", 12.5f);

    // Redirect cout to test print output
    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    ball.print();

    std::cout.rdbuf(old);
    EXPECT_EQ(buffer.str(), "color: purple, radius: 12.5\n");
}

// ============================================================================
// IntPair Class Tests
// ============================================================================

TEST(IntPairTest, DefaultConstruction) {
    IntPair pair;
    EXPECT_EQ(pair.a, 0);
    EXPECT_EQ(pair.b, 0);
}

TEST(IntPairTest, InitializerListConstruction) {
    IntPair pair{5, 10};
    EXPECT_EQ(pair.a, 5);
    EXPECT_EQ(pair.b, 10);
}

TEST(IntPairTest, SetMethod) {
    IntPair pair;
    pair.set(3, 7);
    EXPECT_EQ(pair.a, 3);
    EXPECT_EQ(pair.b, 7);
}

TEST(IntPairTest, SetMethodOverwrite) {
    IntPair pair{1, 2};
    pair.set(10, 20);
    EXPECT_EQ(pair.a, 10);
    EXPECT_EQ(pair.b, 20);
}

TEST(IntPairTest, PrintFunction) {
    IntPair pair{42, 99};

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    pair.print();

    std::cout.rdbuf(old);
    EXPECT_EQ(buffer.str(), "42 99\n");
}

// ============================================================================
// Point3d Class Tests
// ============================================================================

TEST(Point3dTest, DefaultConstruction) {
    Point3d point;
    EXPECT_EQ(point.getX(), 0);
    EXPECT_EQ(point.getY(), 0);
    EXPECT_EQ(point.getZ(), 0);
}

TEST(Point3dTest, SetValues) {
    Point3d point;
    point.setValues(1, 2, 3);
    EXPECT_EQ(point.getX(), 1);
    EXPECT_EQ(point.getY(), 2);
    EXPECT_EQ(point.getZ(), 3);
}

TEST(Point3dTest, SetValuesMultipleTimes) {
    Point3d point;
    point.setValues(5, 10, 15);
    EXPECT_EQ(point.getX(), 5);
    EXPECT_EQ(point.getY(), 10);
    EXPECT_EQ(point.getZ(), 15);

    point.setValues(-5, -10, -15);
    EXPECT_EQ(point.getX(), -5);
    EXPECT_EQ(point.getY(), -10);
    EXPECT_EQ(point.getZ(), -15);
}

TEST(Point3dTest, IsEqualSame) {
    Point3d point1;
    point1.setValues(1, 2, 3);

    Point3d point2;
    point2.setValues(1, 2, 3);

    EXPECT_TRUE(point1.isEqual(point2));
}

TEST(Point3dTest, IsEqualDifferent) {
    Point3d point1;
    point1.setValues(1, 2, 3);

    Point3d point2;
    point2.setValues(3, 4, 5);

    EXPECT_FALSE(point1.isEqual(point2));
}

TEST(Point3dTest, IsEqualPartiallyDifferent) {
    Point3d point1;
    point1.setValues(1, 2, 3);

    Point3d point2;
    point2.setValues(1, 2, 4);

    EXPECT_FALSE(point1.isEqual(point2));
}

TEST(Point3dTest, PrintFunction) {
    Point3d point;
    point.setValues(10, 20, 30);

    // printf doesn't redirect to cout, so we just verify it doesn't crash
    // In a real test, you'd redirect stdout or check the Point3d values directly
    point.print();
    EXPECT_EQ(point.getX(), 10);
    EXPECT_EQ(point.getY(), 20);
    EXPECT_EQ(point.getZ(), 30);
}

// ============================================================================
// RGBA Class Tests
// ============================================================================

TEST(RGBATest, DefaultConstruction) {
    RGBA color;
    EXPECT_EQ(color.getRed(), 0);
    EXPECT_EQ(color.getGreen(), 0);
    EXPECT_EQ(color.getBlue(), 0);
    EXPECT_EQ(color.getAlpha(), 255);
}

TEST(RGBATest, PartialConstruction) {
    RGBA color(127, 255, 64);
    EXPECT_EQ(color.getRed(), 127);
    EXPECT_EQ(color.getGreen(), 255);
    EXPECT_EQ(color.getBlue(), 64);
    EXPECT_EQ(color.getAlpha(), 255);
}

TEST(RGBATest, FullConstruction) {
    RGBA color(255, 128, 64, 200);
    EXPECT_EQ(color.getRed(), 255);
    EXPECT_EQ(color.getGreen(), 128);
    EXPECT_EQ(color.getBlue(), 64);
    EXPECT_EQ(color.getAlpha(), 200);
}

TEST(RGBATest, TealColor) {
    RGBA teal(0, 127, 127);
    EXPECT_EQ(teal.getRed(), 0);
    EXPECT_EQ(teal.getGreen(), 127);
    EXPECT_EQ(teal.getBlue(), 127);
    EXPECT_EQ(teal.getAlpha(), 255);
}

TEST(RGBATest, ConstMembers) {
    RGBA color(100, 150, 200, 128);

    // Test that getters work (const members cannot be modified)
    EXPECT_EQ(color.getRed(), 100);
    EXPECT_EQ(color.getGreen(), 150);
    EXPECT_EQ(color.getBlue(), 200);
    EXPECT_EQ(color.getAlpha(), 128);
}

TEST(RGBATest, PrintFunction) {
    RGBA color(255, 128, 64, 200);

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    color.print();

    std::cout.rdbuf(old);
    EXPECT_EQ(buffer.str(), "r=255 g=128 b=64 a=200\n");
}

// ============================================================================
// Stack Class Tests
// ============================================================================

TEST(StackTest, DefaultConstruction) {
    Stack stack;
    EXPECT_EQ(stack.getSize(), 0);
}

TEST(StackTest, PushSingleElement) {
    Stack stack;
    EXPECT_TRUE(stack.push(5));
    EXPECT_EQ(stack.getSize(), 1);
    EXPECT_EQ(stack.get(0), 5);
}

TEST(StackTest, PushMultipleElements) {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    EXPECT_EQ(stack.getSize(), 3);
    EXPECT_EQ(stack.get(0), 1);
    EXPECT_EQ(stack.get(1), 2);
    EXPECT_EQ(stack.get(2), 3);
}

TEST(StackTest, PushToCapacity) {
    Stack stack;
    for (int i = 0; i < 10; ++i) {
        EXPECT_TRUE(stack.push(i));
    }
    EXPECT_EQ(stack.getSize(), 10);
}

TEST(StackTest, PushBeyondCapacity) {
    Stack stack;
    for (int i = 0; i < 10; ++i) {
        stack.push(i);
    }
    EXPECT_FALSE(stack.push(11)); // Should fail
    EXPECT_EQ(stack.getSize(), 10);
}

TEST(StackTest, PopSingleElement) {
    Stack stack;
    stack.push(42);

    int value = stack.pop();
    EXPECT_EQ(value, 42);
    EXPECT_EQ(stack.getSize(), 0);
}

TEST(StackTest, PopMultipleElements) {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);

    EXPECT_EQ(stack.pop(), 3);
    EXPECT_EQ(stack.pop(), 2);
    EXPECT_EQ(stack.pop(), 1);
    EXPECT_EQ(stack.getSize(), 0);
}

TEST(StackTest, PushAndPopSequence) {
    Stack stack;
    stack.push(5);
    stack.push(3);
    stack.push(8);

    EXPECT_EQ(stack.getSize(), 3);

    stack.pop();
    EXPECT_EQ(stack.getSize(), 2);

    stack.pop();
    stack.pop();
    EXPECT_EQ(stack.getSize(), 0);
}

TEST(StackTest, LIFO_Behavior) {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Last in, first out
    EXPECT_EQ(stack.pop(), 30);
    EXPECT_EQ(stack.pop(), 20);
    EXPECT_EQ(stack.pop(), 10);
}

TEST(StackTest, PrintFunction) {
    Stack stack;
    stack.push(5);
    stack.push(3);
    stack.push(8);

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    stack.print();

    std::cout.rdbuf(old);
    EXPECT_EQ(buffer.str(), "( 5 3 8 )\n");
}

TEST(StackTest, PrintEmpty) {
    Stack stack;

    std::stringstream buffer;
    std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

    stack.print();

    std::cout.rdbuf(old);
    EXPECT_EQ(buffer.str(), "( )\n");
}

// ============================================================================
// Main function
// ============================================================================

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
