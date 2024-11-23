#ifndef PRIMS_H
#define PRIMS_H

#include <iostream>
#include "graph.cpp"
#include "edge.cpp"

using namespace std;

// Reference: https://www.geeksforgeeks.org/how-to-assign-negative-infinity-in-cpp/
const double POSITIVE_INFINITY = numeric_limits<double>::infinity();

class Prims
{
private:
    Graph graph;
    vector<double> distances;
    vector<int> prev;
    vector<bool> closed;
    vector<Edge> mst;
    double mst_weight = 0;
    void initialize_values()
    {

        // Initialize all initial distances to infinity and prev as -1
        for (int i = 0; i < graph.get_num_vertices(); i++)
        {
            distances.push_back(POSITIVE_INFINITY);
            prev.push_back(-1);
            closed.push_back(false);
        }
    }
    // returns the node with the smallest distance which is already not found
    int find_next_node()
    {
        double min_distance = POSITIVE_INFINITY;
        int min_node = -1;
        for (int i = 0; i < graph.get_num_vertices(); i++)
            if (!closed[i] && distances[i] < min_distance)
            {
                min_distance = distances[i];
                min_node = i;
            }

        return min_node;
    }
    void compute_mst()
    {
        // Run the loop as long as all the nodes are found
        int src = 0;
        int curr_node = src;
        do
        {
            closed[curr_node] = true;
            if (curr_node != src)
            {
                mst.push_back(Edge(prev[curr_node], curr_node));
                mst_weight += distances[curr_node];
            }

            // Update distances of all neighbours
            // if their new distances are less than their curr distances
            for (int neighbour : graph.get_neighbours(curr_node))
                if (!closed[neighbour])
                    update_neighbour_distance(curr_node, neighbour);
        } while ((curr_node = find_next_node()) != -1);
    }
    void update_neighbour_distance(int curr_node, int neighbour)
    {
        double edge_weight = this->graph.get_edge_weight(curr_node, neighbour);
        if (edge_weight < distances[neighbour])
        {
            distances[neighbour] = edge_weight;
            prev[neighbour] = curr_node;
        }
    }
    // If number of edges in mst is equal to n-1
    // then the graph is connected and therefore has an MST
    // (where 'n' is the number of vertices in the graph)
    bool is_connected() { return this->mst.size() == graph.get_num_vertices() - 1; }

public:
    Prims(Graph &graph) : graph(graph)
    {
        initialize_values();
        compute_mst();
    }
    void print_mst()
    {
        if (!is_connected())
        {
            cout << "No MST in the graph." << endl;
            return;
        }

        // Print edges in MST
        cout << "Edges in MST:" << endl;
        for (Edge edge : mst)
            cout << edge << endl;
    }
    double get_mst_cost() { return this->mst_weight; }
};

#endif