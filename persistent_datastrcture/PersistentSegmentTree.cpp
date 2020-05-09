#include <bits/stdc++.h>
using namespace std;

// Last updated 2020-05-09
template<typename Monoid>
class PersistentSegmentTree {
private:
    struct Node {
        Monoid data;
        pair<Node*, Node*> child;

        Node(const Monoid &data) : data(data), child({nullptr, nullptr}) {}
        Node(const Node &node) : data(node.data), child(node.child) {}
    };

    size_t data_size, node_depth;
    vector<Node*> generation_root;
    const function<Monoid(Monoid, Monoid)> merge;
    const Monoid identity_element;

    void init_first_generation(const vector<Monoid> &init_data) {
        stack<tuple<Node*, size_t, size_t>> explore; // now node, depth, left index
        explore.emplace(new Node(identity_element), node_depth, 0);
        generation_root.push_back(get<0>(explore.top()));
        size_t add_index_count = 0;
        while (add_index_count < data_size) {
            Node* now_node;
            size_t depth, left_index;
            tie(now_node, depth, left_index) = explore.top();
            explore.pop();
            if (depth == 1) {
                if (init_data.empty()) {
                    now_node->child = {new Node(identity_element), new Node(identity_element)};
                } else {
                    pair<Node*, Node*> set_child = {new Node(init_data[left_index]), new Node(identity_element)};
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

    void init_merge_data() {
        stack<pair<Node*, bool>> explore; // before node is_add
        explore.emplace(generation_root.front(), false);

        while (!explore.empty()) {
            Node *now_node;
            bool is_add;
            tie(now_node, is_add) = explore.top();
            pair<Node*, Node*> &now_child = now_node->child;
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

    void init_depth() {
        node_depth = 0;
        size_t max_data_size = 1;
        while (max_data_size < data_size) {
            max_data_size<<=1;
            node_depth++;
        }
    }

    void update_node(size_t index, Monoid value) {
        stack<tuple<Node*, size_t, size_t, bool>> explore; // before node, now node, depth, left index is_add
        Node* start_node = generation_root.back();
        explore.emplace(start_node, node_depth, 0, false);

        while (!explore.empty()) {
            Node *now_node;
            size_t depth, left_index;
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
            size_t right_index = left_index + (1<<(depth - 1));
            if (left_index <= index && index < right_index) {
                now_node->child.first = new Node(*(now_node->child.first));
                explore.emplace(now_node->child.first, depth - 1, left_index, false);
            } else {
                now_node->child.second = new Node(*(now_node->child.second));
                explore.emplace(now_node->child.second, depth - 1, right_index, false);
            }
        }
    }

    Node *get_index_node(size_t generation, size_t index) {
        Node* now_node = generation_root[generation];
        size_t left = 0, depth = node_depth;
        while (depth > 0) {
            size_t interval = (1<<(depth - 1));
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

public:
    PersistentSegmentTree(const size_t data_size, function<Monoid(Monoid, Monoid)> merge, Monoid identity_element)
    : data_size(data_size), merge(merge), identity_element(identity_element) {
        init_depth();
        init_first_generation(vector<Monoid>());
    }

    PersistentSegmentTree (const size_t data_size, Monoid init_value, function<Monoid(Monoid, Monoid)> merge, Monoid identity_element)
    : data_size(data_size), merge(merge), identity_element(identity_element) {
        init_depth();
        init_first_generation(vector<Monoid>(data_size, init_value));
    }

    PersistentSegmentTree(const vector<Monoid> &init_data, function<Monoid(Monoid, Monoid)> merge, Monoid identity_element)
    : data_size(init_data.size()), merge(merge), identity_element(identity_element) {
        init_depth();
        init_first_generation(init_data);
    }

    PersistentSegmentTree(Node* root, const size_t data_size, function<Monoid(Monoid, Monoid)> merge, Monoid identity_element)
    : data_size(data_size), merge(merge), identity_element(identity_element) {
        init_depth();
        generation_root.push_back(root);
    }

    void update(vector<pair<size_t, Monoid>> update_contents) {
        generation_root.push_back(new Node(*generation_root.back()));
        for (auto content : update_contents) update_node(content.first, content.second);
    }

    void stay_generation_update(vector<pair<size_t, Monoid>> update_contents) {
        for (auto content : update_contents) update_node(content.first, content.second);
    }

    void update(size_t index, Monoid value) {
        generation_root.push_back(new Node(*generation_root.back()));
        update_node(index, value);
    }

    void stay_generation_update(size_t index, Monoid value) {
        update_node(index, value);
    }

    void next_generation() {
        generation_root.push_back(new Node(*generation_root.back()));
    }

    Monoid get_index_data(size_t generation, size_t index) {
        return get_index_node(generation, index)->data;
    }

    Monoid query(size_t generation, size_t explore_left_index, size_t explore_right_index) {
        Monoid ret = identity_element;
        stack<tuple<Node*, size_t, size_t>> explore; // now node, depth, left index
        explore.emplace(generation_root[generation], node_depth, 0);

        while (!explore.empty()) {
            Node *now_node;
            size_t now_left_index, now_right_index, depth;
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

    Monoid query(size_t left_index, size_t right_index) {
        return query(generation_root.size() - 1, left_index, right_index);
    }

    [[nodiscard]] size_t size() const {
        return data_size;
    }

    [[nodiscard]] size_t generation_size() const {
        return generation_root.size();
    }
};