#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <optional>
#include <functional>

class Executor;

/**
 * Represents both matrices and vectors to be usd with
 * Vector and LASolve library
*/
class Matrix{

    std::vector<std::vector<float>> m_values;
    std::pair<int, int> m_dims; // height, width
    bool isUpperLowerDiagonal = false;
    // Strategy method to get leading 1s? nah probably subclass because +/- operations
    // need to be modified to ensure leading 1s can e.g. be calculated in O(1) time by
    // popping from stack/linked list when necessary.
    // Actually don't need to, does not change time complexity anyways as after you find
    // the leading 1 in O(1) you need still need to apply row wise op in O(n),
    // additive of the same or lower level O complexity does not affect overall TC

public:

    Matrix(int height, int width, int fill=0) : m_values{std::vector<std::vector<float>>(height)},
    m_dims{std::pair<int,int>{height, width}} {
        for (auto& row: m_values){
            row = std::vector<float>(width, fill);
        }
    }

    std::vector<float>& operator[](int row);

    bool operator==(Matrix& m) const;

    std::optional<float> determinant() const;

    float norm(int l_x) const;

    float trace() const;
    
    bool isVector() const;

    bool isSquare() const;

    Matrix transpose() const;

    std::pair<int,int> dims() const;

    static Matrix dot_product(Matrix a, Matrix b);

    static Matrix broadcast(Matrix a, Matrix b, std::function<float(float, float)>);

    static Matrix getIdentity(int height, int width);

    std::string toString() const;
};

// class LeadingOneDecorator: public Matrix{
//     Matrix 
// }

namespace Vector{
    
    Matrix dot_product(Matrix a, Matrix b);

    Matrix angle_between(Matrix a, Matrix b);

    Matrix projected_vector(Matrix from, Matrix to);
};


namespace LASolve{

    /**
     * In place row wise operations
    */
    namespace Helpers{
        Matrix& swap_row(Matrix& a, int row_a, int row_b);
        Matrix& mult_row(Matrix&a, int row_num, float multiplier);
        Matrix& add_row(Matrix& a, int row_apply, int row_use, float use_mult);
        int non_zeroes(Matrix& a, int row);
        int leading_one_idx(Matrix& a, int row); // ideally should have stack wrapper to maintain leading 1
    };

    struct RowKey{
        int non_zeroes;
        int leading_from_right;
        int row;
    };

    Matrix ref(Matrix a, Executor* executor=nullptr);

    Matrix rref(Matrix a, Executor* executor=nullptr);

    Matrix inverse(Matrix a, Executor* executor=nullptr);

    std::vector<float> eigenvals(Matrix a); // Need to create general polynomial solver for this

    std::tuple<Matrix, Matrix, Matrix> diagonalise(Matrix a);
};

// Command classes for elementary row ops
class Command{
protected:
    Matrix* m_matrix;
    float m_det;
    
public:
    Command(Matrix* m) : m_matrix{m}, m_det{-1} {};
    void setMatrix(Matrix* m) {
        m_matrix = m;
    }
    float computedDeterminant();
    virtual Matrix computeCommandMatrix() = 0;
    virtual void invoke() = 0;
};

class CommandSwapRow: public Command{
public:
    int row_a;
    int row_b;

    CommandSwapRow(Matrix* m, int row_a, int row_b) : 
        Command{m}, row_a{row_a}, row_b{row_b}{
            m_det=1;
        }

    void invoke() override{
        LASolve::Helpers::swap_row(*(this->m_matrix), row_a, row_b);
    };

    Matrix computeCommandMatrix();
};

class CommandMultRow: public Command{
public:
    int row_num;
    int multiplier;

    CommandMultRow(Matrix* m, int row_num, float ) : 
        Command{m}, row_num{row_num}, multiplier{multiplier} {
            m_det=multiplier;
        }

    void invoke() override{
        LASolve::Helpers::mult_row(*(this->m_matrix), row_num, multiplier);
    };
    Matrix computeCommandMatrix();
};

class CommandAddRow: public Command{
public:
    int row_apply;
    int row_use;
    float use_mult;

    CommandAddRow(Matrix* m, int row_apply, int row_use, float use_mult) : 
        Command{m}, row_apply{row_apply}, row_use{row_use}, use_mult{use_mult} {
            m_det=1;
        }
  
    void invoke() override{
        LASolve::Helpers::add_row(*(this->m_matrix), row_apply, row_use, use_mult);
    };
    Matrix computeCommandMatrix();

};

class Executor{
public:
    std::vector<Command*> commands{};

    void execute(Command* c){
        c->invoke();
        commands.push_back(c);
    }
};

#endif