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

class TransferFunc
{
public:
    TransferFunc() = default;
    virtual float getActivation(float x) const = 0; //? >=1 unoverriden Makes Transfer Func abstract class i.e. virtual ~= abstract
    virtual float getDerivative(float x) const = 0;
};

class RELUTransfer : public TransferFunc
{
    float getActivation(float input) const
    {
        if (input <= 0)
            return 0;
        return input;
    }

    float getDerivative(float input) const
    {
        if (input <= 0)
            return 0;
        return 1;
    }
};

class Perceptron
{
public:
    enum Type
    {
        INPUT,
        HIDDEN,
        OUTPUT
    };

private:
    // Members are private by default
    const TransferFunc &transferApply;
    std::vector<Edge> inEdges{{}};
    float targetValue; // Only applies if the neuron is output neuron
    Type type{HIDDEN};

public:
    // https://stackoverflow.com/questions/11422070/c-abstract-class-parameter-error-workaround
    Perceptron(const TransferFunc &transferfunc,            //! You can only pass abstract class by reference, not by value because by value creates copy of instance of base class, and abstract classes cannot be directly instantiated
               std::vector<Edge> &inEdges, Type type) //& to ensure we get reference to original not copy
        : transferApply{transferfunc}, inEdges{inEdges}, type{type}
    {
    }

    Perceptron(const TransferFunc &transferfunc) : transferApply{transferfunc} {};

    void setInEdges(std::vector<Edge> &inEdges)
    {
        this->inEdges = inEdges;
    }

    // Oi = f(net i) for neuron i i.e. total activation
    float getOutput()
    {
        float total{0};
        for (Edge e : inEdges)
        {
            //! You cannot call the function of an object with const keyword (i.e. immutable) unless that function is const too!
            // Syntax -> add const at end
            total += transferApply.getActivation(e.getWeightedActivation());
        }
        return total;
    }

    // Varies depending on is output -> maybe have subclass?
    // Could also use strategy pattern as well, but let's just do enum hack for now for simplicity
    float get_delta()
    {
        // output -> (target - actual)*deriv(net input to current)
        if (this->type == OUTPUT)
        {
            return (targetValue - getOutput()) * transferApply.getDerivative(getOutput());
        }
        // hidden -> (sum over all next layer neurons())
    }

    /**
     * Performs back prop update using next layer deltas
     */
    float update_weight()
    {
        // Get next layer deltas
        // Compute own update constant
        // Update self
        // Propogate own delta backwards
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
                //? cppdefault - copy is passed, & in PARAM, not in ARGS makes it so that reference is provided

                // Create neuron linked to previous layer's neurons
                std::vector<Edge> previousLayerEdges{};
                RELUTransfer transferfunc = RELUTransfer{};
                Perceptron neuron{transferfunc};
                for (Perceptron p : previousLayer)
                {
                    previousLayerEdges.push_back(Edge{1, p, neuron});
                }
                // ! anonymous objects i.e. Perceptron{RELUTransfer{}} the relutransfer object is temp and does not have a reference! so must assign to var before passing it
                // ! cannot bind tmp rvalue to non-const lvalue reference (but can for const lvalue reference as we do here)
                layer.push_back(Perceptron{RELUTransfer{}, previousLayerEdges, Perceptron::Type::HIDDEN});
            }
            layers.push_back(layer);
            previousLayer = layer; // copies layer's values into previous layer (not reference moving).
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