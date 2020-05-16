#include <bits/stdc++.h>
using namespace std;

// Last updated 2020-05-16
template<typename T>
class Matrix {
private:
    vector<vector<T>> data;
    const size_t height, width;

public:
    Matrix(size_t height, size_t width) : height(height), width(width), data(height, vector<T>(width, 0)) {}

    Matrix(size_t N) : height(N), width(N), data(N, vector<T>(N, 0)) {}

    Matrix(Matrix const &copy_matrix) : height(copy_matrix.height), width(copy_matrix.width), data(copy_matrix.data) {}

    static Matrix generate_identity_matrix(size_t N) {
        Matrix ret(N);
        for (size_t index = 0; index < N; index++) ret.data[index][index] = 1;
        return ret;
    }

    Matrix &operator+=(const Matrix &operation_matrix) {
        assert(height == operation_matrix.height && width == operation_matrix.width);
        for (size_t height_index = 0; height_index < height; height_index++) {
            for (size_t width_index = 0; width_index < width; width_index++) {
                data[height_index][width_index] += operation_matrix.data[height_index][width_index];
            }
        }
        return *this;
    }

    Matrix &operator-=(const Matrix &operation_matrix) {
        assert(height == operation_matrix.height && width == operation_matrix.width);
        for (size_t height_index = 0; height_index < height; height_index++) {
            for (size_t width_index = 0; width_index < width; width_index++) {
                data[height_index][width_index] -= operation_matrix.data[height_index][width_index];
            }
        }
        return *this;
    }

    Matrix &operator*=(const Matrix &operation_matrix) {
        assert(width == operation_matrix.height);
        Matrix ret(height, operation_matrix.width);
        for (size_t height_index = 0; height_index < height; height_index++) {
            for (size_t width_index = 0; width_index < operation_matrix.width; width_index++) {
                for (size_t target_index = 0; target_index < width; target_index++) {
                    ret.data[height_index][width_index] += data[height_index][target_index] * operation_matrix.data[target_index][width_index];
                }
            }
        }
        data.swap(ret.data);
        return *this;
    }

    Matrix &operator^=(uint64_t operation_pow) {
        Matrix ret = generate_identity_matrix(height);
        while (operation_pow > 0) {
            if (operation_pow & 1) ret *= *this;
            *this *= *this;
            operation_pow >>= 1;
        }
        data.swap(ret.data);
        return *this;
    }

    Matrix &operator+(const Matrix &operation_matrix) const {
        return Matrix(*this) += operation_matrix;
    }

    Matrix &operator-(const Matrix &operation_matrix) const {
        return Matrix(*this) -= operation_matrix;
    }

    Matrix &operator*(const Matrix &operation_matrix) const {
        return Matrix(*this) *= operation_matrix;
    }

    Matrix &operator^(const uint64_t operation_pow) const {
        return Matrix(*this) ^= operation_pow;
    }

    friend istream &operator>>(istream &stream, Matrix &target) {
        for (size_t height_index = 0; height_index < target.height; height_index++) {
            for (size_t width_index = 0; width_index < target.width; width_index++) {
                stream >> target.data[height_index][width_index];
            }
        }
        return stream;
    }

    friend ostream &operator<<(ostream &stream, Matrix &target) {
        for (size_t height_index = 0; height_index < target.height; height_index++) {
            stream << "[";
            for (size_t width_index = 0; width_index < target.width; width_index++) {
                stream << target.data[height_index][width_index];
                stream << (width_index + 1 == target.width ? "]\n" : ", ");
            }
        }
        return stream;
    }

    vector<T> &operator[](const size_t index) { return data[index]; }

    size_t height_size() { return height; }

    size_t width_size() { return width; }
};