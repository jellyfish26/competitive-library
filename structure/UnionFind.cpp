#include <cstdio>
#define int long long
using namespace std;

struct UnionFind {
    vector<int> data;

    explicit UnionFind(int data_size) {
        data.assign(static_cast<unsigned long>(data_size), -1);
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if(x == y) return (false);
        if(data[x] > data[y]) swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return (true);
    }

    int find(int a) {
        if (data[a] < 0) return (a);
        else return (data[a] = find(data[a]));
    }

    int size(int a) {
        return (-data[find(a)]);
    }
};