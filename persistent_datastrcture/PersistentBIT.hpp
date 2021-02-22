#pragma once
#include <cstddef>
#include <stack>
#include <tuple>
#include <vector>
#include <utility>

// Last Update 2021-02-23
template <typename T>
class PersistentBIT {
protected:
    struct Node {
        T data;
        std::pair<Node*, Node*> child;

        Node() : data(), child({nullptr, nullptr}) {}
        explicit Node(const T &data) : data(data), child({nullptr, nullptr}) {}
        Node(const Node &node) : data(node.data), child(node.child) {}
    };

    std::size_t data_size, node_depth;
    std::vector<Node*> generation_root;

    void init_merge_data();
    void init_first_generation(const std::vector<T> &init_data) ;
    void init_depth();

    void update_node(std::size_t index, T value);

    Node *get_index_node(std::size_t generation, std::size_t index);

public:
    explicit PersistentBIT(const std::size_t data_size);
    PersistentBIT (const std::size_t data_size, T init_value);
    PersistentBIT(const std::vector<T> &init_data);
    PersistentBIT(Node* root, const std::size_t data_size);

    void update(std::vector<std::pair<std::size_t, T>> update_contents);
    void stay_generation_update(std::vector<std::pair<std::size_t, T>> update_contents);
    void update(std::size_t index, T value);
    void stay_generation_update(std::size_t index, T value);

    void next_generation();

    T get_index_data(std::size_t generation, std::size_t index);

    T query(std::size_t generation, std::size_t explore_left_index, std::size_t explore_right_index);
    T query(std::size_t left_index, std::size_t right_index);

    std::size_t size() const;
    std::size_t generation_size() const;
};


template <typename T>
void PersistentBIT<T>::init_merge_data() {
    std::stack<std::pair<Node*, bool>> explore; // before node is_add
    explore.emplace(generation_root.front(), false);

    while (!explore.empty()) {
        Node *now_node;
        bool is_add;
        tie(now_node, is_add) = explore.top();
        std::pair<Node*, Node*> &now_child = now_node->child;
        explore.pop();
        if (is_add) {
            now_node->data += now_child.first->data;
            now_node->data += now_child.second->data;
            continue;
        }
        if (now_child.first == nullptr) continue;
        explore.emplace(now_node, true);
        explore.emplace(now_child.second, false);
        explore.emplace(now_child.first, false);
    }
}

template <typename T>
void PersistentBIT<T>::init_first_generation(const std::vector<T> &init_data) {
    std::stack<std::tuple<Node*, std::size_t, std::size_t>> explore; // now node, depth, left index
    explore.emplace(new Node((T) 0), node_depth, 0);
    generation_root.push_back(get<0>(explore.top()));
    std::size_t add_index_count = 0;
    while (add_index_count < data_size) {
        Node* now_node;
        std::size_t depth, left_index;
        tie(now_node, depth, left_index) = explore.top();
        explore.pop();
        if (depth == 1) {
            if (init_data.empty()) {
                now_node->child = {new Node(0), new Node(0)};
            } else {
                std::pair<Node*, Node*> set_child = {new Node(init_data[left_index]), new Node(0)};
                if (left_index + 1 < data_size) set_child.second = new Node(init_data[left_index + 1]);
                now_node->child = set_child;
            }
            add_index_count += 2;
        } else {
            Node *left_node = new Node(0), *right_node = new Node(0);
            now_node->child = {left_node, right_node};
            explore.emplace(right_node, depth - 1, left_index + (1<<(depth - 1)));
            explore.emplace(left_node, depth - 1, left_index); // must left node second push (explore dfs)
        }
    }
    if (!init_data.empty()) init_merge_data();
}


template <typename T>
void PersistentBIT<T>::init_depth() {
    node_depth = 0;
    std::size_t max_data_size = 1;
    while (max_data_size < data_size) {
        max_data_size<<=1;
        node_depth++;
    }
}

template <typename T>
void PersistentBIT<T>::update_node(std::size_t index, T value) {
    std::stack<std::tuple<Node*, std::size_t, std::size_t, bool>> explore; // before node, now node, depth, left index is_add
    Node* start_node = generation_root.back();
    explore.emplace(start_node, node_depth, 0, false);

    while (!explore.empty()) {
        Node *now_node;
        std::size_t depth, left_index;
        bool is_add;
        tie(now_node, depth, left_index, is_add) = explore.top();
        explore.pop();
        if (is_add) {
            now_node->data += value;
            continue;
        }
        if (depth == 0) {
            now_node->data += value;
            continue;
        }
        explore.emplace(now_node, depth, left_index, true);
        std::size_t right_index = left_index + (1<<(depth - 1));
        if (left_index <= index && index < right_index) {
            now_node->child.first = new Node(*(now_node->child.first));
            explore.emplace(now_node->child.first, depth - 1, left_index, false);
        } else {
            now_node->child.second = new Node(*(now_node->child.second));
            explore.emplace(now_node->child.second, depth - 1, right_index, false);
        }
    }
}

template <typename T>
typename PersistentBIT<T>::Node*  PersistentBIT<T>::get_index_node(std::size_t generation, std::size_t index) {
    Node* now_node = generation_root[generation];
    std::size_t left = 0, depth = node_depth;
    while (depth > 0) {
        std::size_t interval = (1<<(depth - 1));
        if (index < left + interval) {
            now_node = now_node->child.first;
        } else {
            now_node = now_node->child.second;
            left = left + interval;
        }
        depth--;
    }
    return now_node;
}

template <typename T>
PersistentBIT<T>::PersistentBIT(const std::size_t data_size) : data_size(data_size) {
    init_depth();
    init_first_generation(std::vector<T>());
}

template <typename T>
PersistentBIT<T>::PersistentBIT (const std::size_t data_size, T init_value) : data_size(data_size) {
    init_depth();
    init_first_generation(std::vector<T>(data_size, init_value));
}

template <typename T>
PersistentBIT<T>::PersistentBIT(const std::vector<T> &init_data) : data_size(init_data.size()) {
    init_depth();
    init_first_generation(init_data);
}

template <typename T>
PersistentBIT<T>::PersistentBIT(Node* root, const std::size_t data_size) : data_size(data_size) {
    init_depth();
    generation_root.push_back(root);
}

template <typename T>
void PersistentBIT<T>::update(std::vector<std::pair<std::size_t, T>> update_contents) {
    generation_root.push_back(new Node(*generation_root.back()));
    for (auto content : update_contents) update_node(content.first, content.second);
}

template <typename T>
void PersistentBIT<T>::stay_generation_update(std::vector<std::pair<std::size_t, T>> update_contents) {
    for (auto content : update_contents) update_node(content.first, content.second);
}

template <typename T>
void PersistentBIT<T>::update(std::size_t index, T value) {
    generation_root.push_back(new Node(*generation_root.back()));
    update_node(index, value);
}

template <typename T>
void PersistentBIT<T>::stay_generation_update(std::size_t index, T value) {
    update_node(index, value);
}

template <typename T>
void PersistentBIT<T>::next_generation() {
    generation_root.push_back(new Node(*generation_root.back()));
}

template <typename T>
T PersistentBIT<T>::get_index_data(std::size_t generation, std::size_t index) {
    return get_index_node(generation, index)->data;
}

template <typename T>
T PersistentBIT<T>::query(std::size_t generation, std::size_t explore_left_index, std::size_t explore_right_index) {
    T ret = 0;
    std::stack<std::tuple<Node*, std::size_t, std::size_t>> explore; // now node, depth, left index
    explore.emplace(generation_root[generation], node_depth, 0);

    while (!explore.empty()) {
        Node *now_node;
        std::size_t now_left_index, now_right_index, depth;
        tie(now_node, depth, now_left_index) = explore.top();
        explore.pop();
        now_right_index = now_left_index + (1<<depth);
        if (explore_right_index <= now_left_index || now_right_index <= explore_left_index) continue;
        if (explore_left_index <= now_left_index && now_right_index <= explore_right_index) {
            ret += now_node->data;
            continue;
        }
        if (depth == 0) continue;
        explore.emplace(now_node->child.second, depth - 1, now_left_index + (1<<(depth - 1)));
        explore.emplace(now_node->child.first, depth - 1, now_left_index);
    }
    return ret;
}

template <typename T>
T PersistentBIT<T>::query(std::size_t left_index, std::size_t right_index) {
    return query(generation_root.size() - 1, left_index, right_index);
}

template <typename T>
std::size_t PersistentBIT<T>::size() const {
    return data_size;
}

template <typename T>
std::size_t PersistentBIT<T>::generation_size() const {
    return generation_root.size();
}