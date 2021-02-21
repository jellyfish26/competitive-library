#pragma once
#include <cstddef>
#include <functional>
#include <vector>

// Last Update 2021-02-21
template<typename T, class DP>
class ReRooting {
protected:
    struct Edge {
        const int to;
        T data;

        Edge(int to, T data);
    };

    const std::size_t tree_size;
    std::vector<std::vector<ReRooting::Edge>> graph;
    std::vector<std::vector<DP>> normal_dp, left_dp, right_dp;
    std::vector<DP> ans_dp;

    const std::function<DP(DP, DP)> merge;
    const std::function<DP(DP, T)> raising;
    const DP identity_element;

    DP dfs_normal(int now_vtx, int before_vtx = -1);
    void dfs_after(int now_vtx, int before_vtx, DP partial);
public:
    ReRooting(std::size_t size, std::function<DP(DP, DP)> merge, function<DP(DP, T)> raising, DP identity_element);

    void add_edge(int src, int to, T data);
    void build();

    const DP &operator[](const std::size_t idx) const;
};

template<typename T, class DP>
ReRooting<T, DP>::Edge::Edge(int to, T data) : to(to), data(data) {}

template<typename T, class DP>
DP ReRooting<T, DP>::dfs_normal(int now_vtx, int before_vtx) {
    const std::vector<ReRooting::Edge> &now_edges = graph[now_vtx];
    std::vector<DP> &now_normal_dp = normal_dp[now_vtx];
    now_normal_dp = std::vector<DP>(now_edges.size(), identity_element);
    DP sum = identity_element;

    for (int idx = 0; idx < (int)now_edges.size(); idx++) {
        if (now_edges[idx].to == before_vtx) {
            continue;
        }

        now_normal_dp[idx] = raising(dfs_normal(now_edges[idx].to, now_vtx), now_edges[idx].data);
        sum = merge(sum, now_normal_dp[idx]);
    }

    return sum;
}

template<typename T, class DP>
void ReRooting<T, DP>::dfs_after(int now_vtx, int before_vtx, DP partial) {
    const std::vector<ReRooting::Edge> &now_edges = graph[now_vtx];

    std::vector<DP> &now_normal_dp = normal_dp[now_vtx];
    std::vector<DP> &now_left_dp = left_dp[now_vtx];
    std::vector<DP> &now_right_dp = right_dp[now_vtx];
    now_left_dp = std::vector<DP>(now_edges.size() + 1, identity_element);
    now_right_dp = std::vector<DP>(now_edges.size() + 1, identity_element);

    for (int idx = 0; idx < (int)now_edges.size(); idx++) {
        if (now_edges[idx].to == before_vtx) {
            now_normal_dp[idx] = raising(partial, now_edges[idx].data);
        }
        now_left_dp[idx + 1] = merge(now_left_dp[idx], now_normal_dp[idx]);
    }

    for (int idx = (int)now_edges.size() - 1; idx >= 0; idx--) {
        now_right_dp[idx] = merge(now_normal_dp[idx], now_right_dp[idx + 1]);
    }

    for (int idx = 0; idx < (int)now_edges.size(); idx++) {
        if (now_edges[idx].to == before_vtx) continue;

        // Because it is a Monoid, it can be a cumulative (sum, merge).
        dfs_after(now_edges[idx].to, now_vtx, merge(now_left_dp[idx], now_right_dp[idx + 1]));
    }

    ans_dp[now_vtx] = now_right_dp[0];
}

template<typename T, class DP>
ReRooting<T, DP>::ReRooting(const std::size_t size, const std::function<DP(DP, DP)> merge, const std::function<DP(DP, T)> raising, DP identity_element)
    : tree_size(size), graph(size), normal_dp(size), left_dp(size), right_dp(size), ans_dp(size), 
    merge(merge), raising(raising), identity_element(identity_element) {}

template<typename T, class DP>
void ReRooting<T, DP>::add_edge(int src, int to, T data) {
    graph[src].emplace_back(to, data);
    graph[to].emplace_back(src, data);
}

template<typename T, class DP>
void ReRooting<T, DP>::build() {
    dfs_normal(0);
    dfs_after(0, -1, identity_element);
}

template<typename T, class DP>
const DP &ReRooting<T, DP>::operator[](const std::size_t idx) const {
    return ans_dp[idx];
}