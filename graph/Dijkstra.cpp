#include <bits/stdc++.h>
#include "template.cpp"
using namespace std;

// Last updated 2020-05-09
template<typename T>
class Dijkstra {
private:
    WeightedGraph<T> &graph;
    vector<vector<T>> shortest_distance;

    void init_and_exec_dijkstra(int start_vertex, const T MAX_INF, function<bool(int, T)> update_function) {
        shortest_distance[start_vertex] = vector<T>(graph.size(), MAX_INF);
        exec_dijkstra(start_vertex, update_function, shortest_distance[start_vertex]);
    }

    void default_dijkstra(int start_vertex, const T MAX_INF) {
        init_and_exec_dijkstra(start_vertex, MAX_INF, [&](size_t next_vertex, T next_cost) {
            return shortest_distance[start_vertex][next_vertex] == next_cost;
        });
    }

protected:
    void exec_dijkstra(int start_vertex, function<bool(int, T)> update_function, vector<T> &now_distance) {
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> next_edges;
        now_distance[start_vertex] = 0;
        next_edges.emplace(now_distance[start_vertex], start_vertex);
        while (!next_edges.empty()) {
            int now_vertex;
            T now_cost;
            tie(now_cost, now_vertex) = next_edges.top();
            next_edges.pop();
            if (now_distance[now_vertex] < now_cost) continue;
            for (auto &next_vertex : graph[now_vertex]) {
                T next_cost = now_cost + next_vertex.cost;
                if (now_distance[next_vertex.to] < next_cost) continue;
                if (update_function(next_vertex.to, next_cost)) continue;
                now_distance[next_vertex] = next_cost;
                next_edges.emplace(next_cost, next_vertex);
            }
        }
    }

public:
    Dijkstra(WeightedGraph<T> &graph) : graph(graph), shortest_distance(graph.size()) {}

    T query_overwrite(int start_vertex, int end_vertex, const T MAX_INF) {
        default_dijkstra(start_vertex, MAX_INF);
        return shortest_distance[start_vertex][end_vertex];
    }

    T query(int start_vertex, int end_vertex, const T MAX_INF)  {
        if (shortest_distance[start_vertex].empty()) default_dijkstra(start_vertex, MAX_INF);
        return shortest_distance[start_vertex][end_vertex];
    }

    void query(int start_vertex, const T MAX_INF) { if (shortest_distance[start_vertex].empty()) default_dijkstra(start_vertex, MAX_INF); }

    // read only
    constexpr vector<T> &operator[] (const size_t start_vertex) const { return shortest_distance[start_vertex]; }
};