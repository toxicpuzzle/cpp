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

public:

    Matrix(int height, int width, int fill=0) : m_values{std::vector<std::vector<float>>(height)},
    m_dims{std::pair<int,int>{height, width}} {
        for (auto& row: m_values){
            row = std::vector<float>(width, fill);
        }
    }

    std::vector<float>& operator[](int row);

    std::optional<float> determinant();

    float norm(int l_x);

    float trace();
    
    bool isVector();

    bool isSquare();

    Matrix transpose();

    std::pair<int,int> dims();

    static Matrix dot_product(Matrix a, Matrix b);

    static Matrix broadcast(Matrix a, Matrix b, std::function<float(float, float)>);
};

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

public:
    Command(Matrix* m) : m_matrix{m} {};
    void setMatrix(Matrix* m) {
        m_matrix = m;
    }
    virtual void invoke() = 0;
};

class CommandSwapRow: public Command{
public:
    int row_a;
    int row_b;

    CommandSwapRow(Matrix* m, int row_a, int row_b) : 
        Command{m}, row_a{row_a}, row_b{row_b} {}

    void invoke() override{
        LASolve::Helpers::swap_row(*(this->m_matrix), row_a, row_b);
    };
};

class CommandMultRow: public Command{
public:
    int row_num;
    int multiplier;

    CommandMultRow(Matrix* m, int row_num, float ) : 
        Command{m}, row_num{row_num}, multiplier{multiplier} {}

    void invoke() override{
        LASolve::Helpers::mult_row(*(this->m_matrix), row_num, multiplier);
    };
};

class CommandAddRow: public Command{
public:
    int row_apply;
    int row_use;
    float use_mult;

    CommandAddRow(Matrix* m, int row_apply, int row_use, float use_mult) : 
        Command{m}, row_apply{row_apply}, row_use{row_use}, use_mult{use_mult} {}
  
    void invoke() override{
        LASolve::Helpers::add_row(*(this->m_matrix), row_apply, row_use, use_mult);
    };
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