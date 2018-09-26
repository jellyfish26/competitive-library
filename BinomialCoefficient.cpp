//
// AtCoderBeginnerContest110_D
//

#include <bits/stdc++.h>
#include "Value.cpp"s
using namespace std;

long long int fac[Value().MAX], finv[Value().MAX], inv[Value().MAX];

//　Required before binomial coefficient. and Change the MAX value according to my needs.
void BinomialCoefficientInitialization() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < Value().MAX; i++){
        fac[i] = fac[i - 1] * i % Value().MOD;
        inv[i] = Value().MOD - inv[Value().MOD % i] * (Value().MOD / i) % Value().MOD;
        finv[i] = finv[i - 1] * inv[i] % Value().MOD;
    }
}

// Calculation of binomial coefficient
long long int BinomialCoefficientCalculation(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % Value().MOD) % Value().MOD;
}
