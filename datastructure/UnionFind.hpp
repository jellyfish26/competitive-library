#pragma once
#include <vector>
#include <utility>

// Last Update 2021-02-20
class UnionFind {
private:
    std::vector<int> data;

public:
    explicit UnionFind(std::size_t data_size);

    bool unite(int x, int y);
    int find(int x);
    int size(int x);
    bool same(int x, int y);
};