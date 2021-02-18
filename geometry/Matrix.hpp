#pragma once
#include <cstdint>
#include <istream>
#include <vector>

// Last Update 2021-02-18
template<typename T>
class Matrix {
private:
    std::vector<std::vector<T>> data;
    std::size_t height, width;

public:
    Matrix(std::size_t height, std::size_t width);
    explicit Matrix(std::size_t N);
    Matrix(const Matrix &cp_mat);

    static Matrix gen_identity(std::size_t N);

    Matrix &operator+=(const Matrix &target);
    Matrix &operator-=(const Matrix &target);
    Matrix &operator*=(const Matrix &target);
    Matrix &operator^=(std::uint64_t power);

    Matrix operator+(const Matrix &target) const;
    Matrix operator-(const Matrix &target) const;
    Matrix operator*(const Matrix &target) const;
    Matrix operator^(std::uint64_t power) const;

    template<typename A>
    friend std::istream &operator>>(std::istream &stream, Matrix<A> &target);

    template<typename A>
    friend std::ostream &operator<<(std::ostream &stream, Matrix<A> &target);
    template<typename A>
    friend std::ostream &operator<<(std::ostream &stream, Matrix<A> target);

    const std::vector<T> &operator[](std::size_t index);

    std::size_t get_height();
    std::size_t get_width();
};

template<typename T>
Matrix<T>::Matrix(std::size_t height, std::size_t width) 
: data(height, std::vector<T>(width, 0)), height(height), width(width) {}

template<typename T>
Matrix<T>::Matrix(std::size_t N)
: data(N, std::vector<T>(N, 0)), height(N), width(N) {}

template<typename T>
Matrix<T>::Matrix(const Matrix<T> &cp_mat)
: height(cp_mat.height), width(cp_mat.width) {
    data = std::vector<std::vector<T>>(height, std::vector<T>(width, 0));
    for (std::size_t hi = 0; hi < height; hi++) {
        for (std::size_t wi = 0; wi < width; wi++) {
            data[hi][wi] = cp_mat.data[hi][wi];
        }
    }
}

template<typename T>
Matrix<T> Matrix<T>::gen_identity(std::size_t N) {
    Matrix<T> ret(N);
    for (std::size_t idx = 0; idx < N; idx++) {
        ret.data[idx][idx] = 1;
    }
    return ret;
}

template<typename T>
Matrix<T> &Matrix<T>::operator+=(const Matrix<T> &target) {
    assert(height == target.height && width == target.width);
    for (std::size_t hi = 0; hi < height; hi++) {
        for (std::size_t wi = 0; wi < width; wi++) {
            data[hi][wi] += target.data[hi][wi];
        }
    }
    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::operator-=(const Matrix<T> &target) {
    assert(height == target.height && width == target.width);
    for (std::size_t hi = 0; hi < height; hi++) {
        for (std::size_t wi = 0; wi < width; wi++) {
            data[hi][wi] -= target.data[hi][wi];
        }
    }
    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::operator*=(const Matrix<T> &target) {
    assert(width == target.height);
    Matrix<T> ret(height, target.width);
    for (std::size_t target_hi = 0; target_hi < ret.height; target_hi++) {
        for (std::size_t target_wi = 0; target_wi < ret.width; target_wi++) {
            for (std::size_t com_idx = 0; com_idx < width; com_idx++) {
                ret.data[target_hi][target_wi] += data[target_hi][com_idx] * target.data[com_idx][target_wi];
            }
        }
    }
    data.swap(ret.data);
    width = target.width;
    return *this;
}

template<typename T>
Matrix<T> &Matrix<T>::operator^=(std::uint64_t power) {
    Matrix<T> ret = gen_identity(height);
    while (power > 0) {
        if (power & 1) ret *= *this;
        *this *= *this;
        power >>= 1;
    }
    data.swap(ret.data);
    return *this;
}

template<typename T>
Matrix<T> Matrix<T>::operator+(const Matrix &target) const {
    return Matrix(*this) += target;
}

template<typename T>
Matrix<T> Matrix<T>::operator-(const Matrix &target) const {
    return Matrix(*this) -= target;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix &target) const {
    return Matrix(*this) *= target;
}

template<typename T>
Matrix<T> Matrix<T>::operator^(std::uint64_t power) const {
    return Matrix(*this) ^= power;
}

template<typename T>
std::istream &operator>>(std::istream &stream, Matrix<T> &target) {
    for (std::size_t hi = 0; hi < target.height; hi++) {
        for (std::size_t wi = 0; wi < target.width; wi++) {
            stream >> target.data[hi][wi];
        }
    }
    return stream;
}

template<typename T>
std::ostream &operator<<(std::ostream &stream, Matrix<T> &target) {
    for (std::size_t hi = 0; hi < target.height; hi++) {
        stream << "[";
        for (std::size_t wi = 0; wi < target.width; wi++) {
            stream << target.data[hi][wi];
            stream << (wi + 1 == target.width ? "]\n" : ", ");
        }
    }
    return stream;
}

template<typename T>
std::ostream &operator<<(std::ostream &stream, Matrix<T> target) {
    for (std::size_t hi = 0; hi < target.height; hi++) {
        stream << "[";
        for (std::size_t wi = 0; wi < target.width; wi++) {
            stream << target.data[hi][wi];
            stream << (wi + 1 == target.width ? "]\n" : ", ");
        }
    }
    return stream;
}

template<typename T>
const std::vector<T> &Matrix<T>::operator[](std::size_t index) {
    return data[index];
}

template<typename T>
std::size_t Matrix<T>::get_height() {
    return height;
}

template<typename T>
std::size_t Matrix<T>::get_width() {
    return width;
}