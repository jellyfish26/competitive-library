#include <bits/stdc++.h>
#include "PersistentArray.cpp"
using namespace std;

// Last updated 2020-05-09
template<size_t node_division>
class PersistentUnionFind {
    PersistentArray<int, node_division> data;

public:
    explicit PersistentUnionFind(size_t data_size) : data(data_size, -1) {}

    PersistentUnionFind(PersistentArray<int, node_division> &before, size_t generation) : data(before.get_generation_root(generation)) {}

    explicit PersistentUnionFind(PersistentArray<int, node_division> &before) : data(before.get_generation_root(before.generation_size() - 1)) {}

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int find(size_t index) {
        if (data[index] < 0) return index;
        int temp = find(data[index]);
        data.stay_generation_update(index, temp);
        return temp;
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(data[x] > data[y]) swap(x, y);
        data.stay_generation_update(x, data[x] + data[y]);
        data.stay_generation_update(y, x);
        return true;
    }

    void next_generation() {
        data.next_generation();
    }

    int size(size_t index) {
        return (-data[find(index)]);
    }

    PersistentUnionFind<node_division> &operator=(PersistentUnionFind<node_division> *before) {
        data = before->data.get_generation_root(before->data.generation_size() - 1);
        return *this;
    }
};