#include <bits/stdc++.h>
using namespace std;

#include "ModInt.cpp"

// LastUpdate 2020-04-30
class Combination {
private:
    size_t combination_size;
    vector<modint> factorial, inverse, factorial_inverse;

    void combination_init() {
        factorial[0] = factorial[1] = 1;
        inverse[1] = 1;
        factorial_inverse[0] = factorial_inverse[1] = 1;
        for (size_t index = 2; index < combination_size; index++) {
            factorial[index] = factorial[index - 1] * index;
            inverse[index] = modint(0) - inverse[modint::get_mod() % index] * (modint::get_mod() / index);
            factorial_inverse[index] = factorial_inverse[index - 1] * inverse[index];
        }
    }

public:
    explicit Combination(size_t N) : combination_size(N), factorial(N), inverse(N), factorial_inverse(N) {
        combination_init();
    }

    modint P(int n, int k) const {
        if (n < 0 || k < 0) return 0;
        if (n < k) return 0;
        return factorial[n] * factorial_inverse[n - k];
    }

    modint C(int n, int k) const {
        if (k < 0) return 0;
        return P(n, k) * factorial_inverse[k];
    }

    modint H(int n, int k) const {
        if (n < 0 || k < 0) return 0;
        return k == 0 ? 1 : C(n + k - 1, k);
    }
};