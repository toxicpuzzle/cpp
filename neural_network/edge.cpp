#include "edge.h"
#include "perceptron.h"

Edge::Edge(float weight, Perceptron &from, Perceptron &to) : weight{weight}, from{from}, to{to} {
    this->id = globalId++;
}

Perceptron &Edge::getFrom() const
{
    return from;
}

Perceptron &Edge::getTo() const
{
    return to;
}

float Edge::getWeightedActivation() const
{
    return from.getOutput() * weight;
}

float Edge::getWeight() const
{
    return weight;
}

void Edge::setWeight(float weight)
{
    this->weight = weight;
}

float Edge::updateWeight()
{
    float weightChange = this->from.getLearningRate() * this->to.getDelta() * this->from.getOutput();
    this->weight = this->weight + weightChange;
    return 0.0;
}

int Edge::getId() const
{
    return id;
}

bool operator==(const Edge first, const Edge second)
{
    return first.getId() == second.getId();
}

Edge &Edge::operator=(const Edge &edge)
{
    weight = edge.weight;
    id = edge.id;
    return *this;
}
int Edge::globalId = 0;
