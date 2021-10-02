#ifndef VEC3_H
#define VEC3_H

#include "random.hpp"
#include <cmath>
#include <iostream>

class vec3 {
public:
  vec3() : e{0, 0, 0} {}
  vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

  vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }

  double x() const { return e[0]; }
  double y() const { return e[1]; }
  double z() const { return e[2]; }
  inline static vec3 random() {
    return vec3(random_double(), random_double(), random_double());
  }

  inline static vec3 random(double min, double max) {
    return vec3(random_double(min, max), random_double(min, max),
                random_double(min, max));
  }

  vec3 &operator+=(const vec3 &v) {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
  }

  double length() const { return sqrt(length_squared()); }

  double length_squared() const {
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
  }

public:
  double e[3];
};

inline vec3 operator+(vec3 v1, vec3 v2) {
  return vec3(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() + v2.z());
}
inline vec3 operator-(vec3 v1, vec3 v2) { return v1 + (-v2); }

inline vec3 operator*(double t, vec3 v) {
  return vec3(v.x() * t, v.y() * t, v.z() * t);
}

inline vec3 operator*(vec3 v, double t) { return t * v; }
inline vec3 operator/(vec3 v, double t) { return (1 / t) * v; }
inline double dot(const vec3 &u, const vec3 &v) {
  return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

inline vec3 unit_vector(vec3 v) { return v / v.length(); }

using point3 = vec3;
using color = vec3;
#endif
