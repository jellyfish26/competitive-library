#pragma once
#include <cstddef>
#include <vector>

// Last Update 2021-02-19
template<typename T>
class Edge {
public:
    int src, to;
    T cost;

    Edge(int src, int to, T cost);
    Edge(int to, T cost);
    Edge(const Edge &target);

    Edge &operator=(const int &vt);

    operator int() const { return to; }
};

template<typename T>
Edge<T>::Edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

template<typename T>
Edge<T>::Edge(int to, T cost) : src(-1), to(to), cost(cost) {}

template<typename T>
Edge<T>::Edge(const Edge<T> &target) : src(target.src), to(target.to), cost(target.cost) {}

template<typename T>
class WeightedGraph {
protected:
    std::vector<std::vector<Edge<T>>> graph;
    const bool is_directed;

public:
    WeightedGraph(std::size_t size, bool is_directed);
    WeightedGraph(const WeightedGraph<T> &target);
    
    void add_edge(int src, int to, T cost);

    const std::vector<Edge<T>> &operator[](std::size_t index) const;
    std::size_t size() const;
};

template<typename T>
WeightedGraph<T>::WeightedGraph(std::size_t size, bool is_directed) : graph(size), is_directed(is_directed) {}

template<typename T>
WeightedGraph<T>::WeightedGraph(const WeightedGraph<T> &target) : graph(target.graph), is_directed(target.is_directed) {}

template<typename T>
void WeightedGraph<T>::add_edge(int src, int to, T cost) {
    graph[src].emplace_back(src, to, cost);
    if (!is_directed) {
        graph[to].emplace_back(to, src, cost);
    }
}

template<typename T>
const std::vector<Edge<T>> &WeightedGraph<T>::operator[](std::size_t index) const{
    return graph[index];
}

template<typename T>
std::size_t WeightedGraph<T>::size() const {
    return graph.size();
}