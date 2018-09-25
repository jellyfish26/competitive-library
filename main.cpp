#include <bits/stdc++.h>
using namespace std;
#define YesNo(b) b?cout << "Yes" << endl: cout << "No" << endl
#define YESNO(b) b?cout << "YES" << endl: cout << "NO" << endl
#define All(x) (x).begin(),(x).end()
#define VectorSumTotal(a) accumulate(a.begin(), a.end(), 0LL);
#define VectorSumMin(a) *std::min_element(a.begin(), a.end());
#define VectorSumMax(a) *std::max_element(a.begin(), a.end());
#define SortAscending(a) sort(a.begin(), a.end());
#define SortDescending(a) sort(a.begin(), a.end(), greater<>());

#include "GreatestCommonDivisor.cpp"

int main() {
    int A, B;
    cin >> A >> B;
    cout << GreatestCommonDivisor(A, B) << endl;
}