//
// Modulo
//
#include <bits/stdc++.h>
#include "Value.cpp"
using namespace std;

long long int AdditionMOD(long long int a, long long int b) {
    return (a + b) % Value().MOD;
}

long long int SubtractionMOD(long long int a, long long int b) {
    return (a + Value().MOD - b) % Value().MOD;
}

long long int MultiplicationMOD(long long int a, long long int b) {
    return ((a % Value().MOD) * (b % Value().MOD) % Value().MOD);
}

long long int Power(long long int a, long long int b) {
    if (b == 0) return 1;
    else if (b == 1) return a % Value().MOD;
    else if (b % 2 == 0) return static_cast<long long int>(pow(Power(a, b / 2), 2)) % Value().MOD;
    else return (static_cast<long long int>(pow(Power(a, b / 2), 2)) * a) % Value().MOD;
}

long long int DivisionMOD(long long int a, long long int b) {
    return MultiplicationMOD(a, Power(b, Value().MOD - 2));
}