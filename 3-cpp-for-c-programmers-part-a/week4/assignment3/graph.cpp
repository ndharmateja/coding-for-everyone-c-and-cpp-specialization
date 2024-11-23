#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <fstream>
#include <iostream>

using namespace std;

class Graph
{
    friend ostream &operator<<(ostream &out, const Graph &graph);

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

#endif