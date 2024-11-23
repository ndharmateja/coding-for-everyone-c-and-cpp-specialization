#ifndef EDGE_H
#define EDGE_H

#include <iostream>

using namespace std;

class Edge
{
    friend ostream &operator<<(ostream &out, const Edge &graph);

public:
    const int from;
    const int to;
    Edge(int from, int to) : from(from), to(to) {}
};

ostream &operator<<(ostream &out, const Edge &edge)
{
    out << edge.from << "->" << edge.to;
    return out;
}

#endif