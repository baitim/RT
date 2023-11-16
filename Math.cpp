#include "Math.h"

double dist(Vect2 const &a, Vect2 const &b) { return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)); }
double dist(Vect3 const &a, Vect3 const &b) { return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z)); }

Vect2 normalize(Vect2 v) { return v / v.len(); }
Vect3 normalize(Vect3 v) { return v / v.len(); }

double mul(Vect2 const &a, Vect2 const &b) { return a.x * b.x + a.y * b.y; }
double mul(Vect3 const &a, Vect3 const &b) { return a.x * b.x + a.y * b.y + a.z * b.z; }

Vect2 intersection_sphere(Vect3 V, Vect3 dir, double r)
{
    double a = -mul(V, dir);
    double b = mul(V, V) - r * r;
    double dist = a * a - b;

    if (dist < 0.0f) return Vect2(-1.0);

    return Vect2(a - sqrt(dist), a + sqrt(dist));
}