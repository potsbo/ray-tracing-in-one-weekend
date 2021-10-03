#ifndef RAY_H
#define RAY_H

#include "vec3.hpp"

class ray {
public:
  ray() {}
  ray(const point3 &origin, const vec3 &direction)
      : orig(origin), dir(direction) {}
  vec3 at(double t) const { return orig + t * dir; }

  vec3 direction() const { return dir; }
  vec3 origin() const { return orig; }

public:
  point3 orig;
  vec3 dir;
};

#endif
