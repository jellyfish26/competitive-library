#pragma once
#include <cmath>
#include <istream>

// Last Update 2021-02-19
class Vertex {
public:
    double x, y;

    Vertex();
    Vertex(double x, double y);
    Vertex(const Vertex &vt);

    double dot(const Vertex &target) const;
    double cross(const Vertex &target) const;

    double before_norm() const;
    double norm() const;
    int orthant() const;

    Vertex rotate_orthant() const;
    Vertex rotate_theta(double theta) const;

    Vertex &operator+=(const Vertex &target);
    Vertex &operator-=(const Vertex &target);
    Vertex &operator*=(double times);
    Vertex &operator/=(double div);

    Vertex operator+(const Vertex &target) const;
    Vertex operator-(const Vertex &target) const;
    Vertex operator*(double times) const;
    Vertex operator/(double div) const;

    Vertex &operator=(const Vertex &target);

    bool operator<(const Vertex &target) const;

    friend std::istream &operator>>(std::istream &stream, Vertex &target);
    friend std::ostream &operator<<(std::istream &stream, Vertex &target);
};

Vertex::Vertex() : x(0), y(0) {}
Vertex::Vertex(double x, double y) : x(x), y(y) {}
Vertex::Vertex(const Vertex &target) : x(target.x), y(target.y) {}

double Vertex::dot(const Vertex &target) const {
    return x * target.x + y * target.y;
}

double Vertex::cross(const Vertex &target) const {
    return x * target.y - y * target.x;
}

double Vertex::before_norm() const {
    return x * x + y * y;
}

double Vertex::norm() const {
    return std::sqrt(before_norm());
}

int Vertex::orthant() const {
    if (x == 0 && y == 0) return 1;
    if (x > 0) return y > 0 ? 1 : 4;
    return y > 0 ? 2 : 3;
}


Vertex Vertex::rotate_orthant() const {
    return Vertex{y, -x};
}

Vertex Vertex::rotate_theta(double theta) const {
    return Vertex(cos(theta) * x - sin(theta) * y, sin(theta) * x + cos(theta) * y);
}


Vertex &Vertex::operator+=(const Vertex &target) {
    x += target.x;
    y += target.y;
    return *this;
}

Vertex &Vertex::operator-=(const Vertex &target) {
    x -= target.x;
    y -= target.y;
    return *this;
}

Vertex &Vertex::operator*=(double times) {
    x *= times;
    y *= times;
    return *this;
}

Vertex &Vertex::operator/=(double divide) {
    x /= divide;
    y /= divide;
    return *this;
}

Vertex Vertex::operator+(const Vertex &target) const {
    return Vertex(*this) += target;
}

Vertex Vertex::operator-(const Vertex &target) const {
    return Vertex(*this) -= target;
}

Vertex Vertex::operator*(double times) const {
    return Vertex(*this) *= times;
}
Vertex Vertex::operator/(double divide) const {
    return Vertex(*this) /= divide;
}

Vertex &Vertex::operator=(const Vertex &target) {
    this->x = target.x;
    this->y = target.y;
    return *this;
};

bool Vertex::operator<(const Vertex &target) const {
    int my_orthant = orthant(), input_orthant = target.orthant();
    if (my_orthant != input_orthant) return my_orthant < input_orthant;
    return cross(target) > 0;
}

std::istream &operator>>(std::istream &stream, Vertex &target) {
    return stream >> target.x >> target.y;
}

std::ostream &operator<<(std::ostream &stream, const Vertex &target) {
    return stream << target.x << target.y;
}
