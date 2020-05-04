#include <bits/stdc++.h>
using namespace std;

// Last-Update 2020-05-04
template<typename T>
class UndoableLongestIncreaseingSubsequence {
private:
    struct operation_infomation {
        bool is_insert;
        T before, after;

        operation_infomation(bool is_insert, T before, T after) : is_insert(is_insert), before(before), after(after) {}
    };

    multiset<T> lis_data;
    list<operation_infomation> update_infomation;
    bool is_narrowly_sense;

public:
    explicit UndoableLongestIncreaseingSubsequence(bool is_narrowly_sense) : is_narrowly_sense(is_narrowly_sense) {}

    size_t update(T add) {
        typename multiset<T>::iterator iter;
        if (is_narrowly_sense) iter = lis_data.lower_bound(add);
        else iter = lis_data.upper_bound(add);
        if (iter == lis_data.end()) {
            lis_data.insert(add);
            update_infomation.emplace_back(true, add, add);   
        } else {
            update_infomation.emplace_back(false, *iter, add);
            lis_data.erase(iter);
            lis_data.insert(add);
        }
        return lis_data.size();
    }

    void undo() {
        if (lis_data.empty()) return;
        operation_infomation operation = update_infomation.back();
        auto iter = lis_data.lower_bound(operation.after);
        lis_data.erase(iter);
        if (!operation.is_insert) lis_data.insert(operation.before);
        update_infomation.erase(next(update_infomation.end(), -1));
    }
};