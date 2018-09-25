//
// Modulo
//
#include <bits/stdc++.h>
const int MOD = (int)1e9 + 7;
using namespace std;

long long int AdditionMOD(long long int a, long long int b) {
    return (a + b) % MOD;
}

long long int SubtractionMOD(long long int a, long long int b) {
    return (a + mod - b) % MOD
}

long long int MultiplicationMOD(long long int a, long long int b) {
    return ((a % MOD) * (b % MOD) % MOD);
}

private long long long int Power(long long int a, long long int b) {
    if (b == 0) return 1;
    else if (b == 1) return x % MOD;
    else if (b % 2 == 0) return pow(Power(a, b / 2), 2) % MOD;
    else return pow(Power(a, b / 2), 2) * a % MOD;
}

long long int DivisionMOD(long long int a, long long int b) {
    return MultiplicationMOD(a, Power(b, MOD - 2));
}