#pragma once
#include <cassert>
#include <cstddef>
#include <vector>

#include "../datastructure/BinaryIndexedTree.hpp"
#include "EulerTour.hpp"

// Last Update 2021-02-20
template<typename T, typename BIT>
class CountupEulerTour : public EulerTour<T> {
protected:
    BinaryIndexedTree<BIT> count_on_tree;

    void vertex_update(std::size_t index, BIT valum, std::vector<bool> &is_already);
public:
    explicit CountupEulerTour(std::size_t size);
    CountupEulerTour(WeightedGraph<T> &graph);

    void reset();

    void init_pre_order_count(BIT base);
    void init_post_order_count(BIT base);

    void reset_pre_order_count(BIT base);
    void reset_post_order_count(BIT base);

    void update(int tree_root, BIT value);

    BIT query(std::size_t left, std::size_t right);
    BIT query(int tree_root);
};

template<typename T, typename BIT>
void CountupEulerTour<T, BIT>::vertex_update(std::size_t index, BIT value, std::vector<bool> &is_already) {
    if (is_already[EulerTour<T>::operator[](index)]) return;
    is_already[EulerTour<T>::operator[](index)] = true;
    count_on_tree.update(index, value);
}

template<typename T, typename BIT>
CountupEulerTour<T, BIT>::CountupEulerTour(std::size_t size) : EulerTour<T>(size), count_on_tree(2 * size) {}

template<typename T, typename BIT>
CountupEulerTour<T, BIT>::CountupEulerTour(WeightedGraph<T> &graph) : EulerTour<T>(graph), count_on_tree(2 * graph.size()) {};

template<typename T, typename BIT>
void CountupEulerTour<T, BIT>::reset() {
    count_on_tree = BinaryIndexedTree<BIT>(WeightedGraph<T>::size());
}

template<typename T, typename BIT>
void CountupEulerTour<T, BIT>::init_pre_order_count(BIT base) {
    std::vector<bool> already_appeared(EulerTour<T>::size(), false);
    for (std::size_t idx = 0; idx <  EulerTour<T>::size(); idx++) {
        vertex_update(idx, base, already_appeared);
    }
}

template<typename T, typename BIT>
void CountupEulerTour<T, BIT>::init_post_order_count(BIT base) {
    assert(EulerTour<T>::size() != 0);
    std::vector<bool> already_appeared(EulerTour<T>::size(), false);
    for (std::size_t idx = EulerTour<T>::size() - 1; idx >= 0; idx--) {
        vertex_update(idx, base, already_appeared);
    }
}

template<typename T, typename BIT>
void CountupEulerTour<T, BIT>::reset_pre_order_count(BIT base) {
    reset();
    init_pre_order_count(base);
}

template<typename T, typename BIT>
void CountupEulerTour<T, BIT>::reset_post_order_count(BIT base) {
    reset();
    init_post_order_count();
}

template<typename T, typename BIT>
void CountupEulerTour<T, BIT>::update(int tree_root, BIT value) {
    count_on_tree.update(EulerTour<T>::interval(tree_root).first, value);
}

template<typename T, typename BIT>
BIT CountupEulerTour<T, BIT>::query(std::size_t left, std::size_t right) {
    return count_on_tree.query(left, right);
}

template<typename T, typename BIT>
BIT CountupEulerTour<T, BIT>::query(int tree_root) {
    std::pair<int, int> idx = EulerTour<T>::interval(tree_root);
    return count_on_tree.query(idx.first, idx.second);
}