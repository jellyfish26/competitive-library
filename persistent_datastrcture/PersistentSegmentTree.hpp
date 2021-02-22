#pragma once
#include <cstddef>
#include <functional>
#include <stack>
#include <tuple>
#include <utility>
#include <vector>

// Last Update 2021-02-23
template<typename Monoid>
class PersistentSegmentTree {
private:
    struct Node {
        Monoid data;
        std::pair<Node*, Node*> child;

        Node(const Monoid &data) : data(data), child({nullptr, nullptr}) {}
        Node(const Node &node) : data(node.data), child(node.child) {}
    };

    std::size_t data_size, node_depth;
    std::vector<Node*> generation_root;
    const std::function<Monoid(Monoid, Monoid)> merge;
    const Monoid identity_element;

    void init_merge_data();
    void init_first_generation(const std::vector<Monoid> &init_data);
    void init_depth();

    void update_node(std::size_t index, Monoid value);

    Node *get_index_node(std::size_t generation, std::size_t index);

public:
    PersistentSegmentTree(const std::size_t data_size, const std::function<Monoid(Monoid, Monoid)> &merge, Monoid identity_element);
    PersistentSegmentTree (const std::size_t data_size, Monoid init_value, const std::function<Monoid(Monoid, Monoid)> &merge, Monoid identity_element);
    PersistentSegmentTree(const std::vector<Monoid> &init_data, const std::function<Monoid(Monoid, Monoid)> &merge, Monoid identity_element);
    PersistentSegmentTree(Node* root, const std::size_t data_size, const std::function<Monoid(Monoid, Monoid)> &merge, Monoid identity_element);

    void update(std::vector<std::pair<std::size_t, Monoid>> update_contents);
    void stay_generation_update(std::vector<std::pair<std::size_t, Monoid>> update_contents);
    void update(std::size_t index, Monoid value);
    void stay_generation_update(std::size_t index, Monoid value);

    void next_generation();

    Monoid get_index_data(std::size_t generation, std::size_t index);

    Monoid query(std::size_t generation, std::size_t explore_left_index, std::size_t explore_right_index);
    Monoid query(std::size_t left_index, std::size_t right_index);

    Node* get_generation_root(std::size_t generation);

    std::size_t size() const;

    std::size_t generation_size() const;
};

template<typename Monoid>
void PersistentSegmentTree<Monoid>::init_merge_data() {
    std::stack<std::pair<Node*, bool>> explore; // before node is_add
    explore.emplace(generation_root.front(), false);

    while (!explore.empty()) {
        Node *now_node;
        bool is_add;
        tie(now_node, is_add) = explore.top();
        std::pair<Node*, Node*> &now_child = now_node->child;
        explore.pop();
        if (is_add) {
            now_node->data = merge(now_child.first->data, now_child.second->data);
            continue;
        }
        if (now_child.first == nullptr) continue;
        explore.emplace(now_node, true);
        explore.emplace(now_child.second, false);
        explore.emplace(now_child.first, false);
    }
}

template<typename Monoid>
void PersistentSegmentTree<Monoid>::init_first_generation(const std::vector<Monoid> &init_data) {
    std::stack<std::tuple<Node*, std::size_t, std::size_t>> explore; // now node, depth, left index
    explore.emplace(new Node(identity_element), node_depth, 0);
    generation_root.push_back(get<0>(explore.top()));
    std::size_t add_index_count = 0;
    while (add_index_count < data_size) {
        Node* now_node;
        std::size_t depth, left_index;
        tie(now_node, depth, left_index) = explore.top();
        explore.pop();
        if (depth == 1) {
            if (init_data.empty()) {
                now_node->child = {new Node(identity_element), new Node(identity_element)};
            } else {
                std::pair<Node*, Node*> set_child = {new Node(init_data[left_index]), new Node(identity_element)};
                if (left_index + 1 < data_size) set_child.second = new Node(init_data[left_index + 1]);
                now_node->child = set_child;
            }
            add_index_count += 2;
        } else {
            Node *left_node = new Node(identity_element), *right_node = new Node(identity_element);
            now_node->child = {left_node, right_node};
            explore.emplace(right_node, depth - 1, left_index + (1<<(depth - 1)));
            explore.emplace(left_node, depth - 1, left_index); // must left node second push (explore dfs)
        }
    }
    if (!init_data.empty()) init_merge_data();
}

template<typename Monoid>
void PersistentSegmentTree<Monoid>::init_depth() {
    node_depth = 0;
    std::size_t max_data_size = 1;
    while (max_data_size < data_size) {
        max_data_size<<=1;
        node_depth++;
    }
}

template<typename Monoid>
void PersistentSegmentTree<Monoid>::update_node(std::size_t index, Monoid value) {
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
            now_node->data = merge(now_node->child.first->data, now_node->child.second->data);
            continue;
        }
        if (depth == 0) {
            now_node->data = value;
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

template<typename Monoid>
typename PersistentSegmentTree<Monoid>::Node* PersistentSegmentTree<Monoid>::get_index_node(std::size_t generation, std::size_t index) {
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

template<typename Monoid>
PersistentSegmentTree<Monoid>::PersistentSegmentTree(const std::size_t data_size, const std::function<Monoid(Monoid, Monoid)> &merge, Monoid identity_element)
    : data_size(data_size), merge(merge), identity_element(identity_element) {
    init_depth();
    init_first_generation(std::vector<Monoid>());
}

template<typename Monoid>
PersistentSegmentTree<Monoid>::PersistentSegmentTree (const std::size_t data_size, Monoid init_value, const std::function<Monoid(Monoid, Monoid)> &merge, Monoid identity_element)
    : data_size(data_size), merge(merge), identity_element(identity_element) {
    init_depth();
    init_first_generation(std::vector<Monoid>(data_size, init_value));
}

template<typename Monoid>
PersistentSegmentTree<Monoid>::PersistentSegmentTree(const std::vector<Monoid> &init_data, const std::function<Monoid(Monoid, Monoid)> &merge, Monoid identity_element)
    : data_size(init_data.size()), merge(merge), identity_element(identity_element) {
    init_depth();
    init_first_generation(init_data);
}

template<typename Monoid>
PersistentSegmentTree<Monoid>::PersistentSegmentTree(Node* root, const std::size_t data_size, const std::function<Monoid(Monoid, Monoid)> &merge, Monoid identity_element)
        : data_size(data_size), merge(merge), identity_element(identity_element) {
    init_depth();
    generation_root.push_back(root);
}

template<typename Monoid>
void PersistentSegmentTree<Monoid>::update(std::vector<std::pair<std::size_t, Monoid>> update_contents) {
    generation_root.push_back(new Node(*generation_root.back()));
    for (auto content : update_contents) update_node(content.first, content.second);
}

template<typename Monoid>
void PersistentSegmentTree<Monoid>::stay_generation_update(std::vector<std::pair<std::size_t, Monoid>> update_contents) {
    for (auto content : update_contents) update_node(content.first, content.second);
}

template<typename Monoid>
void PersistentSegmentTree<Monoid>::update(std::size_t index, Monoid value) {
    generation_root.push_back(new Node(*generation_root.back()));
    update_node(index, value);
}

template<typename Monoid>
void PersistentSegmentTree<Monoid>::stay_generation_update(std::size_t index, Monoid value) {
    update_node(index, value);
}

template<typename Monoid>
void PersistentSegmentTree<Monoid>::next_generation() {
    generation_root.push_back(new Node(*generation_root.back()));
}

template<typename Monoid>
Monoid PersistentSegmentTree<Monoid>::get_index_data(std::size_t generation, std::size_t index) {
    return get_index_node(generation, index)->data;
}

template<typename Monoid>
Monoid PersistentSegmentTree<Monoid>::query(std::size_t generation, std::size_t explore_left_index, std::size_t explore_right_index) {
    Monoid ret = identity_element;
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
            ret = merge(ret, now_node->data);
            continue;
        }
        if (depth == 0) continue;
        explore.emplace(now_node->child.second, depth - 1, now_left_index + (1<<(depth - 1)));
        explore.emplace(now_node->child.first, depth - 1, now_left_index);
    }
    return ret;
}

template<typename Monoid>
Monoid PersistentSegmentTree<Monoid>::query(std::size_t left_index, std::size_t right_index) {
    return query(generation_root.size() - 1, left_index, right_index);
}

template<typename Monoid>
typename PersistentSegmentTree<Monoid>::Node* PersistentSegmentTree<Monoid>::get_generation_root(std::size_t generation) {
    return generation_root[generation];
}

template<typename Monoid>
std::size_t PersistentSegmentTree<Monoid>::size() const {
    return data_size;
}

template<typename Monoid>
std::size_t PersistentSegmentTree<Monoid>::generation_size() const {
    return generation_root.size();
}