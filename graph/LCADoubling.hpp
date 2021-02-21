#pragma once
#include <cstddef>
#include <stack>
#include <tuple>
#include <vector>

#include "Base.hpp"


// Last Update 2021-02-21
template<typename T>
class LCADoubling : public WeightedGraph<T> {
protected:
    std::vector<std::vector<int>> parent;
    std::vector<int> root_dist;
    int doubling_depth;

    void init_depth();
    void init_doubling(int root);

public:
    explicit LCADoubling(std::size_t size);
    LCADoubling(const WeightedGraph<T> &graph);

    void build(int root);

    int query(int vtx1, int vtx2) const;
};

template<typename T>
void LCADoubling<T>::init_depth() {
    doubling_depth = 1;
    std::size_t graph_size = WeightedGraph<T>::size();
    std::size_t count = 1;
    while ((count <<= 1) < graph_size) doubling_depth++;
}

template<typename T>
void LCADoubling<T>::init_doubling(int root) {
    root_dist.assign(WeightedGraph<T>::size(), 0);
    parent.assign(WeightedGraph<T>::size(), std::vector<int>(doubling_depth, -1));

    // before_vertex, now_vertex, depth from root
    // vtx = vertex
    using TP = std::tuple<int, int, int>;
    std::stack<TP> explore;
    explore.emplace(-1, root, 0);

    while (!explore.empty()) {
        int before_vtx, now_vtx, root_depth;
        tie(before_vtx, now_vtx, root_depth) = explore.top();
        explore.pop();

        parent[now_vtx][0] = before_vtx;
        root_dist[now_vtx] = root_depth;
        for (const Edge<T> &next : WeightedGraph<T>::graph[now_vtx]) {
            if (next.to != before_vtx) {
                explore.emplace(now_vtx, next.to, root_depth + 1);
            }
        }
    }
            
    // index for doubling
    for (int idx = 0; idx + 1 < doubling_depth; idx++) {
        for (int vtx = 0; vtx < (int)WeightedGraph<T>::size(); vtx++) {
            int now_parent = parent[vtx][idx];
            parent[vtx][idx + 1] = (now_parent < 0 ? -1 : parent[now_parent][idx]);
        }
    }
}

template<typename T>
LCADoubling<T>::LCADoubling(std::size_t size) : WeightedGraph<T>(size, false) {}

template<typename T>
LCADoubling<T>::LCADoubling(const WeightedGraph<T> &graph) : WeightedGraph<T>(graph) {}

template<typename T>
void LCADoubling<T>::build(int root) {
    init_depth();
    init_doubling(root);
}

template<typename T>
int LCADoubling<T>::query(int vtx1, int vtx2) const {
    if (root_dist[vtx1] < root_dist[vtx2]) std::swap(vtx1, vtx2);

    for (int idx = doubling_depth - 1; idx >= 0; idx--) {
        int diff = root_dist[vtx1] - root_dist[vtx2];
        if ((diff>>idx)&1) {
            vtx1 = parent[vtx1][idx];
        }
    }
    if (vtx1 == vtx2) return vtx1;

    for (int idx = doubling_depth - 1; idx >= 0; idx--) {
        if (parent[vtx1][idx] == parent[vtx2][idx]) continue;

        vtx1 = parent[vtx1][idx];
        vtx2 = parent[vtx2][idx];
    }
    return parent[vtx2][0];
}