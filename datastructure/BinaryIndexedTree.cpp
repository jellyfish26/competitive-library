#include <bits/stdc++.h>
using namespace std;

// Last updated 2020-4-20
template<typename T>
struct BinaryIndexedTree {
    vector<T> data;

    explicit BinaryIndexedTree(int size) : data(size + 1, 0) {}

    void update(int idx, T value) {
        for (int i = idx + 1; i < data.size(); i += (i & -i)) data[i] += value;
    }

    T sum(int idx) {
        T count_up = 0;
        for (int i = idx + 1; i > 0; i -= (i & -i)) count_up += data[i];
        return count_up;
    }

    T sum_all() {
        return sum(data.size() - 1);
    }

    // [left, right)
    T query(int leftIdx, int rightIdx) {
        return sum(rightIdx - 1) - sum(leftIdx - 1);
    }
};