#ifndef DIJKSTRAS_H
#define DIJKSTRAS_H

#include "graph.cpp"

using namespace std;

// Reference: https://www.geeksforgeeks.org/how-to-assign-negative-infinity-in-cpp/
const double POSITIVE_INFINITY = numeric_limits<double>::infinity();

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
    void initialize_values(int src)
    {

        // Initialize all initial distances to infinity and prev as -1
        for (int i = 0; i < num_vertices; i++)
        {
            distances.push_back(POSITIVE_INFINITY);
            prev.push_back(-1);
            found.push_back(false);
        }

        // Distance for the src node is 0
        // And it is found initially
        distances[src] = 0;
        prev[src] = src;
    }
    // returns the node with the smallest distance which is already not found
    int find_next_node()
    {
        int num_vertices = distances.size();
        double min_distance = POSITIVE_INFINITY;
        int min_node = -1;
        for (int i = 0; i < num_vertices; i++)
        {
            if (!found[i] && distances[i] < min_distance)
            {
                min_distance = distances[i];
                min_node = i;
            }
        }

        return min_node;
    }
    void compute_shortest_path()
    {
        // Run the loop as long as all the nodes are found
        int curr_node = 0;
        while ((curr_node = find_next_node()) != -1)
        {
            // Mark node as found
            found[curr_node] = true;

            // Update distances of all neighbours
            // if their new distances are less than their curr distances
            for (int neighbour : graph.get_neighbours(curr_node))
                update_neighbour_distance(curr_node, neighbour);
        }

        // Construct the shortest path
        construct_path();
    }
    void update_neighbour_distance(int curr_node, int neighbour)
    {
        double edge_weight = this->graph.get_edge_weight(curr_node, neighbour);
        if (distances[curr_node] + edge_weight < distances[neighbour])
        {
            distances[neighbour] = distances[curr_node] + edge_weight;
            prev[neighbour] = curr_node;
        }
    }
    void construct_path()
    {
        int curr_node = dest;
        int prev_node = prev[curr_node];
        while (curr_node != prev_node)
        {
            path.push_back(curr_node);
            curr_node = prev_node;
            prev_node = prev[curr_node];
        }
        path.push_back(curr_node);
    }

public:
    Dijkstras(Graph &graph, int src, int dest) : graph(graph), src(src), dest(dest)
    {
        this->num_vertices = graph.get_num_vertices();
        initialize_values(src);
        compute_shortest_path();
    }
    void print_shortest_path()
    {
        // If previous node of dest is -1
        // that means no path to dest from src
        if (prev[dest] == -1)
        {
            cout << "No path between " << src << " & " << dest << " in the graph." << endl;
            return;
        }

        // Print the shortest path
        cout << "Shortest path from " << src << " to " << dest << ": ";
        while (path.size() > 1)
        {
            cout << path[path.size() - 1] << " -> ";
            path.pop_back();
        }
        cout << path[path.size() - 1] << endl;
        cout << "Distance: " << distances[dest] << endl;
    }
};

#endif