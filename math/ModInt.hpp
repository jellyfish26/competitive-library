#pragma once
#include <cstdint>
#include <istream>

// Last Update 2021-02-23
template<std::int64_t MOD>
class ModInt {
protected:
    std::int64_t value;

public:
    ModInt();
    ModInt(std::int64_t value);
    ModInt(const ModInt &target);

    std::int64_t get() const;

    ModInt inverse() const;

    ModInt &operator+=(const ModInt &target);
    ModInt &operator-=(const ModInt &target);
    ModInt &operator*=(const ModInt &target);
    ModInt &operator/=(const ModInt &target);

    ModInt operator+(const ModInt &target) const;
    ModInt operator-(const ModInt &target) const;
    ModInt operator*(const ModInt &target) const;
    ModInt operator/(const ModInt &target) const;

    ModInt &operator-() const;

    bool operator==(const ModInt &target) const;
    bool operator!=(const ModInt &target) const;

    ModInt &operator=(std::int64_t x);
    ModInt &operator=(const ModInt &target);

    ModInt pow(std::int64_t n) const;
    static std::int64_t get_mod();

    template<std::int64_t X>
    friend std::istream &operator>>(std::istream &stream, ModInt<X> &target);

    template<std::int64_t X>
    friend std::ostream &operator<<(std::istream &stream, const ModInt<X> &target);
};

template<std::int64_t MOD>
ModInt<MOD>::ModInt() : value(0) {}

template<std::int64_t MOD>
ModInt<MOD>::ModInt(std::int64_t x)
: value(x >= 0 ? x % MOD : (MOD - ((-x) % MOD) % MOD)) {}

template<std::int64_t MOD>
ModInt<MOD>::ModInt(const ModInt &target) : value(target.value) {}

template<std::int64_t MOD>
std::int64_t ModInt<MOD>::get() const {
    return value;
}

template<std::int64_t MOD>
ModInt<MOD> ModInt<MOD>::inverse() const {
    std::int64_t base = value, p = MOD;
    std::int64_t u = 1, v = 0;
    while (p) {
        std::int64_t tmp = base / p;
        std::swap(base -= tmp * p, p);
        std::swap(u -= tmp * v, v);
    }
    return ModInt(u);
}

template<std::int64_t MOD>
ModInt<MOD> &ModInt<MOD>::operator+=(const ModInt &target) {
    value += target.value;
    if (value >= MOD) {
        value -= MOD;
    }
    return *this;
}

template<std::int64_t MOD>
ModInt<MOD> &ModInt<MOD>::operator-=(const ModInt &target) {
    value += (MOD - target.value);
    if (value >= MOD) {
        value -= MOD;
    }
    return *this;
}

template<std::int64_t MOD>
ModInt<MOD> &ModInt<MOD>::operator*=(const ModInt &target) {
    value = value * target.value % MOD;
    return *this;
}

template<std::int64_t MOD>
ModInt<MOD> &ModInt<MOD>::operator/=(const ModInt &target) {
    *this *= target.inverse();
    return *this;
}

template<std::int64_t MOD>
ModInt<MOD> ModInt<MOD>::operator+(const ModInt &target) const {
    return ModInt(*this) += target;
}

template<std::int64_t MOD>
ModInt<MOD> ModInt<MOD>::operator-(const ModInt &target) const {
    return ModInt(*this) -= target;
}

template<std::int64_t MOD>
ModInt<MOD> ModInt<MOD>::operator*(const ModInt &target) const {
    return ModInt(*this) *= target;
}

template<std::int64_t MOD>
ModInt<MOD> ModInt<MOD>::operator/(const ModInt &target) const {
    return ModInt(*this) /= target;
}

template<std::int64_t MOD>
ModInt<MOD> &ModInt<MOD>::operator-() const {
    return ModInt(-value);
}

template<std::int64_t MOD>
bool ModInt<MOD>::operator==(const ModInt &target) const {
    return value == target.value;
}

template<std::int64_t MOD>
bool ModInt<MOD>::operator!=(const ModInt &target) const {
    return value != target.value;
}

template<std::int64_t MOD>
ModInt<MOD> &ModInt<MOD>::operator=(std::int64_t value) {
    this->value = value;
    return *this;
}

template<std::int64_t MOD>
ModInt<MOD> &ModInt<MOD>::operator=(const ModInt &target) {
    this->value = target.value;
    return *this;
}

template<std::int64_t MOD>
ModInt<MOD> ModInt<MOD>::pow(std::int64_t n) const {
    ModInt ret(1), x(value);
    while (n > 0) {
        if (n&1) ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

template<std::int64_t MOD>
std::int64_t ModInt<MOD>::get_mod() {
    return MOD;
}

template<std::int64_t MOD>
std::istream &operator>>(std::istream &stream, ModInt<MOD> &target) {
    std::int64_t tmp;
    stream >> tmp;
    target = ModInt<MOD>(tmp);
    return stream;
}

template<std::int64_t MOD>
std::ostream &operator<<(std::ostream &stream, const ModInt<MOD> &target) {
    return stream << target.get();
}