#include <bits/stdc++.h>
#include "template.cpp"
using namespace std;

// Last updated 2020-05-04
template<typename T>
class EulerTour {
private:
    UnWeightedGraph<T> &graph;
    vector<size_t> euler_data, euler_in, euler_out;
    size_t data_size;

    void dfs(size_t now_vertex, size_t before_vertex, size_t &reference_count) {
        euler_in[now_vertex] = reference_count;
        euler_data[reference_count++] = now_vertex;
        for (auto next_vertex : graph[now_vertex]) {
            if (reference_count != 0 && next_vertex == before_vertex) continue;
            dfs(next_vertex, now_vertex, reference_count);
            euler_data[reference_count++] = now_vertex;
        }
        euler_out[now_vertex] = reference_count;
    }

public:
    explicit EulerTour(UnWeightedGraph<T> &graph) : graph(graph), euler_data(2 * graph.size()), euler_in(graph.size()), euler_out(graph.size()), data_size(0) {}

    void build(size_t start_vertex = 0) {
        size_t reference_count = 0;
        dfs(start_vertex, 0, reference_count);
        data_size = reference_count;
    }

    // [left, right) = [first, second)
    pair<int, int> index_of_vertex(const size_t vertex) { return {euler_in[vertex], euler_out[vertex]}; }

    int pre_oreder(const size_t vertex) {return euler_in[vertex]; }

    // When using it in a query, the closed-interval.
    int post_order(const size_t vertex) {return euler_out[vertex] - 1; }

    // read only
    const size_t &operator[] (const size_t index) const { return euler_data[index]; }

    size_t size() const noexcept { return data_size; }
};