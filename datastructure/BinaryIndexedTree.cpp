#include <bits/stdc++.h>
using namespace std;

// Last updated 2020-4-21
template<typename T>
class BinaryIndexedTree {
private:
    vector<T> data;

public:
    explicit BinaryIndexedTree(int data_size) : data(data_size + 1, 0) {}

    void update(int index, T value) {
        for (int now_index = index + 1; now_index < data.size(); now_index += (now_index & -now_index)) {
            data[now_index] += value;
        } 
    }

    T sum(int index) {
        T count_up = 0;
        for (int now_index = index + 1; now_index > 0; now_index -= (now_index & -now_index)) {
            count_up += data[now_index];
        }
        return count_up;
    }

    T sum_all() {
        return sum(data.size() - 1);
    }

    // [left, right)
    T query(int left_index, int right_index) {
        return sum(right_index - 1) - sum(left_index - 1);
    }
};