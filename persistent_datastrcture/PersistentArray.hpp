#pragma once
#include <cstddef>
#include <cstdint>
#include <functional>
#include <stack>
#include <tuple>
#include <vector>

// Last updated 2020-05-09
template<typename T, std::size_t node_division = 2>
class PersistentArray {
protected:
    struct Node {
        T data;
        std::vector<Node*> child;

        Node() : data(), child(node_division) {}
        Node(const T data) : data(data), child(0) {}
        Node(const Node &node) : data(node.data), child(node.child) {}
    };

    std::vector<Node*> generation_root;
    std::vector<std::size_t> depth_range;
    std::size_t node_depth{}, data_size;

    void init_first_generation(const std::vector<T> &init_data);
    void init_depth();

    void node_explore(Node* &start_node, const std::function<void(Node*, std::size_t, std::size_t)> &operation, std::size_t index) const;

    const Node* get_index_node(std::size_t generation, std::size_t index) const;
    void update_nodes(std::pair<std::size_t, T> update_content);

public:
    explicit PersistentArray(std::size_t data_size);
    PersistentArray(std::size_t data_size, T init_value);
    PersistentArray(const std::vector<T> &init_data);
    PersistentArray(Node* root, const std::size_t data_size);

    T get_data(std::size_t generation, std::size_t index) const;

    Node* get_generation_root(std::size_t generation);

    void update(std::vector<std::pair<std::size_t, T>> update_contents);
    void stay_generation_update(std::vector<std::pair<std::size_t, T>> update_contents);
    void update(std::size_t index, T value);
    void stay_generation_update(std::size_t index, T value);

    void next_generation();

    const T operator[](std::size_t index) const;

    std::size_t size();
    std::size_t generation_size();
    PersistentArray &operator=(Node *node);
};

template<typename T, std::size_t node_division>
void PersistentArray<T, node_division>::init_first_generation(const std::vector<T> &init_data) {
    std::stack<std::tuple<std::size_t, std::size_t, Node*, std::size_t>> explore; // <left, right, now_node, depth> and [left, right)
    explore.emplace(0, data_size, new Node(), node_depth);

    generation_root.push_back(get<2>(explore.top())); // root save
    while (!explore.empty()) {
        std::size_t left, right, depth;
        Node *now_node;
        tie(left, right, now_node, depth) = explore.top();
        explore.pop();
        for (std::size_t index = 0; left + index * depth_range[depth - 1] < right; index++) {
            std::size_t reference_index = left + index * depth_range[depth - 1];
            if (depth == 1) {
                now_node->child[index] = new Node(init_data.empty() ? 0 : init_data[reference_index]);
            } else {
                Node *temp = new Node();
                now_node->child[index] = temp;
                explore.emplace(reference_index, min(reference_index + depth_range[depth - 1], data_size), temp, depth - 1);
            }
        }
    }
}

template<typename T, std::size_t node_division>
void PersistentArray<T, node_division>::init_depth() {
    node_depth = 0;
    std::size_t max_data_size = 1;
    while (max_data_size < data_size) {
        max_data_size *= node_division;
        node_depth++;
    }
    depth_range = std::vector<std::size_t>(node_depth + 1);
    depth_range[0] = 1;
    for (std::size_t index = 1; index <= node_depth; index++) depth_range[index] = depth_range[index - 1] * node_division;
}

template<typename T, std::size_t node_division>
void PersistentArray<T, node_division>::node_explore(Node* &start_node, const std::function<void(Node*, std::size_t, std::size_t)> &operation, std::size_t index) const {
    if (index >= data_size) throw out_of_range("out-of-range[" + to_string(index) + "]: The range that the program can reference is the half-open interval [0, " + to_string(data_size) +").");
    for (std::size_t explore_depth = node_depth; explore_depth > 0; explore_depth--) {
        std::size_t node_index = index / depth_range[explore_depth - 1];
        if (operation != nullptr) operation(start_node, node_index, explore_depth);
        start_node = start_node->child[node_index];
        index -= node_index * depth_range[explore_depth - 1];
    }
}

template<typename T, std::size_t node_division>
const typename PersistentArray<T, node_division>::Node* PersistentArray<T, node_division>::get_index_node(std::size_t generation, std::size_t index) const {
    Node* ret = generation_root[generation];
    node_explore(ret, nullptr, index);
    return ret;
}

template<typename T, std::size_t node_division>
void PersistentArray<T, node_division>::update_nodes(std::pair<std::size_t, T> update_content) {
    std::size_t index;
    T value;
    tie(index, value) = update_content;
    Node* reference_node = generation_root.back();
    function<void(Node*, std::size_t, std::size_t)> operation = [](Node* now_node, std::size_t node_index, [[maybe_unused]] std::size_t depth) {
        now_node->child[node_index] = new Node(*(now_node->child[node_index]));
    };
    node_explore(reference_node, operation, index);
    reference_node->data = value;
}

template<typename T, std::size_t node_division>
PersistentArray<T, node_division>::PersistentArray(std::size_t data_size) : data_size(data_size) {
    init_depth();
    init_first_generation(std::vector<T>());
}

template<typename T, std::size_t node_division>
PersistentArray<T, node_division>::PersistentArray(std::size_t data_size, T init_value) : data_size(data_size) {
    init_depth();
    init_first_generation(std::vector<T>(data_size, init_value));
}

template<typename T, std::size_t node_division>
PersistentArray<T, node_division>::PersistentArray(const std::vector<T> &init_data) : data_size(init_data.size()) {
    init_depth();
    init_first_generation(init_data);
}

template<typename T, std::size_t node_division>
PersistentArray<T, node_division>::PersistentArray(Node* root, std::size_t data_size) : data_size(data_size) {
    init_depth();
    generation_root.push_back(root);
}

template<typename T, std::size_t node_division>
T PersistentArray<T, node_division>::get_data(std::size_t generation, std::size_t index) const {
    return get_index_node(generation, index)->data;
}

template<typename T, std::size_t node_division>
typename PersistentArray<T, node_division>::Node* PersistentArray<T, node_division>::get_generation_root(std::size_t generation) {
    return generation_root[generation];
}

template<typename T, std::size_t node_division>
void PersistentArray<T, node_division>::update(std::vector<std::pair<std::size_t, T>> update_contents) {
    generation_root.push_back(new Node(*generation_root.back()));
    for (auto content : update_contents) update_nodes(content);
}

template<typename T, std::size_t node_division>
void PersistentArray<T, node_division>::stay_generation_update(std::vector<std::pair<std::size_t, T>> update_contents) {
    for (auto content : update_contents) update_node(content.first, content.second);
}

template<typename T, std::size_t node_division>
void PersistentArray<T, node_division>::update(std::size_t index, T value) {
    generation_root.push_back(new Node(*generation_root.back()));
    update_nodes({index, value});
}

template<typename T, std::size_t node_division>
void PersistentArray<T, node_division>::stay_generation_update(std::size_t index, T value) {
    update_nodes({index, value});
}

template<typename T, std::size_t node_division>
void PersistentArray<T, node_division>::next_generation() {
    generation_root.push_back(new Node(*generation_root.back()));
}

template<typename T, std::size_t node_division>
const T PersistentArray<T, node_division>::operator[](std::size_t index) const {
    return get_data(generation_size() - 1, index);
}

template<typename T, std::size_t node_division>
std::size_t PersistentArray<T, node_division>::size() {
    return data_size;
}

template<typename T, std::size_t node_division>
std::size_t PersistentArray<T, node_division>::generation_size() {
    return generation_root.size();
}


template<typename T, std::size_t node_division>
PersistentArray<T, node_division> &PersistentArray<T, node_division>::operator=(Node *node) {
    generation_root = std::vector<Node*>();
    generation_root.push_back(node);
    return *this;
}