#include <bits/stdc++.h>
using namespace std;

// LastUpdate 2020-05-17
template<typename T>
class CumulativeSum {
private:
    vector<T> data;

public:
    explicit CumulativeSum(size_t size) : data(size, 0) {}

    void update(size_t index, T value) {
        data[index] += value;
    }

    virtual void build() {
        for (size_t index = 0; index + 1 < data.size(); index++) data[index + 1] += data[index];
    }

    T sum(size_t index) {
        return data[index];
    }

    T sum_all() {
        return sum(data.size() - 1);
    }

    /// [left, right)
    T query(size_t left_index, size_t right_index) {
        T ret = (right_index == 0 ? 0 : sum(right_index - 1));
        ret -= (left_index == 0 ? 0 : sum(left_index - 1));
        return ret;
    }
};