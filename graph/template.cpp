#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct edge {
    pair<int, int> arrow;
    T cost;

    edge(int source, int to, T cost) : arrow(source, to), cost(cost) {}
    edge(int to, T cost) : arrow(-1, to), cost(cost) {}

    edge &operator=(const int &vertex) {
        arrow.second = vertex;
        return *this;
    }
};

template<typename T>
struct WeightedGraph : vector<vector<edge<T>>> {
    bool is_directed_graph;
    explicit WeightedGraph(int size, bool is_directed_graph) : vector<vector<edge<T>>>(size), is_directed_graph(is_directed_graph) {}

    void add_edge(int source, int to, T cost) {
        vector<vector<edge<T>>>::operator[](source).emplace_back(to, cost);
        if (!is_directed_graph) vector<vector<edge<T>>>::operator[](to).emplace_back(source, cost);
    }
};

template<typename T>
struct UnWeightedGraph : vector<vector<int>> {
    bool is_directed_graph;
    explicit UnWeightedGraph(int size, bool is_directed_graph) : vector<vector<int>>(size), is_directed_graph(is_directed_graph) {}

    void add_edge(int source, int to) {
        vector<vector<int>>::operator[](source).push_back(to);
        if (!is_directed_graph) vector<vector<int>>::operator[](to).push_back(source);
    }
};