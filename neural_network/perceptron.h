
// Perceptron will be incomplete type at this point i.e. need to declare member vars/functions for other sto use
// follow pattern of having definition of class (not its member functions) in header, then definition of functions in cpp file.
#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <vector>
#include <functional>
#include "transfer.h"
#include "edge.h"

class Edge;
class TransferFunc;


class Perceptron
{
public:
    enum Type
    {
        INPUT,
        HIDDEN,
        OUTPUT
    };

public:

    using Edgeptr = std::shared_ptr<Edge>;
    const TransferFunc &transferApply;   // if reference i.e. const pointer to non-const data, cannot use default constructor, must do member list initialisation or do inline here? and also override assignment(move operator)
    std::vector<Edgeptr> inEdges{{}}; // need edges as single neuron could be connected via many weights to other neurons
    std::vector<Edgeptr> outEdges{{}};
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
    Perceptron(const TransferFunc &transferfunc,                                 //! You can only pass abstract class by reference, not by value because by value creates copy of instance of base class, and abstract classes cannot be directly instantiated
               std::vector<Edgeptr> &inEdges, std::vector<Edgeptr> &outEdges, float learningRate, Type type); //& to ensure we get reference to original not copy

    Perceptron(const TransferFunc &transferfunc);

    //! Must be a copy of ptrs because if vector is declared inside constructor then it could get deallocated
    void setInEdges(std::vector<Edgeptr> inEdges);

    void setOutEdges(std::vector<Edgeptr> inEdges);

    float getNet() const;

    float getOutput() const;

    float getDelta() const;

    float getLearningRate() const;

    void updateBias();

    void updateTargetVal(float target);

    std::vector<Edgeptr> getInEdges();

    std::vector<Edgeptr> getOutEdges();

    bool operator==(Perceptron &other);

    int getId() const;

    Perceptron &operator=(const Perceptron &other);

};

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

bool operator==(const Perceptron first, const Perceptron second);

#endif