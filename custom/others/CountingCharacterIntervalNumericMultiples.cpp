#include <bits/stdc++.h>
#include "../algorithm/CumulativeSum.cpp"
using namespace std;

template<typename T>
class CountingCharacterIntervalNumericMultiples : public CumulativeSum<T> {
private:
    string huge_number;
    long long int radix, mod, remainder;
    vector<T> data;

    int char_convert(const char &input) {
        int now = input - '0';
        if (now >= 10) now = (input - 'A') + 10;
        return now;
    }

public:
    explicit CountingCharacterIntervalNumericMultiples(string number, long long int radix, long long int mod, long long int remainder) : CumulativeSum<T>(number.length()), huge_number(number), radix(radix), mod(mod), remainder(remainder), data(number.length()) {}

    void build() override {
        long long int now = 0, base = 1;
        data[0] = 1;
        for (size_t index = 0; index < huge_number.length(); index++) {
            now = (now + char_convert(huge_number[index]) * base) % mod;
            CumulativeSum<T>::update(index, data[(now + remainder) % mod]);
            base = (base * radix) % mod;
            data[now]++;
        }
        CumulativeSum<T>::build();
    }

    // C++17 or later
    bool is_viable() {
        return (gcd(radix, mod) == 1);
    }
};