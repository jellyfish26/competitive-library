//
// AtCoderBeginnerContest110_D
//

#include <bits/stdc++.h>
using namespace std;
const int MAX = (int)1e7;
const int MOD = (int)1e9 + 7;

long long int fac[MAX], finv[MAX], inv[MAX];

//　Required before binomial coefficient. and Change the MAX value according to my needs.
void BinomialCoefficientInitialization() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// Calculation of binomial coefficient
long long int BinomialCoefficientCalculation(int n, int k) {
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
