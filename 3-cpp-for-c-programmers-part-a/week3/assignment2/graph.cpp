#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <utility>
#include <vector>
#include <limits>
#include "weighted-edge.cpp"

using namespace std;

class Graph
{
private:
    vector<vector<WeightedEdge>> list;

public:
    Graph(int n)
    {
        for (int i = 0; i < n; i++)
        {
            vector<WeightedEdge> neighbours;
            this->list.push_back(neighbours);
        }
    }

    vector<WeightedEdge> get_neighbours(int v) const { return list[v]; }
    int get_num_vertices() const { return this->list.size(); }
    void add_edge(int from, int to, double weight) { this->list[from].push_back(WeightedEdge(from, to, weight)); }
};

#endif