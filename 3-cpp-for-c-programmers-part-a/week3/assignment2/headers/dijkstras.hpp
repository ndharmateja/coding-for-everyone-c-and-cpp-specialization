#ifndef DIJKSTRAS_H
#define DIJKSTRAS_H

#include "graph.hpp"

using namespace std;

class Dijkstras
{
private:
    Graph graph;
    int num_vertices;
    vector<double> distances;
    vector<int> prev;
    vector<bool> found;
    int src;
    int dest;
    vector<int> path;
    void initialize_values(int src);
    // returns the node with the smallest distance which is already not found
    int find_next_node();
    void compute_shortest_path();
    void update_neighbour_distance(int curr_node, WeightedEdge &edge);
    void construct_path();

public:
    Dijkstras(Graph &graph, int src, int dest);
    void print_shortest_path();
};

#endif