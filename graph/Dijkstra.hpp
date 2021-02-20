#pragma once
#include <cstddef>
#include <functional>
#include <limits>
#include <queue>
#include <vector>

#include "Base.hpp"

// Last Update 2021-02-20
template<typename T>
class Dijkstra : public WeightedGraph<T> {
protected:
    std::vector<std::vector<T>> dist;
    std::vector<std::vector<int>> prev;
    const T MAX_INF;

    void calc(int start);

public:
    Dijkstra(std::size_t size, bool is_directed);
    Dijkstra(const WeightedGraph<T> &target);

    T query(int start, int goal);
    std::vector<int> shortest_path(int start, int goal);
};

template<typename T>
Dijkstra<T>::Dijkstra(std::size_t size, bool is_directed)
: WeightedGraph<T>::WeightedGraph(size, is_directed), dist(size), prev(size), MAX_INF(std::numeric_limits<T>::max()) {}

template<typename T>
Dijkstra<T>::Dijkstra(const WeightedGraph<T> &target)
: WeightedGraph<T>::WeightedGraph(target), dist(target.size()), prev(target.size()), MAX_INF(std::numeric_limits<T>::max()) {}

template<typename T>
void Dijkstra<T>::calc(int start) {
    dist[start] = std::vector<T>(WeightedGraph<T>::graph.size(), MAX_INF);
    prev[start] = std::vector<int>(WeightedGraph<T>::graph.size(), -1);

    using PAIR = pair<T, int>;
    std::priority_queue<PAIR, std::vector<PAIR>, std::greater<PAIR>> next_edge;

    dist[start][start] = 0;
    prev[start][start] = -1;
    next_edge.emplace(dist[start][start], start);
    while (!next_edge.empty()) {
        T now_cost;
        int now_vt;
        tie(now_cost, now_vt) = next_edge.top();
        next_edge.pop();
        if (dist[start][now_vt] < now_cost) continue;

        for (const Edge<T> &next : WeightedGraph<T>::graph[now_vt]) {
            T next_cost = now_cost + next.cost;
            if (dist[start][next.to] <= next_cost) continue;

            prev[start][next.to] = now_vt;
            dist[start][next.to] = next_cost;
            next_edge.emplace(next_cost, next.to);
        }
    }
}

template<typename T>
T Dijkstra<T>::query(int start, int goal) {
    if (dist[start].empty()) calc(start);
    T ret = dist[start][goal];
    return (ret == MAX_INF ? -1 : ret);
}

template<typename T>
std::vector<int> Dijkstra<T>::shortest_path(int start, int goal) {
    if (dist[start].empty()) calc(start);
    std::vector<int> ret = {goal};

    int now = goal;
    while (now != start) {
        ret.push_back(prev[start][now]);
        now = prev[start][now];
        if (now == -1) {
            return std::vector<int>();
        }
    }
    std::reverse(ret.begin(), ret.end());
    return ret;
}