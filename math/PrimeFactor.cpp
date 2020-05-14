#include <bits/stdc++.h>
using namespace std;

// Last updated 2020-05-14
class PrimeFactor {
private:
    map<uint64_t , uint> factor_result;
    const uint64_t data;

public:
    PrimeFactor(uint64_t data) : data(data) {
        uint64_t calc_base = data;
        for (uint64_t index = 2; index * index <= calc_base; index++) {
            while (calc_base % index == 0) {
                factor_result[index]++;
                calc_base /= index;
            }
        }
        if (calc_base != 1) factor_result[calc_base]++;
    }

    map<uint64_t, uint> &query() { return factor_result; }
};