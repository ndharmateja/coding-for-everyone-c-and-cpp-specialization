#include <iostream>
#include <utility>
#include <vector>
#include <limits>

using namespace std;

// Reference: https://www.geeksforgeeks.org/how-to-assign-negative-infinity-in-cpp/
const double POSITIVE_INFINITY = numeric_limits<double>::infinity();

class Graph
{
private:
    vector<vector<double>> list;
    void initialize_list(int n)
    {
        for (int i = 0; i < n; i++)
        {
            vector<double> neighbours(n);
            for (int j = 0; j < n; j++)
                neighbours[j] = 0.0;

            this->list.push_back(neighbours);
        }
    }

public:
    Graph(int n) { initialize_list(n); }
    Graph(const Graph &g) { this->list = vector<vector<double>>(g.list); }

    int get_num_vertices() const { return this->list.size(); }
    int get_num_edges()
    {
        int edges = 0;
        for (int i = 0; i < list.size(); i++)
            for (int j = 0; j < list.size(); j++)
                if (list[i][j] > 0.0)
                    edges++;
        return edges;
    }

    bool is_adjacent(int u, int v) const { return list[u][v] > 0.0; }
    vector<int> get_neighbours(int u) const
    {
        vector<int> neighbours;
        for (int i = 0; i < list.size(); i++)
            if (is_adjacent(u, i))
                neighbours.push_back(i);
        return neighbours;
    }

    void add_edge(int u, int v, double weight) { this->list[u][v] = weight; }
    void delete_edge(int u, int v) { this->list[u][v] = 0.0; }

    double get_edge_weight(int u, int v) const { return this->list[u][v]; }
};

class Edge
{
public:
    const int from;
    const int to;
    Edge(int from, int to) : from(from), to(to) {}
};

class Prims
{
private:
    Graph graph;
    int num_vertices;
    vector<double> distances;
    vector<int> prev;
    vector<bool> closed;
    vector<Edge> mst;
    int mst_weight = 0;
    int src;
    void initialize_values(int src)
    {

        // Initialize all initial distances to infinity and prev as -1
        for (int i = 0; i < num_vertices; i++)
        {
            distances.push_back(POSITIVE_INFINITY);
            prev.push_back(-1);
            closed.push_back(false);
        }

        // Distance for the src node is 0
        // And it is found initially
        distances[src] = 0;
        closed[src] = true;
    }
    // returns the node with the smallest distance which is already not found
    int find_next_node()
    {
        double min_distance = POSITIVE_INFINITY;
        int min_node = -1;
        for (int i = 0; i < num_vertices; i++)
        {
            if (!closed[i] && distances[i] < min_distance)
            {
                min_distance = distances[i];
                min_node = i;
            }
        }

        return min_node;
    }
    void compute_mst()
    {
        // Run the loop as long as all the nodes are found
        int curr_node = 0;
        while ((curr_node = find_next_node()) != -1)
        {
            // Mark node as found
            closed[curr_node] = true;
            mst.push_back(Edge(prev[curr_node], curr_node));
            mst_weight += distances[curr_node];

            // Update distances of all neighbours
            // if their new distances are less than their curr distances
            for (int neighbour : graph.get_neighbours(curr_node))
                update_neighbour_distance(curr_node, neighbour);
        }
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

public:
    Prims(Graph &graph, int src) : graph(graph), src(src)
    {
        this->num_vertices = graph.get_num_vertices();
        initialize_values(src);
        compute_mst();
    }
    // If previous node of dest is -1
    // that means no path to dest from src
    bool is_connected() { return this->mst.size() < this->num_vertices - 1; }
    double get_shortest_distance(int dest) { return distances[dest]; }
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
            cout << edge.from << "-" << edge.to << endl;
        cout << "MST cost: " << this->mst_weight << endl;
    }
};