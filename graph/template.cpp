#include <bits/stdc++.h>
using namespace std;

// Last updated 2020-05-09
template<typename T>
struct edge {
    int source, to;
    T cost;

    edge(int source, int to, T cost) : source(source), to(to), cost(cost) {}
    edge(int to, T cost) : source(-1), to(to), cost(cost) {}

    edge &operator=(const int &vertex) {
        to = vertex;
        return *this;
    }

    operator int() const { return to; }
};

template<typename T>
struct UnWeightedGraph {
    vector<vector<edge<T>>> data;
    bool is_directed_graph;

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