#include <iostream>

#include "graph.cpp"
#include "prims.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    // Create graph and add edges
    int num_vertices = 4;
    Graph g(num_vertices);
    g.add_edge(0, 1, 1);
    g.add_edge(0, 2, 7);
    g.add_edge(1, 0, 1);
    g.add_edge(1, 3, 2);
    g.add_edge(2, 0, 7);
    g.add_edge(2, 3, 3);
    g.add_edge(3, 1, 2);
    g.add_edge(3, 2, 3);

    // Print the graph
    cout << "Graphhh: " << endl;
    cout << g << endl;

    // Run Prim's and print the MST
    Prims prims(g);
    cout << "MST cost: " << prims.get_mst_cost() << endl;
    prims.print_mst();

    return 0;
}
