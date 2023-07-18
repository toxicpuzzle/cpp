#include <vector>
#include <functional>
#include "perceptron.h"
#include "edge.h"

// https://stackoverflow.com/questions/11422070/c-abstract-class-parameter-error-workaround
Perceptron::Perceptron(const TransferFunc &transferfunc,                          //! You can only pass abstract class by reference, not by value because by value creates copy of instance of base class, and abstract classes cannot be directly instantiated
                       std::vector<Edge> &inEdges, float learningRate, Type type) //& to ensure we get reference to original not copy
    : transferApply{transferfunc}, inEdges{inEdges}, learningRate{learningRate}, type{type}
{
    this->id = globalId++;
}

Perceptron::Perceptron(const TransferFunc &transferfunc) : transferApply{transferfunc} {};

void Perceptron::setInEdges(std::vector<Edge> &inEdges)
{
    this->inEdges = inEdges;
}

// Returns net weight input of neurons: includes bias
float Perceptron::getNet() const
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
float Perceptron::getOutput() const
{
    if (this->type == INPUT)
        return this->targetValue; // i.e. input neurons never get incorrect target values;
    return this->transferApply.getActivation(this->getNet());
}

// Varies depending on is output -> maybe have subclass?
// Could also use strategy pattern as well, but let's just do enum hack for now for simplicity
float Perceptron::getDelta() const
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
        return result;
    }
}

// inline ensures we can avoid extra call stack layer
float Perceptron::getLearningRate() const
{
    return this->learningRate;
}

void Perceptron::updateBias()
{
    this->bias = this->bias - learningRate * this->getDelta();
}

void Perceptron::updateTargetVal(float target)
{
    this->targetValue = target;
}

std::vector<Edge>& Perceptron::getInEdges()
{
    return this->inEdges;
}

std::vector<Edge>& Perceptron::getOutEdges()
{
    return this->inEdges;
}

int Perceptron::getId() const
{
    return this->id;
}

bool operator==(const Perceptron first, const Perceptron second){
    return first.id == second.id;
}

Perceptron& Perceptron::operator=(const Perceptron& other){
    this->id = other.id;
    return *this;
}

int Perceptron::globalId = 0;