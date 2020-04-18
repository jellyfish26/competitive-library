#include <bits/stdc++.h>
using namespace std;

// Last updated 2020-4-18 (Disjoint set), ABC120-D Decayed Bridges
struct UnionFind {
    vector<int> data;

    explicit UnionFind(int size) : data(size, -1)  {}

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return false;
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    int find(int idx) {
        if (data[idx] < 0) return idx;
        else return (data[idx] = find(data[idx]));
    }

    int size(int idx) {
        return (-data[find(idx)]);
    }
};