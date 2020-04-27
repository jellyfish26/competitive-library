#include <bits/stdc++.h>
using namespace std;

template<typename T>
class VertexReplenishmentLimitDijkstra {
private:
    struct edge {
        size_t source, to;
        T limit, cost;
        
        edge(size_t source, size_t to, T limit, T cost) : source(source), to(to), limit(limit), cost(cost) {}
    };

    struct replenishment {
        T limit, cost;

        replenishment() : limit(0), cost(1) {};
        replenishment(T limit, T cost) : limit(limit), cost(cost) {};
    };

    size_t graph_size;
    vector<vector<T>> minimum_cost;
    vector<vector<edge>> graph;
    vector<replenishment> vertex_replenishment;
    T max_limit;
    bool is_directed_graph;

    void exec_dijkstra(size_t start_vertex, T start_limit, T MAX_INF) {
        if (start_limit > max_limit) start_limit = max_limit;
        using info = tuple<T, T, size_t>; // {cost, limit, vertex}
        vector<vector<T>> dp(graph_size, vector<T>(max_limit + 1, MAX_INF));
        priority_queue<info, vector<info>, greater<info>> explore;
        dp[start_vertex][start_limit] = 0;
        explore.emplace(0, start_limit, 0);
        while (!explore.empty()) {
            size_t now_vertex;
            T limit, cost;
            tie(cost, limit, now_vertex) = explore.top();
            explore.pop();

            // replenishment
            T next_limit = limit + vertex_replenishment[now_vertex].limit;
            T next_cost = cost + vertex_replenishment[now_vertex].cost;
            if (next_limit <= max_limit && next_cost < dp[now_vertex][next_limit]) {
                dp[now_vertex][next_limit] = next_cost;
                explore.emplace(next_cost, next_limit, now_vertex);
            }

            for (edge next_edge : graph[now_vertex]) {
                next_limit = limit - next_edge.limit;
                if (next_limit < 0) continue;
                next_cost = cost + next_edge.cost;
                if (next_cost < dp[next_edge.to][next_limit]) {
                    dp[next_edge.to][next_limit] = next_cost;
                    explore.emplace(next_cost, next_limit, next_edge.to);
                }
            }
        }

        // update minimum_cost
        vector<T> &update_reference = (minimum_cost[start_vertex] = vector<T>(graph_size, MAX_INF));
        for (size_t vertex = 0; vertex < graph_size; vertex++) {
            for (T limit = 0; limit < max_limit; limit++) {
                update_reference[vertex] = min(update_reference[vertex], dp[vertex][limit]);
            }
        }
    }

    void reset_minimum_cost(size_t vertex, const T MAX_INF) {
        minimum_cost[vertex] = vector<T>(graph_size, MAX_INF);
    }

public:
    explicit VertexReplenishmentLimitDijkstra(size_t graph_size, T max_limit, bool is_directed_graph) : graph_size(graph_size), minimum_cost(graph_size), graph(graph_size), vertex_replenishment(graph_size), max_limit(max_limit), is_directed_graph(is_directed_graph) {}

    void add_edge(size_t source, size_t to, T limit, T cost) {
        graph[source].emplace_back(source, to, limit, cost);
        if (!is_directed_graph) graph[to].emplace_back(to, source, limit, cost);
    }

    void add_replenishment(size_t vertex, T limit, T cost) {
        vertex_replenishment[vertex] = replenishment(limit, cost);
    }
    

    T query_overwrite(size_t start_vertex, size_t end_vertex, T max_limit, const T MAX_INF) {
        reset_minimum_cost(start_vertex, MAX_INF);
        exec_dijkstra(start_vertex, max_limit, MAX_INF);
    }

    T query(size_t start_vertex, size_t end_vertex, T start_limit, const T MAX_INF) {
        if (minimum_cost[start_vertex].empty()) exec_dijkstra(start_vertex, start_limit, MAX_INF);
        return minimum_cost[start_vertex][end_vertex];
    }
};