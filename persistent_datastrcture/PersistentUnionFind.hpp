#pragma once
#include <cstddef>

#include "PersistentArray.hpp"

// Last updated 2020-05-09
template<std::size_t node_division>
class PersistentUnionFind {
    PersistentArray<int, node_division> data;

public:
    explicit PersistentUnionFind(std::size_t data_size);
    PersistentUnionFind(PersistentArray<int, node_division> &before, std::size_t generation);
    PersistentUnionFind(PersistentArray<int, node_division> &before);

    bool same(int x, int y);
    int find(std::size_t index);
    bool unite(int x, int y);

    void next_generation();

    int size(std::size_t index);

    PersistentUnionFind<node_division> &operator=(const PersistentUnionFind<node_division> *before);
};

template<std::size_t node_division>
PersistentUnionFind<node_division>::PersistentUnionFind(std::size_t data_size) : data(data_size, -1) {}

template<std::size_t node_division>
PersistentUnionFind<node_division>::PersistentUnionFind(PersistentArray<int, node_division> &before, std::size_t generation) : data(before.get_generation_root(generation)) {}

template<std::size_t node_division>
PersistentUnionFind<node_division>::PersistentUnionFind(PersistentArray<int, node_division> &before) : data(before.get_generation_root(before.generation_size() - 1)) {}

template<std::size_t node_division>
bool PersistentUnionFind<node_division>::same(int x, int y) {
    return find(x) == find(y);
}

template<std::size_t node_division>
int PersistentUnionFind<node_division>::find(std::size_t index) {
    if (data[index] < 0) return index;
    int temp = find(data[index]);
    data.stay_generation_update(index, temp);
    return temp;
}

template<std::size_t node_division>
bool PersistentUnionFind<node_division>::unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    if(data[x] > data[y]) swap(x, y);
    data.stay_generation_update(x, data[x] + data[y]);
    data.stay_generation_update(y, x);
    return true;
}

template<std::size_t node_division>
void PersistentUnionFind<node_division>::next_generation() {
    data.next_generation();
}

template<std::size_t node_division>
int PersistentUnionFind<node_division>::size(std::size_t index) {
    return (-data[find(index)]);
}

template<std::size_t node_division>
PersistentUnionFind<node_division> &PersistentUnionFind<node_division>::operator=(const PersistentUnionFind<node_division> *before) {
    data = before->data.get_generation_root(before->data.generation_size() - 1);
    return *this;
}