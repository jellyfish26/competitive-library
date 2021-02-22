#pragma once
#include <cstddef>
#include <cstdint>
#include <vector>
#include <utility>

// Last updated 2020-05-07
template<typename T>
class FastPartialPersistentArray {
private:
    std::size_t data_size, now_generation;
    std::vector<std::vector<std::pair<T, std::size_t>>> data_value;
    std::vector<std::vector<std::pair<std::size_t, T>>> data_generation;

    void generation_update(const std::pair<std::size_t, T> &update_content);
    void init_first_generation(const std::vector<T> &init_data);

public:
    explicit FastPartialPersistentArray(std::size_t data_size);
    FastPartialPersistentArray(std::size_t data_size, T init_value);
    FastPartialPersistentArray(const std::vector<T> &init_data);

    T get_data(std::size_t generation, std::size_t index) const;

    void update(std::vector<std::pair<std::size_t, T>> update_contents);
    void update(std::size_t index, T value);

    typename std::vector<std::pair<T, std::size_t>>::iterator generation_lower_bound(std::size_t index, T value);
    typename std::vector<std::pair<T, std::size_t>>::iterator generation_upper_bound(std::size_t index, T value);
    typename std::vector<std::pair<T, std::size_t>>::iterator generation_vector_end(std::size_t index);

    const T &operator[](std::size_t index) const;

    std::size_t size() const;
    std::size_t generation_size() const;
};

template<typename T>
void FastPartialPersistentArray<T>::generation_update(const std::pair<std::size_t, T> &update_content) {
    size_t index;
    T value;
    tie(index, value) = update_content;
    data_generation[index].emplace_back(now_generation, value);
    data_value[index].emplace_back(value, now_generation);
}

template<typename T>
void FastPartialPersistentArray<T>::init_first_generation(const std::vector<T> &init_data) {
    for (size_t index = 0; index < data_size; index++) {
        generation_update({index, init_data.empty() ? 0 : init_data[index]});
    }
}

template<typename T>
FastPartialPersistentArray<T>::FastPartialPersistentArray(std::size_t data_size)
    : data_size(data_size), now_generation(0), data_value(data_size), data_generation(data_size) {
    init_first_generation(vector<T>());
}

template<typename T>
FastPartialPersistentArray<T>::FastPartialPersistentArray(std::size_t data_size, T init_value)
    : data_size(data_size), now_generation(0), data_value(data_size), data_generation(data_size) {
    init_first_generation(vector<T>(data_size, init_value));
}

template<typename T>
FastPartialPersistentArray<T>::FastPartialPersistentArray(const std::vector<T> &init_data)
    : data_size(init_data.size()), now_generation(0), data_value(init_data.size()), data_generation(init_data.size()) {
    init_first_generation(init_data);
}

template<typename T>
T FastPartialPersistentArray<T>::get_data(std::size_t generation, std::size_t index) const {
    auto iter = lower_bound(data_generation[index].begin(), data_generation[index].end(), make_pair(generation, numeric_limits<T>::max()));
    iter = next(iter, -1);
    return iter->second;
}

template<typename T>
void FastPartialPersistentArray<T>::update(std::vector<std::pair<std::size_t, T>> update_contents) {
    now_generation++;
    for (auto content : update_contents) generation_update(content);
}

template<typename T>
void FastPartialPersistentArray<T>::update(std::size_t index, T value) {
    now_generation++;
    generation_update({index, value});
}

template<typename T>
typename std::vector<std::pair<T, std::size_t>>::iterator FastPartialPersistentArray<T>::generation_lower_bound(std::size_t index, T value) {
    return lower_bound(data_value[index].begin(), data_value[index].end(), make_pair(value, (size_t) 0));
}

template<typename T>
typename std::vector<std::pair<T, std::size_t>>::iterator FastPartialPersistentArray<T>::generation_upper_bound(std::size_t index, T value) {
    return upper_bound(data_value[index].begin(), data_value[index].end(), make_pair(value, (size_t) 0));
}

template<typename T>
typename std::vector<std::pair<T, std::size_t>>::iterator FastPartialPersistentArray<T>::generation_vector_end(std::size_t index) {
    return data_value[index].end();
}

template<typename T>
const T &FastPartialPersistentArray<T>::operator[](std::size_t index) const {
    return get_data(now_generation, index);
}

template<typename T>
std::size_t FastPartialPersistentArray<T>::size() const {
    return data_size;
}

template<typename T>
std::size_t FastPartialPersistentArray<T>::generation_size() const {
    return now_generation;
}

