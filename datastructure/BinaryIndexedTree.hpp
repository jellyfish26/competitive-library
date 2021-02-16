#include <vector>

// Last Update 2021-02-15
template<typename T>
class BinaryIndexedTree {
private:
    std::vector<T> data;

    std::size_t binary_search(const T value, const bool is_contain);
public:
    explicit BinaryIndexedTree(std::size_t data_size);

    void update(std::size_t index, T value);

    T sum(std::size_t index);
    T sum_all();

    T query(std::size_t left_index, std::size_t right_index);

    std::size_t lower_bound(T value);
    std::size_t upper_bound(T value);
};

template<typename T>
BinaryIndexedTree<T>::BinaryIndexedTree(std::size_t data_size) : data(data_size + 1, 0) {}

template<typename T>
std::size_t BinaryIndexedTree<T>::binary_search(const T value, const bool is_contain) {
    size_t low = 0, high = data.size();
    while (high - low > 1) {
        size_t middle = low + (high - low) / 2;
        if (sum(middle) < value + is_contain) low = middle;
        else high = middle;
    }
    return high;
}

template<typename T>
void BinaryIndexedTree<T>::update(std::size_t index, T value) {
    for (std::size_t ni = index + 1; ni < data.size(); ni += (ni & -ni)) {
        data[ni] += value;
    }
}

template<typename T>
T BinaryIndexedTree<T>::sum(std::size_t index) {
    T ret = 0;
    for (std::size_t ni = index + 1; ni > 0; ni -= (ni & -ni)) {
        ret += data[ni];
    }
    return ret;
}

template<typename T>
T BinaryIndexedTree<T>::sum_all() {
    return sum(data.size() - 1);
}

// [left, right)
template<typename T>
T BinaryIndexedTree<T>::query(std::size_t left_index, std::size_t right_index) {
    T ret = 0;
    ret += (right_index == 0 ? 0 : sum(right_index - 1));
    ret -= (left_index == 0 ? 0 : sum(left_index - 1));
    return ret;
}

template<typename T>
std::size_t BinaryIndexedTree<T>::lower_bound(T value) {
    return binary_search(value, false);
}

template<typename T>
std::size_t BinaryIndexedTree<T>::upper_bound(T value) {
    return binary_search(value, true);
}