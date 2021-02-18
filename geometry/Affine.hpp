#include <cassert>
#include <cmath>
#include <iostream>

#include "Matrix.hpp"

// Last Update 2021-02-19
template<typename T>
class Affine : public Matrix<T> {
protected:
    static Affine gen_rot90();
public:
    Affine();
    Affine(const Affine &target);
    Affine(const Matrix<T> &target);

    static Affine gen_scaling(T x, T y);
    static Affine gen_translation(T x, T y);

    static Affine gen_rotate(T theta);
    static Affine gen_rot90(int time);
    static Affine gen_(T theta);
    static Affine gen_xskew(T theta);
    static Affine gen_yskew(T theta);

    Affine &operator+=(const Affine &target);
    Affine &operator-=(const Affine &target);
    Affine &operator*=(const Affine &target);

    Affine operator+(const Affine &target) const;
    Affine operator-(const Affine &target) const;
    Affine operator*(const Affine &target) const;

    Affine &operator=(const Affine &target);

    Matrix<T> calc(T x, T y);
};

template<typename T>
Affine<T> Affine<T>::gen_rot90() {
    Affine<T> ret;
    ret.data[0][0] = 0;
    ret.data[1][1] = 0;
    ret.data[0][1] = -1;
    ret.data[1][0] = 1;
    return ret;
}

template<typename T>
Affine<T>::Affine(): Matrix<T>::Matrix(Matrix<T>::gen_identity(3)) {}

template<typename T>
Affine<T>::Affine(const Affine<T> &target) : Matrix<T>::Matrix(target) {}

template<typename T>
Affine<T>::Affine(const Matrix<T> &target) : Matrix<T>::Matrix(target) {}

template<typename T>
Affine<T> Affine<T>::gen_scaling(T x, T y) {
    Affine<T> ret;
    ret.data[0][0] = x;
    ret.data[1][1] = y;
    return ret;
}

template<typename T>
Affine<T> Affine<T>::gen_translation(T x, T y) {
    Affine<T> ret;
    ret.data[0][2] = x;
    ret.data[1][2] = y;
    return ret;
}

template<typename T>
Affine<T> Affine<T>::gen_rotate(T theta) {
    Affine<T> ret;
    ret.data[0][0] = std::cos(theta);
    ret.data[0][1] = -std::sin(theta);
    ret.data[1][0] = std::sin(theta);
    ret.data[1][1] = std::cos(theta);
    return ret;
}

template<typename T>
Affine<T> Affine<T>::gen_rot90(int times) {
    assert(times >= 1);
    Affine<T> ret = gen_rot90();
    ret ^= times;
    return ret;
}

template<typename T>
Affine<T> Affine<T>::gen_xskew(T theta) {
    Affine<T> ret;
    ret.data[1][0] = std::tan(theta);
    return ret;
}

template<typename T>
Affine<T> Affine<T>::gen_yskew(T theta) {
    Affine<T> ret;
    ret.data[0][1] = std::tan(theta);
    return ret;
}

template<typename T>
Affine<T> &Affine<T>::operator+=(const Affine &target) {
    Matrix<T>::operator+=(target);
    return *this;
}

template<typename T>
Affine<T> &Affine<T>::operator-=(const Affine &target) {
    Matrix<T>::operator-=(target);
    return *this;
}

template<typename T>
Affine<T> &Affine<T>::operator*=(const Affine &target) {
    Matrix<T>::operator*=(target);
    return *this;
}

template<typename T>
Affine<T> Affine<T>::operator+(const Affine &target) const {
    return Affine(*this) += target;
}

template<typename T>
Affine<T> Affine<T>::operator-(const Affine &target) const {
    return Affine(*this) -= target;
}

template<typename T>
Affine<T> Affine<T>::operator*(const Affine &target) const {
    return Affine(*this) *= target;
}

template<typename T>
Affine<T> &Affine<T>::operator=(const Affine &target) {
    Matrix<T>::operator=(target);
    return *this;
}

template<typename T>
Matrix<T> Affine<T>::calc(T x, T y) {
    Matrix<T> ret(3, 1);
    ret.update(0, 0, x);
    ret.update(1, 0, y);
    ret.update(2, 0, 1);
    return *this * ret;
}