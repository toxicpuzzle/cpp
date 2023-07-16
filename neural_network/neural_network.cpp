#include <stdlib.h>
#include <vector>
#include <tuple>
#include <limits>
#include <unordered_map>

class Perceptron;
class Edge;

class Edge
{
    float weight{};
    Perceptron &from;
    Perceptron &to;

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

    Perceptron &getFrom() const
    {
        return from;
    }

    Perceptron &getTo() const
    {
        return to;
    }

    int getWeightedActivation() const
    {
        return from.getOutput() * weight;
    }

    int getWeight() const
    {
        return weight;
    }

    void setWeight(float weight)
    {
        this->weight = weight;
    }

    /**
     * Performs back prop update using next layer deltas
     */
    float updateWeight()
    {
        float weightChange = this->from.getLearningRate() * this->to.getDelta() * this->from.getOutput();
        this->weight = this->weight + weightChange;

        // Get next layer deltas
        // Compute own update constant
        // Update self
        // Propogate own delta backwards (for efficiency)
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
public:
    const TransferFunc &transferApply;
    std::vector<Edge> inEdges{{}}; // need edges as single neuron could be connected via many weights to other neurons
    std::vector<Edge> outEdges{{}};
    float targetValue; // Only applies if the neuron is input or output neuron
    float bias{};
    float learningRate{};
    bool resultComputed{false}; // internal flag to determine if neuron has been updated on the current iteration. OR use hashmap?
    static int globalId;
    int id;
    // Cache for output, delta, nd net? or maybe just make perceptron a dataclass and shift layer/layer work to neural network class so iteration can be used?
    // So each neuron just stores what else it is connected to e.g. for CNN purposes we can modify this?
    //! Why implementation to choose?
    // Go with iteration for now, but keep the existing functions in perceptron
    // forward pass - update outputs layer by layer to get final target output
    // backward pass - compute delta for last layer, then update weights in prev, delta in penult e.t.c.
    Type type{HIDDEN};

public:
    // https://stackoverflow.com/questions/11422070/c-abstract-class-parameter-error-workaround
    Perceptron(const TransferFunc &transferfunc,                          //! You can only pass abstract class by reference, not by value because by value creates copy of instance of base class, and abstract classes cannot be directly instantiated
               std::vector<Edge> &inEdges, float learningRate, Type type) //& to ensure we get reference to original not copy
        : transferApply{transferfunc}, inEdges{inEdges}, learningRate{learningRate}, type{type}
    {
        this->id = globalId++;
    }

    Perceptron(const TransferFunc &transferfunc) : transferApply{transferfunc} {};

    void setInEdges(std::vector<Edge> &inEdges)
    {
        this->inEdges = inEdges;
    }

    // Returns net weight input of neurons: includes bias
    float getNet() const
    {
        float total{0};
        for (Edge e : inEdges)
        {
            //! You cannot call the function of an object with const keyword (i.e. immutable) unless that function is const too!
            // Syntax -> add const at end
            total += e.getWeightedActivation();
        }
        return total + this->bias;
    }

    // Oi = f(net i) for neuron i i.e. total activation
    float getOutput() const
    {
        if (this->type == INPUT)
            return this->targetValue; // i.e. input neurons never get incorrect target values;
        return this->transferApply.getActivation(this->getNet());
    }

    // Varies depending on is output -> maybe have subclass?
    // Could also use strategy pattern as well, but let's just do enum hack for now for simplicity
    float getDelta() const
    {
        // output -> (target - actual)*deriv(net input to current)
        if (this->type == OUTPUT)
        {
            return (targetValue - getOutput()) * transferApply.getDerivative(getOutput());
            // hidden -> (sum over all next layer neurons())
        }
        else
        {
            int result{};
            for (Edge e : outEdges)
            {
                result += e.getWeight() + e.getTo().getDelta();
            }
            result = result * transferApply.getDerivative(this->getNet());
        }
    }

    // inline ensures we can avoid extra call stack layer
    inline float getLearningRate() const
    {
        return this->learningRate;
    }

    void updateBias()
    {
        this->bias = this->bias - learningRate * this->getDelta();
    }

    float updateTargetVal(float target)
    {
        this->targetValue = target;
    }

    std::vector<Edge> &getInEdges()
    {
        return this->inEdges;
    }

    std::vector<Edge> &getOutEdges()
    {
        return this->inEdges;
    }

    bool operator==(Perceptron &other)
    {
        return this->id == other.id;
    }

    int getId() const
    {
        return this->id;
    }
};

int Perceptron::globalId = 0;

// Specialisation of the std::hash template i.e. overrides parent implementation of hash specifically for perceptrons
template <>
struct std::hash<Perceptron>
{
    std::size_t operator()(Perceptron const &s) const noexcept
    {
        auto getIntHash = std::hash<int>{};
        return getIntHash(s.getId()); // or use boost::hash_combine (see Discussion) https://en.cppreference.com/w/Talk:cpp/utility/hash
    }
};

class PerceptronInputLayer : public Perceptron
{
    int input{0};
    // NB: IF you want to define subclass constructor then you need to call parent class constructor too!
    // PerceptronInputLayer(int input = 0) : input{input} {}

    float get_output()
    {
        return input;
    }
};

class NeuralNetwork
{

    struct Result
    {
        float delta;
        float net;
        Result(float delta, float net) : delta{delta}, net{net} {};
    };

    std::vector<std::vector<Perceptron>> layers;
    std::unordered_map<Perceptron, Result> results;

public:
    NeuralNetwork(std::vector<int> layerDims, float learningRate) : layers{}
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
                layer.push_back(Perceptron{RELUTransfer{}, previousLayerEdges, learningRate, Perceptron::Type::HIDDEN});
            }
            layers.push_back(layer);
            previousLayer = layer; // copies layer's values into previous layer (not reference moving).
        }
    }

    // Update the outputs of each layer using iteration (i.e. don't use recursion as that is slower)
    std::unordered_map<Perceptron, float> forwardPass(std::vector<float> inputData)
    {
        // std::vector<int> lastLayerOutputs{static_cast<int>(inputData.size()), 0};
        std::unordered_map<Perceptron, float> lastLayerOutputs{};
        for (int i = 0; i < layers[0].size(); i++)
        {
            lastLayerOutputs[layers[0][i]] = inputData[i];
            results[layers[0][i]] = Result{0, inputData[i]};
        }

        std::unordered_map<Perceptron, float> currLayerOutputs{};
        for (int i = 1; i < layers.size(); i++)
        {
            int result = 0;
            for (int j = 0; j < layers[i].size(); j++)
            {
                std::vector<Edge> &edges = layers[i][j].getInEdges();
                for (Edge e : edges)
                {
                    result += e.getWeight() * lastLayerOutputs[e.getFrom()];
                }
                currLayerOutputs[layers[i][j]] = result;
                results[layers[i][j]] = Result{0, result};
            }
            lastLayerOutputs = currLayerOutputs;
            currLayerOutputs.clear();
        }

        // CurrLayerOutputs at this point should be the outputs of the final layer
        // Compute average error
        return currLayerOutputs;
    }

    // Trains neural network on single example for exactly one iteration
    void trainSingle(std::vector<float> inputData, std::vector<float> outputData)
    {
        // Update deltas for all neurons
        auto outputLayerResult = forwardPass(inputData);
        int layerFromRight = 0;
        for (std::vector<Perceptron> &layer : layers)
        {
            if (layerFromRight = layers.size() - 1)
                break; // input layer does not have in edges

            int nodeNumInLayer = 0;
            for (Perceptron &curr : layer)
            {
                float netForFrom = 0;
                for (Edge &par : curr.getInEdges())
                {
                    float parActivation = par.getFrom().transferApply.getActivation(results[par.getFrom()].net);
                    float fromActivation = curr.transferApply.getActivation(results[curr].net);
                    netForFrom += par.getWeight() * parActivation;
                    if (layerFromRight == 0)
                    {
                        // NB: This assumes that the loss function for the output layer just takes one input (else you need to MSE over errors);
                        // For batch training - you need MSE, i.e. do feedforward for all input-target pairs, calcualte 1/M * 1/2 (sum(target - actual)^2) which diffs to 1/M(sum(target-actual)) i.e. just the mean for this current calculation
                        results[curr].delta = curr.transferApply.getDerivative(netForFrom) * (outputData[nodeNumInLayer] - fromActivation);
                    }
                    else
                    {
                        // Calculate weighted activation
                        float weightedDelta{};
                        for (Edge out : curr.getOutEdges())
                        {
                            weightedDelta += out.getWeight() * results[out.getTo()].delta;
                        }
                        results[curr].delta = curr.transferApply.getDerivative(netForFrom) * weightedDelta;
                    }
                }
                nodeNumInLayer++;
            }
            layerFromRight++;
        }

        // Update weights based on deltas
        for (std::vector<Perceptron> &layer : layers)
        {
            for (Perceptron &curr : layer)
            {
                for (Edge &par : curr.getInEdges())
                {
                    float fromOutput = par.getFrom().transferApply.getActivation(results[par.getFrom()].net);
                    float fromDelta = results[par.getFrom()].delta;
                    float learningRate = par.getFrom().getLearningRate();
                    float weightChange = learningRate * fromOutput * fromDelta;
                    par.setWeight(par.getWeight() + weightChange);
                }
            }
        }
    }

    // Returns the mean loss for every perceptron for n data points.
    float getMeanLoss(std::vector<std::vector<float>> inputData, std::vector<std::vector<float>> outputData){
        auto results = forwardPass(inputData[0]);
        std::unordered_map<Perceptron, float> returnVal{};
        for (int i = 0; i < inputData.size(); ++i){
            auto passResults = forwardPass(inputData[i]);
            for (int j = 0; j < layers[layers.size()-1].size(); j++){
                Perceptron key = layers[layers.size() - 1][i];
                returnVal[key] += passResults[key];
            }
        }
        // Average out the loss using structured binding.
        for (auto& [key, value]: returnVal){
            returnVal[key] = returnVal[key] / outputData.size();
        }
    }

    // void trainSingle(std::vector<std::vector<int>> inputData, ){
    //     for (int i = 0; i < inputData.size(); ++i){
    //         trainSingle()
    //     }
    // }

    void trainBatch(std::vector<std::vector<int>> inputData, std::vector<std::vector<int>> outputData)
    {
        // Use recursion to calculate?
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
// For test set - use the XOR problem i.e. just 2 input neurons, and one output, use 1 desirable for truth, and 0 for false