#include <stdlib.h>
#include <vector>

using namespace std;

class Edge{
    float weight;
    Perceptron from;
    Perceptron to;
    public:
        // Cannot fail to have default constructor - i.e. no params, or params all have default values
        Edge(float weight = 1, Perceptron from = nullptr, Perceptron to = nullptr){
            this->from = from;
            this->to = to;
            this->weight = weight;
        };

        // Edge(float weight){
        //     this(weight); // Cannot do direct delegation of constructors like in java
        // }

        //  This uses the default constructor above to set things up
        Edge(int weight): Edge{weight, nullptr, nullptr} {
            *this = Edge(); // but you can kind of do delegation of constructors in java like this?
        }
};

class Perceptron
{
    // Members are private by default
    float (*transfer_apply)(float);
    std::vector<Edge> weights{{}};

public:
    Perceptron(float (*transfer_apply)(float) = nullptr)
    {
        this->transfer_apply = transfer_apply;
    }
};

class NeuralNetwork
{
};

int main()
{

    return 0;
}