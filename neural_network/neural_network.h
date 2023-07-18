#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H

class Perceptron{

};

class Edge{
    float weight{};
    Perceptron &from;
    Perceptron &to;
    static int globalId;
    int id;
};

#endif