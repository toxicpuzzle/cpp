#include <gtest/gtest.h>
#include "../matrix.hpp"

TEST(MatrixAttributes, isSquare){
    Matrix m{2,3};
    Matrix square{1,1};
    Matrix square2{5,5};
    ASSERT_TRUE(!m.isSquare());
    ASSERT_TRUE(square.isSquare());
    ASSERT_TRUE(square2.isSquare());
}

TEST(MatrixAttributes, equality){
    Matrix m{2,3,1};
    Matrix ne{3,4,0};
    Matrix ne_same_size{2,3,2};

    ASSERT_TRUE(!(m == ne));
    ASSERT_TRUE(!(m == ne_same_size));
    ASSERT_TRUE(m == m);
}

TEST(MatrixAttributes, dot_product){
    Matrix first{3,2};
    Matrix second{2,3};
    Matrix result{3,3};


    // Initialise first and second matrix
    first[0][0] = 1;
    first[0][1] = 2;
    first[1][0] = 2.5;
    first[1][1] = 3;
    first[2][0] = 1.5;
    first[2][1] = 2;

    // Initialise second matrix
    second[0][0] = 2;
    second[0][1] = 3;
    second[0][2] = 5;
    second[1][0] = 2.2;
    second[1][1] = 10;
    second[1][2] = 2.3;

    // Results matrix
    result[0][0] = 6.4;
    result[0][1] = 23;
    result[0][2] = 9.6;
    result[1][0] = 11.6;
    result[1][1] = 37.5;
    result[1][2] = 19.4;
    result[2][0] = 7.4;
    result[2][1] = 24.5;
    result[2][2] = 12.1;

    Matrix actual = Matrix::dot_product(first, second);
    ASSERT_TRUE(actual.isSquare() && actual == result) << actual.toString() << "\n";
}

