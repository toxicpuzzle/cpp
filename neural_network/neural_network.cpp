#include <stdlib.h>
#include <vector>
#include <tuple>
#include <limits>
#include <unordered_map>
#include <ranges>
#include <iostream>
#include <fstream>
#include <memory>
#include "edge.h"
#include "perceptron.h"
#include "transfer.h"
#include "own_templates.h"

// int Perceptron::globalId = 0;

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
        Result() = default;

        friend std::ostream &operator<<(std::ostream &os, const Result &result)
        {
            os << result.net;
            return os;
        }
    };

    std::vector<std::vector<Perceptron>> layers;
    std::unordered_map<Perceptron, Result> results;
    std::unordered_map<int, Perceptron *> idToPerceptron;
    std::vector<std::shared_ptr<Edge>> edges;

public:
    NeuralNetwork(std::vector<int> layerDims, float learningRate) : layers{}, edges{}
    {

        // New rewrite
        std::unordered_map<Perceptron, std::vector<std::shared_ptr<Edge>>> toEdges{};
        std::unordered_map<Perceptron, std::vector<std::shared_ptr<Edge>>> inEdges{};

        // Construct raw neurons
        for (int layerDim : layerDims)
        {
            std::vector<Perceptron> layer{};
            for (int i = 0; i < layerDim; ++i)
            {
                std::shared_ptr<TransferFunc> tmp{new SigmoidTransfer{}};
                Perceptron toInsert = Perceptron{tmp}; //! segfault from calling activation func? because RELU Transfer si alloc on stack, but perceptron takes its reference.
                toInsert.learningRate = 0.05;
                layer.push_back(toInsert);
                toEdges[toInsert] = std::vector<std::shared_ptr<Edge>>{};
                inEdges[toInsert] = std::vector<std::shared_ptr<Edge>>{};
            }
            layers.push_back(layer);
        }

        // Construct edges

        // Construct adj list then put edges in at once (don't care about efficiency)
        std::vector<Perceptron *> previousLayer{};
        std::vector<std::shared_ptr<Edge>> prevToCurrEdges{};
        for (auto &layer : layers)
        {
            // Out Edges - from prev to current layer;
            for (auto &neuron : layer)
            {
                prevToCurrEdges.clear();
                for (Perceptron *prev : previousLayer)
                {
                    std::shared_ptr<Edge> edge{new Edge{1.0, *prev, neuron}};

                    //? Creates two shared pointers to the edge so if
                    //? both neurons dealloc -> edge dealloc
                    edges.push_back(edge);
                    toEdges[*prev].push_back(edge);
                    inEdges[neuron].push_back(edge);
                }
            }

            // Current becomes previous layer
            //? previousLayer = layer won't work, as that'd copy the perceptrons
            previousLayer.clear();
            for (auto &neuron : layer)
            {
                previousLayer.push_back(&neuron);
            }
        }

        for (auto &layer : layers)
        {
            for (auto &neuron : layer)
            {
                neuron.setInEdges(inEdges[neuron]);
                neuron.setOutEdges(toEdges[neuron]);
            }
        }
    }

    void printEdges()
    {
        for (auto edge : edges)
        {
            std::cout << "w" << edge->getWeight() << " " << edge->getFrom() << "->" << edge->getTo() << "\n";
        }
    }

    // Update the outputs of each layer using iteration (i.e. don't use recursion as that is slower)
    // And returns the outputs for the last layer.
    std::unordered_map<Perceptron, float> forwardPass(std::vector<float> inputData)
    {
        // Compute the first layer's outputs (literally just inputs)
        std::unordered_map<Perceptron, float> lastLayerOutputs{};
        for (int i = 0; i < layers[0].size(); i++)
        {
            lastLayerOutputs[layers[0][i]] = inputData[i];
            results[layers[0][i]] = Result{0.0, inputData[i]};
        }

        // Compute the second layer's outputs
        std::unordered_map<Perceptron, float> currLayerOutputs{};
        for (int i = 1; i < layers.size(); i++)
        {
            float result = 0.0;
            for (int j = 0; j < layers[i].size(); j++)
            {
                std::vector<std::shared_ptr<Edge>> edges = layers[i][j].getInEdges();
                for (auto e : edges)
                {
                    result += e->getWeight() * lastLayerOutputs[e->getFrom()];
                }
                currLayerOutputs[layers[i][j]] = result;
                results[layers[i][j]] = Result{0.0, result};
            }
            lastLayerOutputs = currLayerOutputs;
            currLayerOutputs.clear();
        }

        // lastLayerOuptuts at this point should be the outputs of the final layer
        // Compute average error
        return lastLayerOutputs;
    }

    // Adds the delta update needed for neuron using single inputData/OutputData pair
    // Adds to delta the current training pair
    void updateDeltas(std::vector<float> inputData, std::vector<float> outputData)
    {
        auto outputLayerResult = forwardPass(inputData);
        // Calculate net input for every
        for (int layerFromRight = 0; layerFromRight < layers.size() - 1; layerFromRight++)
        {
            int nodeNumInLayer = 0;
            std::vector<Perceptron> layer = layers[layers.size() - layerFromRight - 1];
            for (Perceptron &curr : layer)
            {
                float currDeriv = curr.transferApply->getDerivative(results[curr].net);
                if (layerFromRight == 0)
                {
                    // NB: This assumes that the loss function for the output layer just takes one input (else you need to MSE over errors);
                    // For batch training - you need MSE, i.e. do feedforward for all input-target pairs, calcualte 1/M * 1/2 (sum(target - actual)^2) which diffs to 1/M(sum(target-actual)) i.e. just the mean for this current calculation
                    float outputDiff = outputData[nodeNumInLayer] - outputLayerResult[curr];
                    results[curr].delta = currDeriv * outputDiff; //! assumes that edges are in order i.e. 1st in prev to 1st in next, then 1st in prev to 2nd in next...
                }
                else
                {
                    float dotWAndDelta = 0;
                    for (auto outEdge : curr.getOutEdges())
                    {
                        dotWAndDelta += outEdge->getWeight() * results[outEdge->getTo()].delta;
                    }
                    results[curr].delta = currDeriv * dotWAndDelta;
                }
                nodeNumInLayer++;
            }
        }
    }

    void applyToDeltas(float (*apply)(float))
    {
        for (auto &[key, value] : this->results)
        {
            value.delta = apply(value.delta);
        }
    }

    void clearDeltas()
    {
        applyToDeltas([](float delta)
                      { return (float)0.0; });
    }

    std::unordered_map<Edge, float> getWeightUpdate(std::vector<float> inputData, std::vector<float> outputData)
    {
        std::unordered_map<Edge, float> weightChanges{};
        for (int layerFromRight = 0; layerFromRight < layers.size() - 1; layerFromRight++)
        {
            std::vector<Perceptron> layer = layers[layers.size() - layerFromRight - 1];
            for (Perceptron &curr : layer)
            {
                for (auto par : curr.getInEdges())
                {
                    float fromOutput = par->getFrom().transferApply->getActivation(results[par->getFrom()].net);
                    float toDelta = results[par->getTo()].delta; //! To Delta not from (else at input->next layer weights would have 0 delta always as input neurons have 0 delta?)
                    float learningRate = par->getFrom().getLearningRate();
                    float weightChange = learningRate * fromOutput * toDelta;
                    weightChanges[*par] = weightChange;
                }
            }
        }
        return weightChanges;
    }

    // Gets weight change for neural network neural network on single example for exactly one iteration
    /**
     * Used for SGD i.e. trains one example at a time (better for large datasets where taking one batch step can be very long)
     *
     */
    void trainSingle(std::vector<float> inputData, std::vector<float> outputData)
    {
        // Update deltas for all neurons
        updateDeltas(inputData, outputData);

        // Update weights based on deltas
        std::unordered_map<Edge, float> changes = getWeightUpdate(inputData, outputData);
        for (std::vector<Perceptron> &layer : layers)
        {
            for (Perceptron &curr : layer)
            {
                for (auto par : curr.getInEdges())
                {
                    float weightChange = changes[*par];
                    par->setWeight(par->getWeight() + weightChange);
                }
            }
        }

        // clearDeltas();
    }

    // Returns the mean loss for every perceptron for n data points.
private:
    std::unordered_map<Perceptron, float>
    getMeanLoss(std::vector<std::vector<float>> inputData, std::vector<std::vector<float>> outputData)
    {
        // auto results = forwardPass(inputData[0]);
        std::unordered_map<Perceptron, float> returnVal{};
        for (int i = 0; i < inputData.size(); ++i)
        {
            auto passResults = forwardPass(inputData[i]);
            // Adds the last layer outputs to returnVal for current inputData pass
            for (int j = 0; j < layers[layers.size() - 1].size(); j++)
            {
                Perceptron key = layers[layers.size() - 1][j];
                returnVal[key] += passResults[key]; //! account for target value
            }
        }
        // Average out the loss using structured binding.
        for (auto &[key, value] : returnVal)
        {
            returnVal[key] = returnVal[key] / outputData.size();
        }
        return returnVal;
    }

public:
    // void trainSingle(std::vector<std::vector<int>> inputData, ){
    //     for (int i = 0; i < inputData.size(); ++i){
    //         trainSingle()
    //     }
    // }
    /**
     * Performs weight update after feedforward has been done for all input/output data pairs
     * but weights are still accumulated with each inputData sample and then averaged for update.
     * https://stats.stackexchange.com/questions/436802/neural-network-batch-training
     * We take the average of the gradients of all the training examples and then use that
     * mean gradient to update our parameters. So that’s just one step of gradient descent in one epoch.
     * https://towardsdatascience.com/batch-mini-batch-stochastic-gradient-descent-7a62ecba642a
     */
    void trainBatch(std::vector<std::vector<float>> inputData, std::vector<std::vector<float>> outputData)
    {
        // Update deltas for all neurons
        std::unordered_map<Edge, float> totalChanges{};
        for (int i = 0; i < inputData.size(); i++)
        {
            std::vector<float> input = inputData[i];
            std::vector<float> output = outputData[i];

            updateDeltas(input, output);
            std::unordered_map<Edge, float> changes = getWeightUpdate(input, output);
            for (auto [edge, wc] : changes)
            {
                totalChanges[edge] += wc;
            }
        }

        for (auto [edge, wc] : totalChanges)
        {
            totalChanges[edge] = wc / (inputData.size());
        }

        // Update weights based on deltas
        for (std::vector<Perceptron> &layer : layers)
        {
            for (Perceptron &curr : layer)
            {
                for (auto par : curr.getInEdges())
                {
                    float weightChange = totalChanges[*par];
                    par->setWeight(par->getWeight() + weightChange);
                }
            }
        }
    }

    /**
     * Train SGD - trains the NN using SGD method i.e. weight adj done per training sample
     */
    float trainSGD(std::vector<std::vector<float>> inputData, std::vector<std::vector<float>> outputData, int epochs)
    {
        // Use recursion to calculate?
        for (int epoch = 0; epoch < epochs; epoch++)
        {
            for (int i = 0; i < inputData.size(); i++)
            {
                trainSingle(inputData[i], outputData[i]);
            }
            std::cout << "Epoch " << epoch << " results\n";
            printEdges();

        }
        return 0;
    }

    float predict(std::vector<std::vector<float>> inputData, std::vector<std::vector<float>> outputData)
    {
        auto loss = getMeanLoss(inputData, outputData);
        float result = 0;
        for (auto a : loss)
        {
            result += a.second;
        }
        return result / loss.size();
    }

    //! first paramter of instance method (member function) is calling (this) object, so either overload as friend or free function
    // operator<< is either overloaded as friend function (wi.e. does not take the member method), or outside of class (recommeded);
    friend std::ostream &operator<<(std::ostream &os, const NeuralNetwork &n)
    {
        os << "I'm a neural network!\n";
        return os;
    }
};

// std::vector<std::vector<float>
struct Data
{
    std::vector<float> inputData;
    std::vector<float> outputData;

    friend std::ostream &operator<<(std::ostream &os, Data &d)
    {
        os << "Input: ";
        printVector(d.inputData);
        os << "output: ";
        printVector(d.outputData);
        return os;
    }
};

std::vector<float> getLineAsVec(std::string line)
{
    int pos{0};
    line = line + " ";
    std::string splitDelim = " ";
    std::vector<float> vec{};
    while (true)
    {
        int nextDelim = line.find(splitDelim, pos);

        // .size() includes null byte
        if (nextDelim == std::string::npos || pos == line.size() - 1)
            break;

        std::string value = line.substr(pos, nextDelim);
        vec.push_back(std::stof(value));
        pos = nextDelim + 1;
    }
    return vec;
}

std::vector<Data> readData()
{
    std::vector<Data> results{};
    Data d{};
    std::ifstream file("xor.txt");
    std::string line;
    bool isInput{true};
    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            std::vector<float> result = getLineAsVec(line);
            // std::vector<float> &toInsert = isInput ? d.inputData : d.outputData;
            // toInsert.insert(toInsert.end(), result.begin(), result.end());
            // printVector(toInsert);
            if (!isInput)
            {
                d.outputData = result;
                results.push_back(d);
            }
            else
            {
                d.inputData = result;
            }
            isInput = !isInput;
        }
        file.close();
    }
    return results;
}

int main()
{
    NeuralNetwork n{std::vector{2, 3, 1}, 3};
    std::vector<Data> d = readData();

    printVector(d);
    // std::vector<NeuralNetwork> v = std::vector{n};
    // printVector(v); // print vector works once you've overloaded the << method to work with &ostream.

    std::vector<std::vector<float>> input{};
    std::vector<std::vector<float>> output{};
    for (Data ds : d)
    {
        input.push_back(ds.inputData);
        output.push_back(ds.outputData);
    }
    std::cout << "finished vectorising\n";

    std::cout << "Results without training " << n.predict(input, output) << "\n";
    n.trainSGD(input, output, 2500); // why does error go up after 100 epochs
    //! Problem - stops training i.e. no deltas after the first iteration
    //! Deltas are 0 because derivative becomes 0 with relu when input is negative (so how does relu train if it's f'(netq) is 0.
    //! known as dying relu problem - when you initialise weights to 0 and use RELU on hidden layers.
    std::cout << "Results after training " << n.predict(input, output) << "\n";
    std::cout << "hello world\n";
    return 0;
}

// TODO
// Way to accept input data in input layer, expected output in output layer
// After NN works starts fitting onto data i.e. you can see in command line that training loss decreases over time
// Try visualising the training process (allow stepping through epochs) e.g. using rayliblike this
// Maybe implement matrix multiplication first to avoid huge amount of loops?
// https://playground.tensorflow.org/#activation=relu&regularization=L2&batchSize=10&dataset=circle&regDataset=reg-plane&learningRate=0.1&regularizationRate=0&noise=0&networkShape=8,7,6&seed=0.54712&showTestData=false&discretize=false&percTrainData=50&x=true&y=true&xTimesY=false&xSquared=true&ySquared=false&cosX=false&sinX=false&cosY=false&sinY=false&collectStats=false&problem=classification&initZero=false&hideText=false
// For test set - use the XOR problem i.e. just 2 input neurons, and one output, use 1 desirable for truth, and 0 for false