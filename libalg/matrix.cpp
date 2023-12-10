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
Matrix Matrix::transpose() const{
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
    int h = a.dims().first;
    int w = b.dims().second;
    int inner_dim = a.dims().second;
    Matrix result{h, w};

    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            for (int k = 0; k < inner_dim; k++){
                result[i][j] += a[i][k] * b[k][j];
            }            
        }
    }

    return result;
}

/**
 * TODO
 * Computes Trace for square matrices
*/
float Matrix::trace() const{
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

std::pair<int,int> Matrix::dims() const{
    return m_dims;
}

bool Matrix::isSquare() const{
    return m_dims.first == m_dims.second;
}

/**
 * Returns if matrix is row or column vector
*/
bool Matrix::isVector() const{
    return m_dims.first == 1 || m_dims.second == 1;
}

std::string Matrix::toString() const{
    std::string string;
    string += "[";
    auto [rows, cols] = this->dims();

    for (int i = 0; i < rows; i++){
        string += "[";
        for (int j = 0; j < cols; j++){
            string += std::to_string(this->m_values[i][j]);
            if (j != cols-1) string += ", ";
        }
        string += "]";
        if (i != rows-1) string += ", ";
    }

    return string;
}

/**
 * TODO
 * Returns the l_x norm of the matrix, using element wise squaring
*/
float Matrix::norm(int l_x) const{
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
 * Computes the determinant of a matrix by first reducing it to REF form which
 * is upper diagonal, then taking the product of the leading ones of each row and
 * also the determinants of elementary matrices used to obtain the REF form.
*/
std::optional<float> Matrix::determinant() const{
    assert(this->isSquare());
    float result{};
    auto [h, w] = m_dims;

    // e.g. swap_row -> no change, mult_row -> det *= multiplier, add_row -> no change
    Executor e{};
    Matrix ref_form = LASolve::ref(*this, &e); 

    // Compute multiple of diagonals
    int delta[2]{1,1};
    int coord[2]{0,0};
    result = 1;
    while (coord[0] >= ref_form.dims().first || coord[1] >= ref_form.dims().second){
        result *= ref_form[coord[0]][coord[1]];
        coord[0] += delta[0];
        coord[1] += delta[1];
    }

    for (auto& command: e.commands){
        result *= command->computedDeterminant();
    }

    return result;
}

/**
 * Returns the Identity Matrix
*/
Matrix Matrix::getIdentity(int height, int width){
    Matrix m{height, width, 0};
    int delta[2] = {1,1};
    int curr[2] = {0,0};
    while (curr[0] < height && curr[1] < width){
        m[curr[0]][curr[1]] = 1;
        curr[0] += delta[0];
        curr[1] += delta[1];
    }
    return m;
}

float Command::computedDeterminant(){
    return m_det;
}

Matrix CommandAddRow::computeCommandMatrix(){
    auto [h, w] = m_matrix->dims();
    Matrix identity = Matrix::getIdentity(h,w);
    identity[row_apply][row_use] = use_mult;
    return identity;
}

Matrix CommandMultRow::computeCommandMatrix(){
    auto [h, w] = m_matrix->dims();
    Matrix identity = Matrix::getIdentity(h,w);
    identity[row_num][row_num] *= multiplier;
    return identity;
}

Matrix CommandSwapRow::computeCommandMatrix(){
    auto [h, w] = m_matrix->dims();
    Matrix identity = Matrix::getIdentity(h,w);
    identity[row_a][row_b] = 1;
    identity[row_a][row_a] = 0;
    identity[row_b][row_a] = 1;
    identity[row_b][row_b] = 0;
    return identity;
}

/**
 * Gets the leading ones for particular row 
*/
int LASolve::Helpers::leading_one_idx(Matrix& a, int row){
    int i = 0;
    for (; a[row][i] == 0; i++);
    return i;
}

/**
 * Counts number of non zeroes in row of matrix
*/
int LASolve::Helpers::non_zeroes(Matrix& a, int row){
    int num{0};
    for (int i{0}; i < a[row].size(); i++){
        if (a[row][i] != 0) num++;
    }
    return num;
}

/** 
 * Swaps row_a and row_b of matrix a in place
*/
Matrix& LASolve::Helpers::swap_row(Matrix& a, int row_a, int row_b){
    auto temp = a[row_a];
    a[row_a] = a[row_b];
    a[row_b] = a[row_a];
    return a;
}

/**
 *  Adds use_mult*row_use to row_apply in place
*/
Matrix& LASolve::Helpers::add_row(Matrix& a, int row_apply, int row_use, float use_mult){
    for (int i = 0; i < a[row_apply].size(); i++){
        a[row_apply][i] += a[row_use][i]*use_mult;
    }
    return a;
}

/**
 * Multiplies a[row_num] by multiplier in place
*/
Matrix& LASolve::Helpers::mult_row(Matrix& a, int row_num, float multiplier){
    for (int i = 0; i < a[row_num].size(); i++){
        a[row_num][i] = a[row_num][i]*multiplier;
    }
    return a;
}

/** Matrix OPerations for LA SOlve*/

/**
 * Returns Matrix in Row Echelon Form;
*/
Matrix LASolve::ref(Matrix a, Executor* executor){
    /**
     * O(N^3logn) implementation
     * PQ of rows - highest left mostt leading 1s first, then by the number of leading ones
     * Rank(row) = index from right of left most leading 1
     * Pop from pq - ls - pop all that have same rank(row)
     *             remove leading 1 overlaps with all rows in ls, put rows in ls back in ls.
     *              add current row to result row
     *              STOP when no more left to pop/ if leading 0s, fill rest of results wiht leading 0s.
     * Could improve efficiency via bucket sort? 
    */

    // Comparator to sort in (leading_from_right, non_zeroes) from min->max
    auto comp = [](const RowKey& lhs, const RowKey& rhs) -> bool{
        if (lhs.leading_from_right != rhs.leading_from_right) 
            return lhs.leading_from_right < rhs.leading_from_right;
        return lhs.non_zeroes < rhs.non_zeroes;
    };
    auto right_offset_to_left_idx = [](const Matrix& a, const RowKey& k) -> int{
        return a.dims().second - k.leading_from_right - 1;
    };
    std::multiset<RowKey, std::function<bool(RowKey,RowKey)>> rowKeys{};
    

    while (rowKeys.size() > 0){
        // Calculate RowKey for each row at the start.
        for (int i = 0; i < a.dims().first; i++){
            int non_zeroes = Helpers::non_zeroes(a, i);
            int leading_from_right = a.dims().first-Helpers::leading_one_idx(a, i)-1;
            rowKeys.insert(RowKey{non_zeroes, leading_from_right, i});
        }

        // Get iterator containing rowKeys with same leading one coefficient.
        auto kept_row = *rowKeys.rbegin();
        rowKeys.erase(kept_row);
        auto lower = RowKey{kept_row};
        lower.non_zeroes = 0;
        auto upper = RowKey{kept_row};
        upper.non_zeroes = INT32_MAX;
        auto lower_bound = rowKeys.lower_bound(lower);
        auto upper_bound = rowKeys.lower_bound(upper);
        auto list = std::vector<RowKey>{};
        // upper_bound--; // to avoid eliminating leading 1 for kept_row
        lower_bound--; // to ensure we get last one one with same leading 1 index

        // Extract everything in between upper and lower bound
        for (auto start = upper_bound; start != lower_bound; start--)
            list.push_back(*start);
        
        // Eliminate overlapping rows
        for (auto curr = list.begin(); curr != list.end(); curr++){
            int leading_one_idx = right_offset_to_left_idx(a, *curr);
            float leading_one_val = a[curr->row][leading_one_idx];
            int kept_row_loi = right_offset_to_left_idx(a, kept_row);
            float kept_row_lov = a[kept_row.row][kept_row_loi];

            // Mutliplier add for elimination
            float mult = -1*kept_row_lov/leading_one_val;
            Helpers::add_row(a, curr->row, kept_row.row, mult);

            // Update the values 
            auto node = rowKeys.extract(*curr);
            node.value().leading_from_right = Helpers::leading_one_idx(a, node.value().row);
            node.value().leading_from_right = right_offset_to_left_idx(a, node.value());
            rowKeys.insert(std::move(node));
        }
    }

    return a;
}

/**
 * Returns the matrix in reduced row echolon form.
*/
Matrix LASolve::rref(Matrix a, Executor* executor){ 
    Matrix ref = LASolve::ref(a, executor);
    // TODO: Use the executor.
    // O(N^3) implementation
    // PQ of rows in reverse rank(Row) order
    // Make current row leading coeff a one by mult_row
    // Remove extraneous columns by iterating through previous processed rows.
    std::multiset<RowKey> rowKeys{};

    for (int row = ref.dims().first-1; row >= 0; row--){
        float leading_one_coeff = a[row][Helpers::leading_one_idx(a, row)];
        Helpers::mult_row(a, row, 1/leading_one_coeff);
        for (int done = row+1; done < ref.dims().first; done++){
            int done_loi = Helpers::leading_one_idx(a, done);
            int done_loc = a[done][done_loi];
            if (done_loc == 0) break; // for free vars, no need to eliminate
            float mult = -1*a[row][done_loi]/done_loc;
            Helpers::add_row(a, row, done, mult);
        }
    }

    return ref;
}

/**
 * Returns the inverse of the matrix if possible
*/
Matrix LASolve::inverse(Matrix a, Executor* executor){
    assert(a.isSquare() && a.determinant() != 0);
    // Or instead of calculating determinant, we can just check at end?

    // Some way to syc operations on both matrices e.g. using wrappers around swap_Row, mult_row ...
    // Or replace the swap/mult operations by adding them to a list. (command pattern)
        // Separate out from matrix, create objects for add row, swap

    return Matrix{1,1};
}

std::vector<float> eigenvals(Matrix a){
    return std::vector<float>{};
}

bool Matrix::operator==(Matrix& b) const{
    if (this->dims() != b.dims()) return false;

    auto [rows, cols] = this->dims();
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            if (this->m_values[i][j] != b[i][j]) return false;
        }
    }

    return true;
}