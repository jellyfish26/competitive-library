#include <bits/stdc++.h>
using namespace std;

// Last updated 2020-05-07
template<typename T>
class FastPartialPersistentArray {
private:
    size_t data_size, now_generation;
    vector<vector<pair<T, size_t>>> data_value;
    vector<vector<pair<size_t, T>>> data_generation;

    void init_first_generation(const vector<T> &init_data) {
        for (size_t index = 0; index < data_size; index++) {
            generation_update({index, init_data.empty() ? 0 : init_data[index]});
        }
    }

    void generation_update(const pair<size_t, T> &update_content) {
        size_t index;
        T value;
        tie(index, value) = update_content;
        data_generation[index].emplace_back(now_generation, value);
        data_value[index].emplace_back(value, now_generation);
    }

public:
    explicit FastPartialPersistentArray(size_t data_size)
        : data_size(data_size), now_generation(0), data_value(data_size), data_generation(data_size) {
        init_first_generation(vector<T>());
    }

    FastPartialPersistentArray(size_t data_size, T init_value)
        : data_size(data_size), now_generation(0), data_value(data_size), data_generation(data_size) {
        init_first_generation(vector<T>(data_size, init_value));
    }

    explicit FastPartialPersistentArray(const vector<T> &init_data)
        : data_size(init_data.size()), now_generation(0), data_value(init_data.size()), data_generation(init_data.size()) {
        init_first_generation(init_data);
    }

    T get_data(size_t generation, size_t index) {
        auto iter = lower_bound(data_generation[index].begin(), data_generation[index].end(), make_pair(generation, numeric_limits<T>::max()));
        iter = next(iter, -1);
        return iter->second;
    }

    void update(vector<pair<size_t, T>> update_contents) {
        now_generation++;
        for (auto content : update_contents) generation_update(content);
    }

    void update(size_t index, T value) {
        now_generation++;
        generation_update({index, value});
    }

    typename vector<pair<T, size_t>>::iterator generation_lower_bound(size_t index, T value) {
        return lower_bound(data_value[index].begin(), data_value[index].end(), make_pair(value, (size_t) 0));
    }

    typename vector<pair<T, size_t>>::iterator generation_upper_bound(size_t index, T value) {
        return upper_bound(data_value[index].begin(), data_value[index].end(), make_pair(value, (size_t) 0));
    }

    typename vector<pair<T, size_t>>::iterator generation_vector_end(size_t index) {
        return data_value[index].end();
    }

    T operator[](size_t index) {
        return get_data( now_generation, index);
    }

    [[nodiscard]] size_t size() const {
        return data_size;
    }

    [[nodiscard]] size_t generation_size() const {
        return now_generation;
    }
};
