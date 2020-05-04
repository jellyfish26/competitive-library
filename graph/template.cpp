#include <bits/stdc++.h>
using namespace std;

// Last updated 2020-05-04
template<typename T>
struct edge {
    pair<size_t, size_t> arrow;
    T cost;

    edge(size_t source, size_t to, T cost) : arrow(source, to), cost(cost) {}
    edge(size_t to, T cost) : arrow(-1, to), cost(cost) {}

    edge &operator=(const size_t &vertex) {
        arrow.second = vertex;
        return *this;
    }

    operator size_t() const { return arrow.second; }
};

template<typename T>
struct UnWeightedGraph {
    vector<vector<edge<T>>> data;
    bool is_directed_graph;

    explicit UnWeightedGraph(size_t size, bool is_directed_graph) : data(size), is_directed_graph(is_directed_graph) {}

    void add_edge(size_t source, size_t to) {
        data[source].emplace_back(to, 0);
        if (!is_directed_graph) data[to].emplace_back(source, 0);
    }

    vector<edge<T>> &operator[] (const size_t index) { return data[index]; }

    const size_t size() const { return data.size(); }
};

template<typename T>
struct WeightedGraph : UnWeightedGraph<T> {
    explicit WeightedGraph(size_t size, bool is_directed_graph) : UnWeightedGraph<T>(size, is_directed_graph) {}

    void add_edge(size_t source, size_t to, T cost) {
        UnWeightedGraph<T>::operator[](source).emplace_back(to, cost);
        if (!UnWeightedGraph<T>::is_directed_graph) UnWeightedGraph<T>::operator[](to).emplace_back(source, cost);
    }
};