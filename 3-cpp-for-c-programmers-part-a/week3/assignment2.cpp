#include <iostream>
#include <utility>
#include <vector>
#include <limits>

using namespace std;

// Reference: https://www.geeksforgeeks.org/how-to-assign-negative-infinity-in-cpp/
const double POSITIVE_INFINITY = numeric_limits<double>::infinity();

class WeightedEdge
{
private:
    int from;
    int to;
    double weight;

public:
    WeightedEdge(int from, int to, double weight)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
    int get_from() const { return this->from; }
    int get_to() const { return this->to; }
    double get_weight() const { return this->weight; }
};

ostream &operator<<(ostream &out, const WeightedEdge &edge)
{
    out << "edge(" << edge.get_from() << "->" << edge.get_to() << ", " << edge.get_weight() << ")";
    return out;
}

class Graph
{
private:
    int n;
    vector<vector<WeightedEdge>> list;

public:
    Graph(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            vector<WeightedEdge> neighbours;
            this->list.push_back(neighbours);
        }
    }

    vector<WeightedEdge> get_neighbours(int v) const { return list[v]; }
    int get_num_vertices() const { return this->n; }
    void add_edge(int from, int to, double weight) { this->list[from].push_back(WeightedEdge(from, to, weight)); }
};

ostream &operator<<(ostream &out, const Graph &graph)
{
    for (int i = 0; i < graph.get_num_vertices(); i++)
    {
        vector<WeightedEdge> neighbours = graph.get_neighbours(i);
        int num_neighbours = neighbours.size();
        out << i << ": { ";
        for (int j = 0; j < num_neighbours; j++)
        {
            out << neighbours[j];
            if (j != num_neighbours - 1)
                out << ", ";
        }
        out << " }" << endl;
    }

    return out;
}

void initialize_values(int src, int num_vertices, vector<double> &distances, vector<int> &prev, vector<bool> &found)
{

    // Initialize all initial distances to infinity and prev as -1
    for (int i = 0; i < num_vertices; i++)
    {
        distances[i] = POSITIVE_INFINITY;
        prev[i] = -1;
        found[i] = false;
    }

    // Distance for the src node is 0
    distances[src] = 0;
    found[src] = true;
}

void construct_path(int dest, vector<int> &prev, vector<int> &path)
{
    int curr = dest;
    while (curr != -1)
    {
        path.push_back(curr);
        curr = prev[curr];
    }
}

void print_path(vector<int> &path, double distance)
{
    cout << "Shortest path: ";
    while (path.size() > 1)
    {
        cout << path[path.size() - 1] << " -> ";
        path.pop_back();
    }
    cout << path[path.size() - 1] << endl;
    cout << "Distance: " << distance << endl;
}

// returns the node with the smallest distance which is already not found
int find_next_node(vector<double> &distances, vector<bool> &found)
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

void update_neighbour_distance(int curr_node, WeightedEdge &edge, vector<double> &distances, vector<int> &prev)
{
    int neighbour = edge.get_to();
    if (distances[curr_node] + edge.get_weight() < distances[neighbour])
    {
        distances[neighbour] = distances[curr_node] + edge.get_weight();
        prev[neighbour] = curr_node;
    }
}

void dijkstras(const Graph &graph, int src, int dest)
{
    // Initialize values
    int num_vertices = graph.get_num_vertices();
    vector<double> distances(num_vertices);
    vector<int> prev(num_vertices);
    vector<bool> found(num_vertices);
    initialize_values(src, num_vertices, distances, prev, found);

    // Run the loop as long as all the nodes are found
    int curr_node = 0;
    while (curr_node != -1)
    {
        // Mark node as found
        found[curr_node] = true;

        // Update distances of all neighbours
        // if their new distances are less than their curr distances
        for (WeightedEdge neighbour_edge : graph.get_neighbours(curr_node))
            update_neighbour_distance(curr_node, neighbour_edge, distances, prev);

        // Update curr node
        curr_node = find_next_node(distances, found);
    }

    // If previous node of dest is -1
    // that means no path to dest from src
    if (prev[dest] == -1)
    {
        cout << "No path between " << src << " & " << dest << " in the graph." << endl;
        return;
    }

    // Print the shortest path
    vector<int> path;
    construct_path(dest, prev, path);
    print_path(path, distances[dest]);
}

int main(int argc, char const *argv[])
{
    // Create graph and add edges
    Graph g(5);
    g.add_edge(0, 1, 10);
    g.add_edge(0, 2, 3);
    g.add_edge(1, 2, 1.0);
    g.add_edge(2, 1, 4.0);
    g.add_edge(1, 3, 2.0);
    g.add_edge(2, 4, 2.0);
    g.add_edge(2, 3, 8.0);
    g.add_edge(2, 3, 8.0);
    g.add_edge(3, 4, 7.0);
    g.add_edge(4, 3, 9.0);

    // Print the graph
    cout << "Graph: " << endl;
    cout << g << endl;

    // Dijkstra's
    dijkstras(g, 0, 4);

    return 0;
}
