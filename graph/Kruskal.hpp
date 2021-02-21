#pragma once
#include <algorithm>
#include <cstddef>
#include <vector>

#include "Base.hpp"
#include "../datastructure/UnionFind.hpp"

// Last Update 2021-02-20
template<typename T>
class Kruskal : public WeightedGraph<T> {
protected:
    std::vector<Edge<T>> edges, used_edges;
    T cost;

public:
    explicit Kruskal(std::size_t size);
    Kruskal(const WeightedGraph<T> &graph);

    void build();

    T query() const;
    const std::vector<Edge<T>> &get_used_edges() const;
};

template<typename T>
Kruskal<T>::Kruskal(std::size_t size) : WeightedGraph<T>(size, false), edges(), used_edges() {}

template<typename T>
Kruskal<T>::Kruskal(const WeightedGraph<T> &graph) : WeightedGraph<T>(graph, false), edges(), used_edges() {}

template<typename T>
void Kruskal<T>::build() {
    for (const std::vector<Edge<T>> &vertex : WeightedGraph<T>::graph) {
        for (const Edge<T> &now : vertex) {
            edges.emplace_back(now);
        }
    }
    cost = 0;
    std::sort(edges.begin(), edges.end(), [](const Edge<T> &left, const Edge<T> &right) {
        return left.cost < right.cost;
    });
    UnionFind uf(WeightedGraph<T>::size());
    for (Edge<T> &now_edge : edges) {
        if (uf.unite(now_edge.src, now_edge.to)) {
            cost += now_edge.cost;
            used_edges.emplace_back(now_edge);
        }
    }
}

template<typename T>
T Kruskal<T>::query() const {
    return cost;
}

template<typename T>
const std::vector<Edge<T>> &Kruskal<T>::get_used_edges() const {
    return used_edges;
}
