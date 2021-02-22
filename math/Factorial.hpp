#pragma once
#include <cstdint>
#include <vector>

#include "ModInt.hpp"

// Last Update 2021-02-23
template<std::int64_t MOD>
class Factorial {
protected:
    std::vector<ModInt<MOD>> data;

public:
    Factorial(std::size_t N);

    const ModInt<MOD> &operator[](std::size_t index) const;
};

template<std::int64_t MOD>
Factorial<MOD>::Factorial(std::size_t N): data(N + 1, 0) {
    data[0] = 1, data[1] = 1;
    for (std::size_t idx = 2; idx <= N; idx++) {
        data[idx] = data[idx - 1] * idx;
    }
}

template<std::int64_t MOD>
const ModInt<MOD> &Factorial<MOD>::operator[](std::size_t idx) const {
    return data[idx];
}

