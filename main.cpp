#include <bits/stdc++.h>
using namespace std;
#define int long long
int MOD = (int)1e9 + 7;
int IINF = (int)2e18;
// Comment out below and program paste
#include "UnionFind.h"

// AtCoder Beginner Contest 120
int N, M, A[100000], B[100000];

signed main() {
    cin >> N >> M;
    UnionFind data(N);

    for (int i = 0; i < M; ++i) {
        cin >> A[i] >> B[i];
        --A[i];
        --B[i];
    }

    int ret = 0;
    vector<int> ans(M);

    for (int i = M - 1; i >= 0; --i) {
        ans[i] = N * (N - 1) / 2 - ret;
        if (data.find(A[i]) != data.find(B[i])) {
            ret += data.size(A[i]) * data.size(B[i]);
            data.unite(A[i], B[i]);
        }
    }
    for (auto &i: ans) cout << i << endl;
}