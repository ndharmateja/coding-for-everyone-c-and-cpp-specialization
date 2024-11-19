#include <iostream>
#include "graph.cpp"
#include "dijkstras.cpp"

using namespace std;

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

    // Run Dijkstra's and print the shortest path
    Dijkstras d(g, 0);
    d.print_shortest_path(3);

    return 0;
}
