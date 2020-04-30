#include <bits/stdc++.h>
using namespace std;

// Last updated 2020-4-30
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

    operator int() const { return arrow.second; }
};

template<typename T>
struct UnWeightedGraph {
    bool is_directed_graph;
    vector<vector<edge<T>>> data;
    explicit UnWeightedGraph(size_t size, bool is_directed_graph) : data(size), is_directed_graph(is_directed_graph) {}

    void add_edge(int source, int to) {
        data[source].emplace_back(to, 0);
        if (!is_directed_graph) data[to].emplace_back(source, 0);
    }

    vector<edge<T>> &operator[] (const size_t index) { return data[index]; }

    const size_t size() const { return data.size(); }
};

template<typename T>
struct WeightedGraph : UnWeightedGraph<T> {
    explicit WeightedGraph(size_t size, bool is_directed_graph) : UnWeightedGraph<T>(size, is_directed_graph) {}

    void add_edge(int source, int to, T cost) {
        UnWeightedGraph<T>::operator[](source).emplace_back(to, cost);
        if (!UnWeightedGraph<T>::is_directed_graph) UnWeightedGraph<T>::operator[](to).emplace_back(source, cost);
    }
};