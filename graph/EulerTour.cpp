#include <bits/stdc++.h>
#include "template.cpp"
using namespace std;

// Last updated 2020-4-22
template<typename T>
class EulerTour {
private:
    vector<int> euler_data, euler_in, euler_out;
    size_t data_size;
    UnWeightedGraph<T> &graph;

    void dfs(int now_vertex, int before_vertex, int &reference_count) {
        euler_in[now_vertex] = reference_count;
        euler_data[reference_count++] = now_vertex;
        for (auto next_vertex : graph[now_vertex]) {
            if (next_vertex == before_vertex) continue;
            dfs(next_vertex, now_vertex, reference_count);
            euler_data[reference_count++] = now_vertex;
        }
        euler_out[now_vertex] = reference_count;
    }

public:
    explicit EulerTour(UnWeightedGraph<T> &graph, size_t data_size) : graph(graph), euler_data(2 * data_size), euler_in(data_size), euler_out(data_size), data_size(0) {}

    void build(int start_vertex = 0) {
        int reference_count = 0;
        dfs(start_vertex, -1, reference_count);
        data_size = reference_count;
    }

    // [left, right) = [first, second)
    pair<int, int> index_of_vertex(const int vertex) { return {euler_in[vertex], euler_out[vertex]}; }

    int pre_order(const int vertex) {return euler_in[vertex]; }

    // When using it in a query, the closed-interval.
    int post_order(const int vertex) {return euler_out[vertex] - 1; }

    // read only
    const int &operator[] (const int index) const { return euler_data[index]; }

    size_t size() const noexcept { return data_size; }
};