#include <bits/stdc++.h>
using namespace std;

// Last updated 2020-4-18, ABC139-F Engines
struct Vertex {
    double x, y;
    
    Vertex() : x(0), y(0) {}
    Vertex(double x, double y) : x(x), y(y) {}

    Vertex &operator+=(const Vertex &input_vertex) {
        x += input_vertex.x;
        y += input_vertex.y;
        return *this;
    }

    Vertex &operator-=(const Vertex &input_vertex) {
        x -= input_vertex.x;
        y -= input_vertex.y;
        return *this;
    }

    Vertex &operator*=(double times) {
        x *= times;
        y *= times;
        return *this;
    }

    Vertex &operator/=(double divide) {
        x /= divide;
        y /= divide;
        return *this;
    }

    Vertex operator+(const Vertex &input_vertex) const { return Vertex(*this) += input_vertex;}

    Vertex operator-(const Vertex &input_vertex) const { return Vertex(*this) -= input_vertex;}

    Vertex operator*(double times) const { return Vertex(*this) *= times;}

    Vertex operator/(double divide) const { return Vertex(*this) /= divide;}

    friend istream &operator>>(ifstream stream, Vertex &input_vertex) {
        return stream >> input_vertex.x >> input_vertex.y;
    }

    friend ostream &operator<<(ostream stream, const Vertex &input_vertex) {
        return stream << input_vertex.x << input_vertex.y;
    }

    double dot(const Vertex &input_vertex) const {
        return x * input_vertex.x + y * input_vertex.y;
    }

    double cross(const Vertex &input_vertex) const {
        return x * input_vertex.y - y * input_vertex.x;
    }

    double before_norm() const {
        return x * x + y * y;
    }

    double norm() const {
        return sqrt(before_norm());
    }

    Vertex rotate_orthant() const {
        return Vertex{y, -x};
    }

    Vertex rotate_theta(double theta) {
        return Vertex(cos(theta) * x - sin(theta) * y, sin(theta) * x + cos(theta) * y);
    }

    int orthant() const {
        if (x == 0 && y == 0) return 1;
        if (x > 0) return y > 0 ? 1 : 4;
        return y > 0 ? 2 : 3;
    }

    bool operator<(const Vertex &input_vertex) const {
        int my_orthant = orthant(), input_orthant = input_vertex.orthant();
        if (my_orthant != input_orthant) return my_orthant < input_orthant;
        return cross(input_vertex) > 0;
    }
};