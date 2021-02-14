#pragma once
#include <vector>

// Last Update 2021-02-13
template<typename T>
class CumulativeSum {
private:
    std::vector<T> data;

public:
    explicit CumulativeSum(std::size_t size);

    void update(std::size_t index, T value);
    void build();

    T sum(std::size_t index);
    T sum_all();

    /// [left, right)
    T query(std::size_t left_index, std::size_t right_index);
};

template<typename T>
CumulativeSum<T>::CumulativeSum(std::size_t size) : data(size, 0) {}

template<typename T>
void CumulativeSum<T>::update(std::size_t index, T value) {
    data[index] += value;
}

template<typename T>
void CumulativeSum<T>::build() {
    for (size_t index = 0; index + 1 < data.size(); index++) {
        data[index + 1] += data[index];
    }
}

template<typename T>
T CumulativeSum<T>::sum(size_t index) {
    return data[index];
}

template<typename T>
T CumulativeSum<T>::sum_all() {
    return sum(data.size() - 1);
}

// [left, right)
template<typename T>
T CumulativeSum<T>::query(size_t left_index, size_t right_index) {
    T ret = (right_index == 0 ? 0 : sum(right_index - 1));
    ret -= (left_index == 0 ? 0 : sum(left_index - 1));
    return ret;
}
