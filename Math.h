#ifndef MATH_H
#define MATH_H

#include <math.h>

#define MAX(a, b) ((a) > (b)) ? (a) : (b) 
#define MIN(a, b) ((a) < (b)) ? (a) : (b) 

struct Vect {
    double x, y;

    Vect(double _x, double _y) : x(_x), y(_y) {}
    Vect(double value) : x(value), y(value) {}

    Vect operator+(Vect const &other) {
        return Vect(x + other.x, y + other.y);
    }

    Vect operator-(Vect const &other) {
        return Vect(x - other.x, y - other.y);
    }

    Vect operator*(Vect const &other) {
        return Vect(x * other.x, y * other.y);
    }

    Vect operator/(Vect const &other) {
        return Vect(x / other.x, y / other.y);
    }

    const double len() {
        return sqrt((double)(x * x + y * y));
    }
};

const double dist(double x, double y);

#endif // MATH_H