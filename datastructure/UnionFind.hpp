#pragma once
#include <vector>
#include <utility>

// Last Update 2021-02-17
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

UnionFind::UnionFind(std::size_t data_size) : data(data_size, -1)  {}

bool UnionFind::unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return false;
    if(data[x] > data[y]) std::swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
}

int UnionFind::find(int x) {
    if (data[x] < 0) return x;
    else return (data[x] = find(data[x]));
}

int UnionFind::size(int x) {
    return (-data[find(x)]);
}

bool UnionFind::same(int x, int y) {
    return find(x) == find(y);
}
