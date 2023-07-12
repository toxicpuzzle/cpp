#include <stdlib.h>
#include <vector>
#include <tuple>

class Perceptron;
class Edge;

class Edge
{
    float weight{};
    Perceptron from;
    Perceptron to;

public:
    // Cannot fail to have default constructor - i.e. no params, or params all have default values

    Edge(float weight, Perceptron &from, Perceptron &to) : weight{weight},
                                                           from{from},
                                                           to{to} {};

    // Edge(float weight){
    //     this(weight); // Cannot do direct delegation of constructors like in java
    // }

    // Use default constructor to reset to initial state
    // void reset(){
    //     *this = Edge();
    // }

    void update_weight(int *toLayerErrors)
    {
    }

    int getWeightedActivation()
    {
        return from.get_output() * weight;
    }
};

class Perceptron
{
    // Members are private by default
    float (*transfer_apply)(float);
    std::vector<Edge> inEdges{{}};
    bool isOutput{};

public:
    Perceptron(float (*transfer_apply)(float),
               std::vector<Edge> &inEdges, bool isOutput=false) //& to ensure we get reference to original not copy
        : transfer_apply{transfer_apply}, inEdges{inEdges}, isOutput{isOutput}
    {
    }

    Perceptron(float (*transfer_apply)(float)) : transfer_apply{transfer_apply} {};

    void setInEdges(std::vector<Edge> &inEdges)
    {
        this->inEdges = inEdges;
    }

    float get_output()
    {
        float total{0};
        for (Edge e : inEdges)
        {
            total += transfer_apply(e.getWeightedActivation());
        }
        return total;
    }

    float update_weight()
    {
        for (Edge e :)
    }
};

class PerceptronInputLayer : Perceptron
{
    int input{0};

    PerceptronInputLayer(int input = 0) : input{input} {}

    float get_output()
    {
        return input;
    }
};

float relu_activation(float input)
{
    if (input <= 0)
        return 0;
    return input;
}

float relu_activation_deriv(float input){
    if (input <= 0)
        return 0;
    return 1;
}

class NeuralNetwork
{
    std::vector<std::vector<Perceptron>> layers;

public:
    NeuralNetwork(std::vector<int> layerDims) : layers{}
    {
        //! You still need to include the header decl for std datastructs
        std::vector<Perceptron> previousLayer{};
        for (int layerDim : layerDims)
        {
            std::vector<Perceptron> layer{};
            for (int i = 0; i < layerDim; i++)
            {
                //? cdefault - copy is passed, & in PARAM, not in ARGS makes it so that reference is provided

                // Create neuron linked to previous layer's neurons
                std::vector<Edge> previousLayerEdges{};
                Perceptron neuron{relu_activation};
                for (Perceptron p : previousLayer)
                {
                    previousLayerEdges.push_back(Edge{1, p, neuron});
                }
                layer.push_back(Perceptron{relu_activation, previousLayerEdges});
            }
            previousLayer = layer;
        }
    }

    void train(int **inputData, int **outputData, int samples, int inputDim, int outputDim)
    {
        
    }

    int *predict(int *inputData)
    {
    }
};

int main()
{

    return 0;
}

// TODO
// Way to accept input data in input layer, expected output in output layer
// After NN works starts fitting onto data i.e. you can see in command line that training loss decreases over time
// Try visualising the training process (allow stepping through epochs) e.g. using rayliblike this
// Maybe implement matrix multiplication first to avoid huge amount of loops?
// https://playground.tensorflow.org/#activation=relu&regularization=L2&batchSize=10&dataset=circle&regDataset=reg-plane&learningRate=0.1&regularizationRate=0&noise=0&networkShape=8,7,6&seed=0.54712&showTestData=false&discretize=false&percTrainData=50&x=true&y=true&xTimesY=false&xSquared=true&ySquared=false&cosX=false&sinX=false&cosY=false&sinY=false&collectStats=false&problem=classification&initZero=false&hideText=false