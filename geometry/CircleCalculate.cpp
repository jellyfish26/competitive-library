#include <bits/stdc++.h>
using namespace std;

// Last-Update 2020-05-15
class CircleCalculate {
public:
    static double radian_to_degree(double radian) {
        return radian * (180.0 / acos(-1));
    }

    static double degree_to_radian(double degree) {
        return degree * (acos(-1) / 180.0);
    }

    // warn: theta is radian
    static double calc_arc_length(double radius, double theta) {
        return radius * theta;
    }

    static double calc_chord_length(double radius, double theta) {
        return 2 * radius * sin(theta / 2);
    }
};