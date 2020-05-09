#include <bits/stdc++.h>
using namespace std;

// Last updated 2020-05-09
class UnionFind {
private:
    vector<int> data;

public:
    explicit UnionFind(size_t data_size) : data(data_size, -1)  {}

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    int find(size_t index) {
        if (data[index] < 0) return index;
        else return (data[index] = find(data[index]));
    }

    int size(size_t index) {
        return (-data[find(index)]);
    }
};