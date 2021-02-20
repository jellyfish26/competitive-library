#pragma once
#include <cstddef>
#include <utility>
#include <vector>

#include "Base.hpp"

// Last Update 2021-02-20
template<typename T>
class EulerTour : public WeightedGraph<T> {
protected:
    std::vector<int> euler_data, euler_in, euler_out;
    std::size_t data_size;

    void dfs(int now_v, int before_v, int &count);

public:
    explicit EulerTour(std::size_t size);
    EulerTour(const WeightedGraph<T> &graph);

    void build(int start);

    std::pair<int, int> interval(int vertex) const;

    int pre_order(int vertex) const;
    int post_order(int vertex) const;

    const int &operator[](std::size_t idx) const;
    std::size_t size() const;
};


template<typename T>
void EulerTour<T>::dfs(int now, int before, int &count) {
    euler_in[now] = count;
    euler_data[count++] = now;
    for (Edge<T> &next : WeightedGraph<T>::graph[now]) {
        if (next.to == before) continue;

        dfs(next.to, now, count);
        euler_data[count++] = now;
    }
    euler_out[now] = count;
}

template<typename T>
EulerTour<T>::EulerTour(std::size_t size)
: WeightedGraph<T>::WeightedGraph(size, false), euler_data(2 * size), euler_in(size), euler_out(size), data_size(0) {}

template<typename T>
EulerTour<T>::EulerTour(const WeightedGraph<T> &graph)
: WeightedGraph<T>::WeightedGraph(graph), euler_data(2 * graph.size()), euler_in(graph.size()), euler_out(graph.size()) {}

template<typename T>
void EulerTour<T>::build(int start) {
    int count = 0;
    dfs(start, -1, count);
    data_size = count;
}

// [first, second)
template<typename T>
std::pair<int, int> EulerTour<T>::interval(int vertex) const {
    return {euler_in[vertex], euler_out[vertex]};
}

template<typename T>
int EulerTour<T>::pre_order(int vertex) const {
    return euler_in[vertex];
}

// When using it function, the closed-interval.
template<typename T>
int EulerTour<T>::post_order(int vertex) const {
    return euler_out[vertex] - 1;
}

template<typename T>
const int &EulerTour<T>::operator[](std::size_t index) const {
    return euler_data[index];
}

template<typename T>
std::size_t EulerTour<T>::size() const {
    return data_size;
}