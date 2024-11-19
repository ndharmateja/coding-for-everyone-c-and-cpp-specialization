#ifndef WEIGHTED_EDGE_H
#define WEIGHTED_EDGE_H

#include <iostream>

using namespace std;

class WeightedEdge
{
private:
public:
    const int from;
    const int to;
    const double weight;
    WeightedEdge(int from, int to, double weight) : from(from), to(to), weight(weight) {}
};

#endif