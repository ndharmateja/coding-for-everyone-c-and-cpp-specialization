#ifndef WEIGHTED_EDGE_H
#define WEIGHTED_EDGE_H

#include <iostream>

using namespace std;

class WeightedEdge
{
private:
    int from;
    int to;
    double weight;

public:
    WeightedEdge(int from, int to, double weight) : from(from), to(to), weight(weight) {}
    int get_from() const { return this->from; }
    int get_to() const { return this->to; }
    double get_weight() const { return this->weight; }
};

#endif