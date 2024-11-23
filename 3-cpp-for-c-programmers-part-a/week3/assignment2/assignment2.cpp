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

void run_with_density(Graph &g, double density)
{
    // Run Dijkstra's and print the shortest path for given density
    cout << "Running with " << density * 100 << "% density" << endl;
    g.generate_random_graph(density);
    Dijkstras d(g, 0);
    d.print_shortest_paths();
    cout << "Average shortest path length: " << d.get_average_shortest_path_length() << endl;
    cout << endl;
}

int main(int argc, char const *argv[])
{
    // Create graph and add edges
    Graph g1(50);

    // Run Dijkstra's and print the shortest path for 20% density
    run_with_density(g1, 0.2);

    // Run Dijkstra's and print the shortest path for 40% density
    run_with_density(g1, 0.4);

    return 0;
}
