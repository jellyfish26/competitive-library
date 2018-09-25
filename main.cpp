#include <bits/stdc++.h>
#include "BinomialCoefficient.cpp"
#include "Modulo.cpp"
#include "PrimeFactorization.cpp"
using namespace std;

// AtCoder Beginner Contest 110 D
int main() {
    int N, M;
    cin >> N >> M;
    BinomialCoefficientInitialization();
    auto primePower = PrimeFactorization(M);
    long long int answer = 1;
    for (auto &i : primePower) {
        answer = MultiplicationMOD(answer, BinomialCoefficientCalculation(static_cast<int>(i.second + N - 1), N - 1));
    }
    cout << answer << endl;
}