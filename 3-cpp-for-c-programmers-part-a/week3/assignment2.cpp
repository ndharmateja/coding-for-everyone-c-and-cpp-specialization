#include <iostream>

using namespace std;

class Graph
{
private:
    int n;
    vector<vector<int>> list;

public:
    Graph(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            this->list.push_back(temp);
        }
    }

    vector<int> get_neighbours(int v) const
    {
        return this->list[v];
    }

    int get_num_vertices() const { return this->n; }

    void add_edge(int u, int v)
    {
        this->list[u].push_back(v);
    }
};

ostream &operator<<(ostream &out, const Graph &graph)
{
    for (int i = 0; i < graph.get_num_vertices(); i++)
    {
        vector<int> neighbours = graph.get_neighbours(i);
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

int main(int argc, char const *argv[])
{
    Graph g(4);

    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(2, 1);

    cout << "Graph: " << endl;
    cout << g;

    return 0;
}
