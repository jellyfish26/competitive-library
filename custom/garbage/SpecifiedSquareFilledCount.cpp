#include <bits/stdc++.h>
using namespace std;

class SpecifiedSquareFilledCount {
private:
    pair<long long int, long long int> max_mass, search_range;
    vector<long long int> data;
    set<pair<long long int, long long int>> paint;

    void serach_mass(function<void(long long int, long long int)> update_function) {
        for (int add_height = 0; add_height < search_range.first; add_height++) {
            for (int add_width = 0; add_width < search_range.second; add_width++) {
                update_function(add_height, add_width);
            } 
        }
    }

    long long int count_painted_mass(long long int base_height, long long int base_width) {
        long long int ret = 0;
        auto update_function = [&](long long int add_height, long long int add_width) {
            long long int height = base_height + add_height;
            long long int width = base_width + add_width;
            if (height < 0 || height >= max_mass.first || width < 0 || width >= max_mass.second) {
                ret = -1;
                return;
            }
            if (paint.find({height, width}) != paint.end()) ret++;
        };
        serach_mass(update_function);
        return ret;
    }

    void exec_algorithm() {
        set<pair<long long int, long long int>> explore;
        for (auto now_paint : paint) {
            auto update_function = [&](long long int minus_height, long long int minus_width) {
                long long int height = now_paint.first - minus_height;
                long long int width = now_paint.second - minus_width;
                if (height < 0 || height >= max_mass.first || width < 0 || width >= max_mass.second) return;
                if (explore.find({height, width}) != explore.end()) return;
                auto painted_mass = count_painted_mass(height, width);
                if (painted_mass == -1) return;
                explore.emplace(height, width);
                data[painted_mass]++;
                data[0]--;
            };
            serach_mass(update_function);
        }
    }

public:
    explicit SpecifiedSquareFilledCount(long long int max_height, long long int max_width, long long int search_height, long long int search_width) 
        : max_mass(max_height, max_width), search_range(search_height, search_width), data(search_height * search_width + 1, 0) {
        data[0] = (max_height - search_height + 1) * (max_width - search_width + 1);
    }

    void add_paint_mass(long long int height, long long int width) { paint.emplace(height, width); }

    void build() { exec_algorithm(); }

    const long long int &operator[](const size_t index){ return data[index]; }
};