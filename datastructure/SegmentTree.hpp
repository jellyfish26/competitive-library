#include <vector>
#include <functional>

// Last Update 2021-02-16
template<typename M>
class SegmentTree {
private:
    std::vector<M> data;
    const std::function<M(M, M)> merge;
    const M identity_element;
    std::size_t base_data_size;

    void data_size_calc_and_init(std::size_t N);
    void build();

public:
    explicit SegmentTree(std::size_t N, const std::function<M(M, M)> merge, const M identity_element);
    explicit SegmentTree(const std::vector<M> &init_data, const std::function<M(M, M)> merge, const M identity_element);

    void update(std::size_t index, M value);
    M query(std::size_t left_index, std::size_t right_index);

    const M &operator[](const std::size_t index);
};

template<typename M>
void SegmentTree<M>::data_size_calc_and_init(std::size_t N) {
    base_data_size = 1;
    while (base_data_size < N) {
        base_data_size <<= 1;
    }
    data = std::vector<M>(2 * base_data_size, identity_element);
}

template<typename M>
void SegmentTree<M>::build() {
    for (std::size_t idx = base_data_size - 1; idx > 0; idx--) {
        data[idx] = merge(data[2 * idx], data[2 * idx + 1]);
    }
}

template<typename M>
SegmentTree<M>::SegmentTree(std::size_t N, const std::function<M(M, M)> merge, const M identify_element) : merge(merge), identity_element(identity_element) {
    data_size_calc_and_init(N);
}

template<typename M>
SegmentTree<M>::SegmentTree(const std::vector<M> &init_data, const std::function<M(M, M)> merge, const M identity_element) : merge(merge), identity_element(identity_element) {
   data_size_calc_and_init(init_data.size());
   for (std::size_t idx = 0; idx < init_data.size(); idx++) {
       data[base_data_size + idx] = init_data[idx];
   }
   build();
}

template<typename M>
void SegmentTree<M>::update(std::size_t index, M value) {
    index += base_data_size;
    data[index] = value;
    while (index >>= 1) {
        data[index] = merge(data[2 * index], data[2 * index + 1]);
    }
}

// [left, right)
template<typename M>
M SegmentTree<M>::query(std::size_t left_index, std::size_t right_index) {
    M left = identity_element, right = identity_element;
    left_index += base_data_size;
    right_index += base_data_size;
    while (left_index < right_index) {
        if (left_index & 1) left = merge(left, data[left_index++]);
        if (right_index & 1) right = merge(data[--right_index], right);
        left_index >>= 1;
        right_index >>= 1;
    }
    return merge(left, right);
}

template<typename M>
const M &SegmentTree<M>::operator[](const std::size_t index) {
    return data[index + base_data_size];
}