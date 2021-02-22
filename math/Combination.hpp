#pragma once
#include <cstdint>
#include <vector>

#include "ModInt.hpp"

// Last Update 2021-02-23
template<std::int64_t MOD>
class Combination {
protected:
    std::size_t comb_size;
    std::vector<ModInt<MOD>> fact, inv, fact_inv;

    void comb_init();
public:
    explicit Combination(std::size_t N);

    ModInt<MOD> P(int n, int k) const;
    ModInt<MOD> C(int n, int k) const;
    ModInt<MOD> H(int n, int k) const;
};

template<std::int64_t MOD>
void Combination<MOD>::comb_init() {
    fact[0] = fact[1] = 1;
    inv[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    for (std::size_t index = 2; index < comb_size; index++) {
        fact[index] = fact[index - 1] * index;
        inv[index] = ModInt<MOD>(0) - inv[MOD % index] * (MOD / index);
        fact_inv[index] = fact_inv[index - 1] * inv[index];
    }
}

template<std::int64_t MOD>
Combination<MOD>::Combination(std::size_t N) : comb_size(N), fact(N), inv(N), fact_inv(N) {
    comb_init();
}

template<std::int64_t MOD>
ModInt<MOD> Combination<MOD>::P(int n, int k) const {
    if (n < 0 || k < 0) return 0;
    if (n < k) return 0;
    return fact[n] * fact_inv[n - k];
}

template<std::int64_t MOD>
ModInt<MOD> Combination<MOD>::C(int n, int k) const {
    if (k < 0) return 0;
    return P(n, k) * fact_inv[k];
}

template<std::int64_t MOD>
ModInt<MOD> Combination<MOD>::H(int n, int k) const {
    if (n < 0 || k < 0) return 0;
    return k == 0 ? 1 : C(n + k - 1, k);
}