#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+ 7;

// Last updated 2020-04-18
// Note: Inputs must be within the 32bit integer range (within the mod range).
template<int mod>
struct ModInt {
    int64_t value;

    ModInt() : value(0) {}
    ModInt(int64_t x) : value(x >= 0 ? x % mod : (mod - ((-x) % mod) % mod)) {}

    ModInt &operator+=(const ModInt &input) {
        value += input.value;
        if (value >= mod) value -= mod;
        return *this;
    }    

    ModInt &operator-=(const ModInt &input) {
        value += (mod - input.value);
        if (value >= mod) value -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &input) {
        value = value * input.value % mod;
        return *this;
    }

    ModInt &operator/=(const ModInt &input) {
        *this *= input.inverse();
        return *this;
    }

    ModInt inverse() const {
        int64_t base = value, p = mod;
        pair<int64_t, int64_t> save = {1, 0};
        while (p) {
            int64_t temp = base / p;
            swap(base -= temp * p, p);
            swap(save.first -= temp * save.second, save.second);
        }
        return ModInt(save.first);
    }

    ModInt operator-() const { return ModInt(-value); }

    ModInt operator-(const ModInt &input) const { return ModInt(*this) -= input; }

    ModInt operator+(const ModInt &input) const { return ModInt(*this) += input; }

    ModInt operator*(const ModInt &input) const { return ModInt(*this) *= input; }

    ModInt operator/(const ModInt &input) const { return ModInt(*this) /= input; }

    bool operator==(const ModInt &comparsion) const { return value == comparsion.value; }

    bool operator!=(const ModInt &comparsion) const { return value != comparsion.value; }

    friend istream &operator>>(istream &stream, ModInt &input) {
        int64_t temp;
        stream >> temp;
        input = ModInt<mod>(temp);
        return stream;
    }

    friend ostream &operator<<(ostream &stream, const ModInt &input) {
        return stream << input.value;
    }

    ModInt pow(int64_t n) const {
        ModInt ret(1), x(value);
        while (n > 0) {
            if (n and 1) ret *= x;
            x *= x;
            n >>= 1;
        }
        return ret;
    }
};

using modint = ModInt<MOD>;