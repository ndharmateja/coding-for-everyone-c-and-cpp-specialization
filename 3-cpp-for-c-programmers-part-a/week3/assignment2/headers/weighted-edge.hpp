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
    WeightedEdge(int from, int to, double weight);
    int get_from() const;
    int get_to() const;
    double get_weight() const;
};

ostream &operator<<(ostream &out, const WeightedEdge &edge);

#endif