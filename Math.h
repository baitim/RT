#ifndef MATH_H
#define MATH_H

#include <stdio.h>
#include <math.h>

#define MAX(a, b) ((a) > (b)) ? (a) : (b) 
#define MIN(a, b) ((a) < (b)) ? (a) : (b) 

struct Vect2 {
    double x, y;

    Vect2(double _x, double _y) : x(_x), y(_y) {}
    Vect2(double value) : x(value), y(value) {}

    Vect2 operator+(Vect2 const &other) { return Vect2(x + other.x, y + other.y); }
    Vect2 operator-(Vect2 const &other) { return Vect2(x - other.x, y - other.y); }
    Vect2 operator*(Vect2 const &other) { return Vect2(x * other.x, y * other.y); }
    Vect2 operator/(Vect2 const &other) { return Vect2(x / other.x, y / other.y); }

    double len() { return sqrt((double)(x * x + y * y)); }

    void show() { fprintf(stderr, "x = %lf\ty = %lf\n", x, y); }
};

struct Vect3 {
    double x, y, z;

    Vect3(double _x, Vect2 const &_v) : x(_x), y(_v.x), z(_v.y) {}
    Vect3(double _x, double _y, double _z) : x(_x), y(_y), z(_z) {}
    Vect3(double value) : x(value), y(value), z(value) {}

    Vect3 operator+(Vect3 const &other) { return Vect3(x + other.x, y + other.y, z + other.z); }
    Vect3 operator-(Vect3 const &other) { return Vect3(x - other.x, y - other.y, z - other.z); }
    Vect3 operator*(Vect3 const &other) { return Vect3(x * other.x, y * other.y, z * other.z); }
    Vect3 operator/(Vect3 const &other) { return Vect3(x / other.x, y / other.y, z / other.z); }

    double len() { return sqrt((double)(x * x + y * y + z * z)); }

    void show() { fprintf(stderr, "x = %lf\ty = %lf\tz = %lf\n", x, y, z); }
};

// struct Sphere {
//     Vect3 v;
//     double r;

//     Sphere(Vect3 _v, double _r) : v(_v), r(_r) {}
//     Sphere(double _x, double _y, double _z, double _r) : v(_x, _y, _z), r(_r) {}
//     Sphere(double value, double _r) : v(value, value, value), r(_r) {}
//     Sphere(double value) : v(value, value, value), r(1.0f) {}

//     Sphere operator+(Sphere const &other) { return Sphere(v + other.v, r + other.r); }
//     Sphere operator-(Sphere const &other) { return Sphere(v - other.v, r - other.r); }
//     Sphere operator*(Sphere const &other) { return Sphere(v * other.v, r * other.r); }
//     Sphere operator/(Sphere const &other) { return Sphere(v / other.v, r / other.r); }
//     Sphere operator+(Vect3 const &other) { return Sphere(v + other, r); }
//     Sphere operator-(Vect3 const &other) { return Sphere(v - other, r); }
//     Sphere operator*(Vect3 const &other) { return Sphere(v * other, r); }
//     Sphere operator/(Vect3 const &other) { return Sphere(v / other, r); }

//     void show() { fprintf(stderr, "x = %lf\ty = %lf\tz = %lf\tr = %lf\n", v.x, v.y, v.z, r); }
// };

double dist(Vect2 const &a, Vect2 const &b);
double dist(Vect3 const &a, Vect3 const &b);
Vect2 normalize(Vect2 v);
Vect3 normalize(Vect3 v);
double mul(Vect2 const &a, Vect2 const &b);
double mul(Vect3 const &a, Vect3 const &b);
Vect2 intersection_sphere(Vect3 v, Vect3 dir, double r);

#endif // MATH_H