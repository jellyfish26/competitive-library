#include <bits/stdc++.h>
#include "template.cpp"
#include "../datastructure/UnionFind.cpp"
using namespace std;

// Last updated 2020-05-11
template<typename T>
class Kruskal {
private:
    const size_t vertex_size;
    vector<edge<T>> edges, use_edges;
    T kruskal_cost;

    void convert_graph_to_edges(WeightedGraph<T> &graph) {
        for (size_t index = 0; index < graph.size(); index++) {
            for (auto &temp : graph[index]) edges.push_back(temp);
        }
    }

public:
    Kruskal(WeightedGraph<T> &graph) : vertex_size(graph.size()) {
        convert_graph_to_edges(graph);
    }

    Kruskal(vector<edge<T>> &edges, size_t vertex_size) : vertex_size(vertex_size), edges(edges) {}

    void build() {
        kruskal_cost = 0;
        sort(edges.begin(), edges.end(), [](edge<T> &left, edge<T> &right) {
            return left.cost < right.cost;
        });
        UnionFind uf(vertex_size);
        for (auto &now_edge : edges) {
            if (uf.unite(now_edge.source, now_edge.to)) {
                kruskal_cost += now_edge.cost;
                use_edges.push_back(now_edge);
            }
        }
    }

    T query() { return kruskal_cost; }

    vector<edge<T>> &get_use_edges() { return use_edges; }
};