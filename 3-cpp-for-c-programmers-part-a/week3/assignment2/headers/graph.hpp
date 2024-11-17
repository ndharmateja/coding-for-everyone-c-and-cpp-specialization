#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include "weighted-edge.hpp"

using namespace std;

class Graph
{
private:
    int n;
    vector< vector<WeightedEdge> > list;

public:
    Graph(int n);
    Graph();

    vector<WeightedEdge> get_neighbours(int v) const;
    int get_num_vertices() const;
    void add_edge(int from, int to, double weight);
};

ostream &operator<<(ostream &out, const Graph &graph);

#endif