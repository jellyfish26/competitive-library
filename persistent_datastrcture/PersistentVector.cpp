#include <bits/stdc++.h>
using namespace std;

// Last updated 2020-05-06
template<typename T, size_t node_division = 2>
class PersistentVector {
private:
    struct Node {
        T data;
        vector<Node*> child;

        Node() : data(), child(node_division) {}
        explicit Node(const T &data) : data(data), child(node_division) {}
        Node(const Node &node) : data(node.data), child(node.child) {}
    };

    vector<Node*> generation_root;
    vector<size_t> depth_range;
    size_t node_depth, data_size;

    void init_first_generation(const vector<T> &init_data) {
        stack<tuple<size_t, size_t, Node*, size_t>> explore; // <left, right, now_node, depth> and [left, right)
        explore.emplace(0, data_size, new Node(), node_depth);

        generation_root.push_back(get<2>(explore.top())); // root save

        while (!explore.empty()) {
            size_t left, right, depth;
            Node *now_node;
            tie(left, right, now_node, depth) = explore.top();
            explore.pop();

            for (size_t index = 0; left + index * depth_range[depth - 1] < right; index++) {
                size_t reference_index = left + index * depth_range[depth - 1];
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

    void init_depth() {
        node_depth = 0;
        size_t max_data_size = 1;
        while (max_data_size < data_size) {
            max_data_size *= node_division;
            node_depth++;
        }
        depth_range = vector<size_t>(node_depth + 1);
        depth_range[0] = 1;
        for (size_t index = 1; index <= node_depth; index++) depth_range[index] = depth_range[index - 1] * node_division;
    }

    void node_explore(Node* &start_node, const function<void(Node*, size_t, size_t)> operation, size_t index) {
        if (index >= data_size) throw out_of_range("out-of-range[" + to_string(index) + "]: The range that the program can reference is the half-open interval [0, " + to_string(data_size) +").");
        for (size_t explore_depth = node_depth; explore_depth > 0; explore_depth--) {
            size_t node_index = index / depth_range[explore_depth - 1];
            operation(start_node, node_index, explore_depth);
            start_node = start_node->child[node_index];
            index -= node_index * depth_range[explore_depth - 1];
        }
    }

    Node *get_index_node(size_t generation, size_t index) {
        Node* ret = generation_root[generation];
        node_explore(ret, [](Node* now_node, size_t node_index, size_t depth){}, index);
        return ret;
    }

    void update_nodes(size_t index, T value) {
        generation_root.push_back(new Node(*generation_root.back()));
        Node* reference_node = generation_root.back();
        function<void(Node*, size_t, size_t)> operation = [](Node* now_node, size_t node_index, size_t depth) {
            now_node->child[node_index] = new Node(*(now_node->child[node_index]));
        };
        node_explore(reference_node, operation, index);
        reference_node->data = value;
    }

public:
    explicit PersistentVector(const vector<T> &init_data) : data_size(init_data.size()) {
        init_depth();
        init_first_generation(init_data);
    }

    const T &get_data(size_t generation, size_t index) {
        return get_index_node(generation, index)->data;
    }

    void update(size_t index, T value) {
        update_nodes(index, value);
    }

    size_t generation_size() {
        return generation_root.size();
    }
};
