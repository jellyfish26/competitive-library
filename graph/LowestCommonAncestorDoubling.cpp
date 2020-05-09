#include <bits/stdc++.h>
#include "template.cpp"
using namespace std;

// Last updated 2020-05-09
template<typename T>
class LowestCommonAncestorDoubling {
private:
    UnWeightedGraph<T> &graph;
    vector<vector<int>> doubling_parent; // [v][k] = 2^k distance v's parent
    vector<int> root_distance;
    size_t doubling_depth;

    void init_depth() {
        doubling_depth = 1;
        size_t vertex_size = graph.size();
        size_t max_vertex_size = 1;
        while ((max_vertex_size <<= 1) < vertex_size) doubling_depth++;
    }

    void init_doubling(int root = 0) {
        root_distance.assign(graph.size(), 0);
        doubling_parent.assign(graph.size(), vector<int>(doubling_depth, -1));

        // dfs
        stack<tuple<int, int, int>> explore; // before_vertex, now_vertex, root distance
        explore.emplace(-1, root, 0);
        while (!explore.empty()) {
            int before_vertex, now_vertex, root_depth;
            tie(before_vertex, now_vertex, root_depth) = explore.top();
            explore.pop();
            doubling_parent[now_vertex][0] = before_vertex;
            root_distance[now_vertex] = root_depth;
            for (const edge<T> &next : graph[now_vertex]) {
                if (next.to != before_vertex) explore.emplace(now_vertex, next.to, root_depth + 1);
            }
        }

        for (int doubling_index = 0; doubling_index + 1 < doubling_depth; doubling_index++) {
            for (int vertex = 0; vertex < graph.size(); vertex++) {
                int now_doubling_parent = doubling_parent[vertex][doubling_index];
                doubling_parent[vertex][doubling_index + 1] = (now_doubling_parent < 0 ? -1 : doubling_parent[now_doubling_parent][doubling_index]);
            }
        }
    }

public:
    LowestCommonAncestorDoubling(UnWeightedGraph<T> &graph, const int root = 0) : graph(graph) {
        init_depth();
        init_doubling(root);
    }

    int query(int first_vertex, int second_vertex) {
        if (root_distance[first_vertex] < root_distance[second_vertex]) swap(first_vertex, second_vertex);
        for (int doubling_index = doubling_depth - 1; doubling_index >= 0; doubling_index--) {
            int root_distance_difference = root_distance[first_vertex] - root_distance[second_vertex];
            if ((root_distance_difference>>doubling_index) & 1) first_vertex = doubling_parent[first_vertex][doubling_index];
        }
        if (first_vertex == second_vertex) return first_vertex;
        for (int doubling_index = doubling_depth - 1; doubling_index >= 0; doubling_index--) {
            if (doubling_parent[first_vertex][doubling_index] == doubling_parent[second_vertex][doubling_index]) continue;
            first_vertex = doubling_parent[first_vertex][doubling_index];
            second_vertex = doubling_parent[second_vertex][doubling_index];
        }
        return doubling_parent[second_vertex][0];
    }
};