#include <bits/stdc++.h>
using namespace std;

// Last-Updated 2020-04-30
template<typename Data, class DP>
class ReRooting {
private:
    struct edge {
        int to;
        Data data;

        edge(int to, Data data) : to(to), data(data) {}
    };

    const size_t tree_size;
    vector<vector<edge>> graph;
    vector<vector<DP>> normal_dp, left_dp, right_dp;
    vector<DP> ans_dp;
    const function<DP(DP, DP)> merge;
    const function<DP(DP, Data)> raising;
    const DP identity_element;

    // before not size_t 
    DP dfs_normal(int now_vertex, int before = -1) {
        auto &now_dp = normal_dp[now_vertex];
        now_dp = vector<DP>(graph[now_vertex].size());
        DP sum = identity_element;
        for (auto next_edge = graph[now_vertex].begin(); next_edge != graph[now_vertex].end(); next_edge++) {
            if (next_edge-> to == before) continue;
            size_t index = distance(graph[now_vertex].begin(), next_edge);
            now_dp[index] = raising(dfs_normal(next_edge->to, now_vertex), next_edge->data);
            sum = merge(sum, now_dp[index]);
        }
        return sum;
    }

    void dfs_after(int now_vertex, int before, DP partial_tree) {
        left_dp[now_vertex] = vector<DP>(graph[now_vertex].size() + 1, identity_element);
        right_dp[now_vertex] = vector<DP>(graph[now_vertex].size() + 1, identity_element);

        for (auto next_edge = graph[now_vertex].begin(); next_edge != graph[now_vertex].end(); next_edge++) {
            size_t index = distance(graph[now_vertex].begin(), next_edge);
            if (next_edge-> to == before) normal_dp[now_vertex][index] = raising(partial_tree, graph[now_vertex][index].data);
            left_dp[now_vertex][index + 1] = merge(left_dp[now_vertex][index], normal_dp[now_vertex][index]);
        }

        for (int index = (int) graph[now_vertex].size() - 1; index >= 0; index--) {
            right_dp[now_vertex][index] = merge(normal_dp[now_vertex][index], right_dp[now_vertex][index + 1]);
        }

        for (auto next_edge = graph[now_vertex].begin(); next_edge != graph[now_vertex].end(); next_edge++) {
            size_t index = distance(graph[now_vertex].begin(), next_edge);
            if (next_edge->to == before) continue;
            // Because it is a Monoid, it can be a cumulative (sum, merge).
            dfs_after(next_edge->to, now_vertex, merge(left_dp[now_vertex][index], right_dp[now_vertex][index + 1]));
        }
        
        ans_dp[now_vertex] = right_dp[now_vertex][0];
    }

public:
    ReRooting(const size_t graph_size, const function<DP(DP, DP)> merge, const function<DP(DP, Data)> raising, DP identity_element)
        : tree_size(graph_size), graph(graph_size), normal_dp(graph_size), left_dp(graph_size), right_dp(graph_size), 
            ans_dp(graph_size), merge(merge), raising(raising), identity_element(identity_element) {}

    void add_edge(int source, int to, Data data) {
        graph[source].emplace_back(to, data);
        graph[to].emplace_back(source, data);
    }

    void build() {
        dfs_normal(0);
        dfs_after(0, -1, identity_element);
    }

    const DP &operator[] (const size_t vertex) const { return ans_dp[vertex]; }
};