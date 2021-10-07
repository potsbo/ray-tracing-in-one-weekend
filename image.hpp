#ifndef IMAGE_H
#define IMAGE_H

#include "rtweekend.hpp"
#include <vector>

class image {
public:
  image(const int h, const int w) : height(h), width(w) {
    for (int i = 0; i < h * w; ++i) {
      pixels.push_back(color());
    }
    sample_size = 0;
  }
  image(const int h, const int w, const std::vector<color> new_pixels,
        const int sample_size)
      : height(h), width(w), pixels(new_pixels), sample_size(sample_size) {}

  image &operator+=(const image &img) {
    for (int i = 0; i < pixels.size(); ++i) {
      pixels[i] += img.pixels[i];
    }
    sample_size += img.sample_size;
    return *this;
  }

public:
  int height;
  int width;
  std::vector<color> pixels;
  int sample_size;
};

#endif
