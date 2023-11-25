#include "matrix.hpp"
#include "assert.h"
#include "math.h"
#include <set>

std::vector<float>& Matrix::operator[](int row){
    return m_values[row];
}

/**
 * Applies element wise operation, e.g. for adding, subtracting, dividing, multiplying
*/
Matrix Matrix::broadcast(Matrix a, Matrix b, std::function<float(float, float)> func){
    assert(a.dims() == b.dims());
    auto [h, w] = a.dims(); // must use auto for structured bindings
    Matrix result{h, w};

    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            result[i][j] = func(a[i][j], b[i][j]);
        }
    }

    return result;
}

/**
* Swaps rows/columns of matrix
*/
Matrix Matrix::transpose(){
    auto [h, w] = m_dims; 
    Matrix result{w, h};

    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            result[j][i] = m_values[i][j];
        }
    }

    return result;
}

/**
 * TODO
 * Returns the dot product of two matrices
*/
Matrix Matrix::dot_product(Matrix a, Matrix b){
    assert(a.dims().second == b.dims().first); // Same inner dim
    auto [h, w] = a.dims(); // must use auto for structured bindings
    Matrix result{h, w};

    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            for (int k = 0; k < w; k++){
                result[i][j] = a[i][k] + b[k][j];
            }            
        }
    }

    return result;
}

/**
 * TODO
 * Computes Trace for square matrices
*/
float Matrix::trace(){
    assert(m_dims.first == m_dims.second);
    auto [h, w] = m_dims;
    int delta[2] = {1,1};
    int curr_coord[2] = {0,0};
    float result{0};

    while (curr_coord[0] < m_dims.first && curr_coord[1] < m_dims.second){
        result += m_values[curr_coord[0]][curr_coord[1]];
        curr_coord[0] += delta[0];
        curr_coord[1] += delta[1];
    }

    return result;
}

/**
 * Returns if matrix is row or column vector
*/
bool Matrix::isVector(){
    return m_dims.first == 1 || m_dims.second == 1;
}

bool Matrix::isSquare(){
    return m_dims.first == m_dims.second;
}

/**
 * TODO
 * Returns the l_x norm of the matrix, using element wise squaring
*/
float Matrix::norm(int l_x){
    auto [h,w] = m_dims;
    Matrix placeholder{h, w};
    
    Matrix powered = broadcast(*this, placeholder, [l_x](float a, float b){
        return static_cast<float>(pow(a, static_cast<float>(l_x)));
    });

    // Sum over powered using sum vectors
    Matrix sum_col = Matrix{w, 1, 1};
    Matrix sum_row = Matrix{1, h, 1};
    auto total_over_cols = Matrix::dot_product(powered, sum_col);
    auto total_over_all = Matrix::dot_product(sum_row, total_over_cols);

    assert(total_over_all.dims().first == 1 &&
            total_over_all.dims().second == 1);
    return total_over_all[0][0];
}

/**
 * TODO
 * Factorial time implementation of brute force determinant expansion
 * More efficient implementation would invovle getting matrix to ref form first
*/
std::optional<float> Matrix::determinant(){
    assert(this->isSquare());
    float result{};
    auto [h, w] = m_dims;

    for (int i = 0; i < h; i++){
        // Construct new matrix from eliminating row and col

        // Add the matrix's deteriminant
        bool is_positive = i%2 == 0;
        

    }

    return result;
}

/**
 * Returns Matrix in Row Echelon Form;
*/
Matrix LASolve::ref(Matrix a, Executor* executor){
    // Implement row_swaps, row wise * operationsf
    auto comp = [](const RowKey& lhs, const RowKey& rhs){
        if (lhs.leading_from_right != rhs.leading_from_right) 
            return lhs.leading_from_right < rhs.leading_from_right;
        return lhs.non_zeroes < rhs.non_zeroes;
    };
    std::multiset<RowKey, std::function<bool(RowKey,RowKey)>> rowKeys{};

    // Calculate RowKey for each row at the start.
    for (int i = 0; i < a.dims().first; i++){
        // Count number of non zeroes
        int non_zeroes = 0;
        int leading_from_right = 0;

        for (int j = a.dims().second-1; j >=0; j--){
            if (a[i][j] != 0) {
                non_zeroes += 1;
                leading_from_right = j;
            }
        }

        rowKeys.insert(RowKey{non_zeroes, leading_from_right, i});
    }

    while (rowKeys.size() > 0){
        auto key = rowKeys.end();
        // TODO 
    }

    // O(N^3logn) implementation
    // PQ of rows - highest left mostt leading 1s first, then by the number of leading ones
    // Rank(row) = index from right of left most leading 1
    // Pop from pq - ls - pop all that have same rank(row)
    //               remove leading 1 overlaps with all rows in ls, put rows in ls back in ls.
    //               add current row to result row
    //               STOP when no more left to pop/ if leading 0s, fill rest of results wiht leading 0s.
    // Could improve efficiency via bucket sort?

    // Start with first row, have common leading 1s
    return Matrix{1,1};
}

Matrix LASolve::rref(Matrix a, Executor* executor){ 
    Matrix ref = LASolve::ref(a);
    // O(N^3) implementation
    // PQ of rows in reverse rank(Row) order
    // Make current row leading coeff a one by mult_row
    // Remove extraneous columns by iterating through previous processed rows.
    return ref;
}

Matrix LASolve::inverse(Matrix a, Executor* executor){
    // Some way to syc operations on both matrices e.g. using wrappers around swap_Row, mult_row ...
    // Or replace the swap/mult operations by adding them to a list. (command pattern)
        // Separate out from matrix, create objects for add row, swap


}