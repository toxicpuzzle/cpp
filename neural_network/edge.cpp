#include "neural_network.h"
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