//
// Prime extraction
//
#include <bits/stdc++.h>
using namespace std;

class PrimeNumberExtraction{
private: bool arr[(int)1e6];

public:
    vector<int> Eratosthenes(int N) {
        for (int i = 0; i < N; i++) {
            arr[i] = 1;
        }
        for (int i = 2; i < sqrt(N); i++) {
            if (arr[i]) {
                for (int j = 0; i * (j + 2) < N; j++) {
                    arr[i * (j + 2)] = 0;
                }
            }
        }

        vector<int> returnVector;

        for (int i = 2; i < N; i++) {
            if (arr[i]) {
                returnVector.push_back(i);
            }
        }

        return returnVector;
    }

};