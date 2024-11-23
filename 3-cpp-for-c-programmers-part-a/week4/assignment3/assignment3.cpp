#include <iostream>

#include "graph.cpp"
#include "prims.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
    // Create graph and add edges
    Graph g("data/sample_data.txt");

    // Print the graph
    cout << "Graph: " << endl;
    cout << g << endl;

    // Run Prim's and print the MST
    Prims prims(g);
    prims.print_mst();
    cout << "Cost: " << prims.get_mst_cost() << endl;

    return 0;
}
