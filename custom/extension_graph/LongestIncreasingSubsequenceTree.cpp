#include <bits/stdc++.h>
using namespace std;

#include "../../graph/EulerTour.cpp"
#include "../../custom/extension_algorithm/UndoableLongestIncreasingSubsequence.cpp"

// Last-Update 2020-05-04
template<typename T>
class LongestIncreasingSubsequenceTree {
private:

    UnWeightedGraph<T> tree;
    EulerTour<T> euler_tour;
    vector<T> vertex_number_data;
    vector<size_t> vertex_lis_size;
    UndoableLongestIncreasingSubsequence<T> count_lis;

    void dfs() {
        for (size_t index = 0; index < euler_tour.size(); index++) {
            size_t now_vertex = euler_tour[index];
            size_t pre_order, post_order;
            tie(pre_order, post_order) = euler_tour.index_of_vertex(now_vertex);
            post_order--;
            if (pre_order == index) {
                vertex_lis_size[now_vertex] = count_lis.update(vertex_number_data[now_vertex]);
            }
            if (post_order == index) {
                count_lis.undo();
            }
        }
    }

public:
    explicit LongestIncreasingSubsequenceTree(size_t vertex_size, bool is_narrowly_sense) 
        : tree(vertex_size, false), euler_tour(tree), vertex_number_data(vertex_size, 0), vertex_lis_size(vertex_size) , count_lis(is_narrowly_sense) {}
    
    void add_edge(size_t source, size_t to) { tree.add_edge(source, to); }

    void init_vertex(size_t vertex, T number) { vertex_number_data[vertex] = number; }

    void build(size_t start_vertex = 0) {
        euler_tour.build(start_vertex);
        dfs();
    }

    const size_t &operator[] (size_t vertex) { return vertex_lis_size[vertex]; }
};