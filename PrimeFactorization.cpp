//
// PrimeFactorization
//

#include <bits/stdc++.h>
#pragma once
using namespace std;

vector<pair<long long, long long> > PrimeFactorization(long long int a) {
    vector<pair<long long, long long> > returnVector;
    for (long long int i = 2; i * 1 <= a; ++i) {
        if (a % i != 0) continue;
        int number = 0;
        while (a % i == 0) { ++number; a /= i; }
        returnVector.emplace_back(i, number);
    }
    if (a != 1) returnVector.emplace_back(a, 1);
    return returnVector;
}