#ifndef EDGE_H
#define EDGE_H

#include <functional>
#include <memory>

// Use forward declaration instead of header to avoid circular dependencies
class Perceptron;

class Edge
{
    float weight{};
    Perceptron& from;
    Perceptron& to;
    static int globalId;
    int id;

public:
    Edge(float weight, Perceptron &from, Perceptron &to);

    Perceptron &getFrom() const;

    Perceptron &getTo() const;

    float getWeightedActivation() const;

    float getWeight() const;

    void setWeight(float weight);

    /**
     * Performs back prop update using next layer deltas
     */
    float updateWeight();

    int getId() const;

    // Assignment operator =, by default does shallow copy
    Edge& operator=(const Edge& edge);
};

template <>
struct std::hash<Edge>
{
    std::size_t operator()(Edge const &s) const noexcept
    {
        auto getIntHash = std::hash<int>{};
        return getIntHash(s.getId()); // or use boost::hash_combine (see Discussion) https://en.cppreference.com/w/Talk:cpp/utility/hash
    }
};

bool operator==(const Edge first, const Edge second);

#endif