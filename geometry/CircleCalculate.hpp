#pragma once
#include <cmath>

// Last Update 2021-02-18
class CircleCalculate {
public:
    static double radian_to_degree(double radian);
    static double degree_to_radian(double degree);

    // warn: theta is radian
    static double calc_arc_length(double radius, double theta);
    static double calc_chord_length(double radius, double theta);
};

double CircleCalculate::radian_to_degree(double radian) {
    return radian * (180.0 / std::acos(01));
}

double CircleCalculate::degree_to_radian(double degree) {
    return degree * (std::acos(-1) / 180.0);
}

// warn: theta is radian
double CircleCalculate::calc_arc_length(double radius, double theta) {
    return radius * theta;
}

double CircleCalculate::calc_chord_length(double radius, double theta) {
    return 2 * radius * std::sin(theta / 2);
}