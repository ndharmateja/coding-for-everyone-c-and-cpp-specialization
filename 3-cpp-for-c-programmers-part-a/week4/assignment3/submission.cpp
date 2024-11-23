#include <iostream>
#include <fstream>
#include <iostream>

using namespace std;

// Graph class
class Graph
{
    // Friend function to print the graph
    friend ostream &operator<<(ostream &out, const Graph &graph);

private:
    // The adjacency matrix stored as a vector of vectors
    vector<vector<double>> list;

    // Initialize the matrix with 0.0 values
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
    // Constructor to initialize the graph from a file
    Graph(string filename)
    {
        ifstream f(filename);
        istream_iterator<int> start(f), end;
        vector<int> values(start, end);

        int n = values[0];
        initialize_list(n);
        for (int i = 1; i < values.size(); i += 3)
        {
            int from = values[i], to = values[i + 1];
            double weight = static_cast<double>(values[i + 2]);
            add_edge(from, to, weight);
        }
    }

    // Constructor to initialize from number of vertices
    Graph(int n) { initialize_list(n); }

    // Copy constructor
    Graph(const Graph &g) { this->list = vector<vector<double>>(g.list); }

    // Getters
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
    double get_edge_weight(int u, int v) const { return this->list[u][v]; }
    vector<int> get_neighbours(int u) const
    {
        vector<int> neighbours;
        for (int i = 0; i < list.size(); i++)
            if (is_adjacent(u, i))
                neighbours.push_back(i);
        return neighbours;
    }
    bool is_adjacent(int u, int v) const { return list[u][v] > 0.0; }

    // Add and delete edges
    void add_edge(int u, int v, double weight) { this->list[u][v] = weight; }
    void delete_edge(int u, int v) { this->list[u][v] = 0.0; }
};

// Overloading << operator to print a graph
ostream &operator<<(ostream &out, const Graph &graph)
{
    for (int i = 0; i < graph.get_num_vertices(); i++)
    {
        vector<int> neighbours = graph.get_neighbours(i);
        int num_neighbours = neighbours.size();
        out << i << ": { ";
        for (int j = 0; j < num_neighbours; j++)
        {
            int neighbour = neighbours[j];
            double edge_weight = graph.get_edge_weight(i, neighbour);
            out << "edge(" << i << "->" << neighbour << ", " << edge_weight << ")";
            if (j != num_neighbours - 1)
                out << ", ";
        }
        out << " }" << endl;
    }

    return out;
}

// Edge class to be used in the Prims class
// to store the list of edges in the MST
class Edge
{
    friend ostream &operator<<(ostream &out, const Edge &graph);

public:
    const int from;
    const int to;
    Edge(int from, int to) : from(from), to(to) {}
};

// Overloading << operator to print a edge
ostream &operator<<(ostream &out, const Edge &edge)
{
    out << edge.from << "-" << edge.to;
    return out;
}

// Reference: https://www.geeksforgeeks.org/how-to-assign-negative-infinity-in-cpp/
const double POSITIVE_INFINITY = numeric_limits<double>::infinity();

class Prims
{
private:
    // Instance variables
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

    int find_next_node()
    {
        // returns the node with the smallest distance which is already not found
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
            // Mark the node as closed
            // and add the edge to the MST and update the total weight of mst
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
    // Updates neighbour's distance if it is less than the curr distance
    // and updates its prev node as well
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
        // If graph is not connected, there is no MST
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

int main(int argc, char const *argv[])
{
    // Create graph and add edges
    Graph g("sample_data.txt");

    // Print the graph
    // cout << "Graph: " << endl;
    // cout << g << endl;

    // Run Prim's and print the MST
    Prims prims(g);
    prims.print_mst();
    cout << "Cost: " << prims.get_mst_cost() << endl;

    return 0;
}