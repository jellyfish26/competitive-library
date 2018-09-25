//
// Cumulative sum
//

#include <bits/stdc++.h>
using namespace std;

class CumulativeSum {
private:
    vector<long long int> sum;

public:
    void Initialization(long long int a) {
        sum.push_back(0);
        long long int temp;
        for (int i = 1; i <= a; ++i) {
            cin >> temp;
            sum.push_back(sum[i - 1] + temp);
        }
    }

    long long int Section(long long int a, long long int b) {
        return sum[b] - sum[a];
    }
};
