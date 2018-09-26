#include <bits/stdc++.h>
using namespace std;
#define VectorType string
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define YesNo(b) b?cout << "Yes" << endl: cout << "No" << endl
#define YESNO(b) b?cout << "YES" << endl: cout << "NO" << endl
#define All(x) (x).begin(),(x).end()
#define VectorSumTotal(a) accumulate(a.begin(), a.end(), 0LL)
#define VectorStringTotal(a) accumulate(a.begin(), a.end(), string())
#define VectorSumMin(a) *std::min_element(a.begin(), a.end())
#define VectorSumMax(a) *std::max_element(a.begin(), a.end())
#define SortAscending(a) sort(a.begin(), a.end())
#define SortDescending(a) sort(a.begin(), a.end(), greater<>())

#include "PrimeNumberExtraction.cpp"

vector<VectorType> VectorInput(long long int a) {
    vector<VectorType> returnVector;
    VectorType temp;
    for (int i = 0; i < a; ++i) {
        cin >> temp;
        returnVector.push_back(temp);
    }
    return returnVector;
}

int main() {
    int N;
    cin >> N;
    auto ans = PrimeNumberExtraction().Eratosthenes(N);
    for (int an : ans) {
        cout << an << endl;
    }
}