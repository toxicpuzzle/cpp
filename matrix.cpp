#include <vector>
#include <iostream>
#include <cassert>

class Matrix{
    // TODO: Create copy constructor properly so that new matrix has duplciate stdvecs i.e. Matrix(const Matrix& other); override the default version.
    // https://www.youtube.com/watch?v=ehMg6zvXuMY&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=89
    // Create move constructor as well so you don't need to do Matrix{{},{},{}} and the r-value on call is linked to the l-value w/o copying through function calls.
    std::vector<std::vector<int>> matrix{};
    int rows{};
    int cols{};

public:
    Matrix(int rows, int cols){
        for (int i = 0; i < rows; i++){
            matrix.push_back(std::vector<int>{});
        }

        for (std::vector<int>& vec: matrix){
            for (int i = 0; i < cols; i++){
                vec.push_back(0);
            }
        }
        this->rows = rows;
        this->cols = cols;
    }

    Matrix(int* values, int rows, int cols){
        for (int i = 0; i < rows; i++){
            matrix.push_back(std::vector<int>{});
        }

        for (int i = 0; i < rows; i++){
            // https://stackoverflow.com/questions/49938999/stdvector-at-does-it-return-a-reference-or-a-copy
            std::vector<int>& vec = matrix[i]; //! need to provide & to indicate you want reference ret rather than copy initialise it from the returned reference
            for (int j = 0; j < cols; j++){
                //! CPP stores 2d arrays as continguous block so doing *(*(values + i) + j) won't work as 2d array !+ array of pointers -> use int* instead of int**
                //! values[i][j] also won't work as pointer int* as by itself values contains no information about the width of rows
                vec.push_back(*(values + i*cols + j));
            }
        }
        this->rows = rows;
        this->cols = cols;
    }

    Matrix applyOnAll(Matrix other, int (*function)(int, int)){
        Matrix result{rows, cols};
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                result.matrix[i][j] = function(matrix[i][j], other.matrix[i][j]);
            }
        }
        return result;
    }

    Matrix add(Matrix other){
        // Lambda function - lambda ret type [](params){ lambda function body ...}
        assert((this->rows == other.rows && this->cols == other.cols));
        return applyOnAll(other, [](int a, int b){return a + b;});
    }

    Matrix sub(Matrix other){
        assert((this->rows == other.rows && this->cols == other.cols));
        return applyOnAll(other, [](int a, int b){return a - b;});
    }

    Matrix dot(Matrix other){
        // Assumes self is left, i.e. other's rows must equal self's cols
        assert((this->cols == other.rows));
        Matrix result{rows, other.cols};
        // Draw diagram out to clarify order of looping
        for (int k = 0; k < other.cols; k++){
            for (int i = 0; i < this->rows; i++){
                for (int j = 0; j < this->cols; j++){
                    result.matrix[i][k] += this->matrix[i][j]*other.matrix[j][k];
                }
            }
        }
        return result;
    }
    
    void print(){
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                std::cout << matrix[i][j];
                if (j < cols) std::cout << ",";
            }
            std::cout << "\n";
        }
    }

};

int main(){
    int first[2][2]{{2,3},{1,5}};
    int second[2][3]{{3,1,2},{6,2,7}};

    for (int i = 0; i < 2; i++){
        for (int j =0; j < 2; j++){
            std::cout << &first[i][j] << "\n";
        }
    }

    Matrix m_first = Matrix{(int*)first, 2, 2};
    Matrix m_second = Matrix{(int*)second, 2, 3};

    m_first.print();
    std::cout << "-------\n";
    m_second.print();
    m_first.dot(m_second).print();
    m_first.add(m_first).add(m_first).print();
    m_first.sub(m_first).sub(m_first).print();

}