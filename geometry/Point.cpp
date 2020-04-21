#include <bits/stdc++.h>
using namespace std;


// Last updated 2020-4-18, ABC139-F Engines
struct Point {
    double x, y;
    
    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}

    Point &operator+=(const Point &input_vertex) {
        x += input_vertex.x;
        y += input_vertex.y;
        return *this;
    }

    Point &operator-=(const Point &input_vertex) {
        x -= input_vertex.x;
        y -= input_vertex.y;
        return *this;
    }

    Point &operator*=(double times) {
        x *= times;
        y *= times;
        return *this;
    }

    Point &operator/=(double divide) {
        x /= divide;
        y /= divide;
        return *this;
    }

    Point operator+(const Point &input_vertex) const { return Point(*this) += input_vertex;}

    Point operator-(const Point &input_vertex) const { return Point(*this) -= input_vertex;}

    Point operator*(double times) const { return Point(*this) *= times;}

    Point operator/(double divide) const { return Point(*this) /= divide;}

    friend istream &operator>>(istream &stream, Point &input_vertex) {
        return stream >> input_vertex.x >> input_vertex.y;
    }

    friend ostream &operator<<(ostream &stream, const Point &input_vertex) {
        return stream << input_vertex.x << input_vertex.y;
    }

    double dot(const Point &input_vertex) const {
        return x * input_vertex.x + y * input_vertex.y;
    }

    double cross(const Point &input_vertex) const {
        return x * input_vertex.y - y * input_vertex.x;
    }

    double before_norm() const {
        return x * x + y * y;
    }

    double norm() const {
        return sqrt(before_norm());
    }

    Point rotate_orthant() const {
        return Point{y, -x};
    }

    Point rotate_theta(double theta) {
        return Point(cos(theta) * x - sin(theta) * y, sin(theta) * x + cos(theta) * y);
    }

    int orthant() const {
        if (x == 0 && y == 0) return 1;
        if (x > 0) return y > 0 ? 1 : 4;
        return y > 0 ? 2 : 3;
    }

    bool operator<(const Point &input_vertex) const {
        int my_orthant = orthant(), input_orthant = input_vertex.orthant();
        if (my_orthant != input_orthant) return my_orthant < input_orthant;
        return cross(input_vertex) > 0;
    }
};