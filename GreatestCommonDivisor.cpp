//
// GCD
//
#include <bits/stdc++.h>
using namespace std;


long long int GreatestCommonDivisor(long long int a, long long int b) {
    while(true) {
        if(a < b) swap(a, b);
        if(!b) break;
        a %= b;
    }
    return a;
}
