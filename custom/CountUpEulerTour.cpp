#include <bits/stdc++.h>
#include "../graph/EulerTour.cpp"
#include "../datastructure/BinaryIndexedTree.cpp"
using namespace std;

// Last updated 2020-4-22
template<typename T, typename bit_type>
class CountUpEulerTour : public EulerTour<T> {
private:
    BinaryIndexedTree<bit_type> count_on_tree;
    size_t vertex_size;

    void reset_bit() { count_on_tree = BinaryIndexedTree<bit_type>(EulerTour<T>::size()); }

    void vertex_update(size_t index, bit_type value, vector<bool> &is_already) {
        if (is_already[EulerTour<T>::operator[](index)]) return;
        is_already[EulerTour<T>::operator[](index)] = true;
        count_on_tree.update(index, value);
    }

public:
    explicit CountUpEulerTour(UnWeightedGraph<T> &graph, size_t vertex_size) : EulerTour<T>(graph, vertex_size), count_on_tree(2 * vertex_size), vertex_size(vertex_size) {}

    void init_pre_order_count(bit_type base) {
        vector<bool> is_already_appeared(vertex_size, false);
        for (size_t index = 0; index < EulerTour<T>::size(); index++) vertex_update(index, base, is_already_appeared);
    }

    void init_post_order_count(bit_type base) {
        vector<bool> is_already_appeared(vertex_size, false);
        for (size_t index = EulerTour<T>::size() - 1; index >= 0; index--) vertex_update(index, base, is_already_appeared);
    }

    void reset_pre_order_count(bit_type base) {
        reset_bit();
        init_pre_order(base);
    }

    void reset_post_order_count(bit_type base) {
        reset_bit();
        init_post_order(base);
    }

    void reset_count() { reset_bit(); }

    void update(int partial_tree_root, bit_type value) {
        count_on_tree.update(EulerTour<T>::index_of_vertex(partial_tree_root).first, value);
    }

    bit_type query(pair<int, int> index) {
        return count_on_tree.query(index.first, index.second);
    }

    bit_type query(int partial_tree_root) {
        auto index = EulerTour<T>::index_of_vertex(partial_tree_root);
        return count_on_tree.query(index.first, index.second);
    }
};