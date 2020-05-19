#include <bits/stdc++.h>
using namespace std;

// Last updated 2020-05-20
template<typename T>
class BinaryIndexedTree {
private:
    vector<T> data;

    inline size_t binary_search(const T value, const bool is_contain) {
        size_t low = 0, high = data.size();
        while (high - low > 1) {
            size_t middle = low + (high - low) / 2;
            if (sum(middle) < value + is_contain) low = middle;
            else high = middle;
        }
        return high;
    }

public:
    explicit BinaryIndexedTree(size_t data_size) : data(data_size + 1, 0) {}

    void update(size_t index, T value) {
        for (size_t now_index = index + 1; now_index < data.size(); now_index += (now_index & -now_index)) {
            data[now_index] += value;
        }
    }

    T sum(size_t index) {
        T count_up = 0;
        for (size_t now_index = index + 1; now_index > 0; now_index -= (now_index & -now_index)) {
            count_up += data[now_index];
        }
        return count_up;
    }

    T sum_all() {
        return sum(data.size() - 1);
    }

    // [left, right)
    T query(size_t left_index, size_t right_index) {
        T ret = 0;
        ret += (right_index == 0 ? 0 : sum(right_index - 1));
        ret += (left_index == 0 ? 0 : sum(left_index - 1));
        return ret;
    }

    size_t lower_bound(T value) {
        return binary_search(value, false);
    }

    size_t upper_bound(T value) {
        return binary_search(value, true);
    }
};