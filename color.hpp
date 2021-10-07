#ifndef COLOR_H
#define COLOR_H

#include "image.hpp"
#include "vec3.hpp"
#include <iostream>
#include <vector>

inline double clamp(double x, double min, double max) {
  if (x < min)
    return min;
  if (x > max)
    return max;
  return x;
}

void write_color(std::ostream &out, color pixel_color, int samples_per_pixel) {
  auto r = pixel_color.x();
  auto g = pixel_color.y();
  auto b = pixel_color.z();

  auto scale = 1.0 / samples_per_pixel;
  r = sqrt(scale * r);
  g = sqrt(scale * g);
  b = sqrt(scale * b);

  out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
      << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
      << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << "\n";
}

inline void write_colors(std::ostream &out, image img) {

  std::cerr << "img.sample_size" << img.sample_size << "\n";
  for (auto c : img.pixels) {
    write_color(out, c, img.sample_size);
  }
}
#endif
