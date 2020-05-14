#include <bits/stdc++.h>
using namespace std;
#include "ModInt.cpp"

// LastUpdate 2020-05-14
class Factorial {
private:
    vector<modint> data;

public:
    Factorial(size_t N) :  data(N + 1, 0) {
        data[1] = 1;
        for (size_t index = 2; index <= N; index++) {
            data[index] = data[index - 1] * index;
        }
    }

    const modint &operator[] (size_t index) { return data[index]; }
};