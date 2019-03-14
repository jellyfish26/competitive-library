#include <cstdio>
#define int long long
using namespace std;

int power(int a, int n, int mod) {
    int returnValue = 1;
    while (n > 0) {
        if (n & 1) {
            returnValue *= a;
            returnValue %= mod;
        }
        a *= a;
        a %= mod;
        n >>= 1;
    }
    return returnValue;
}