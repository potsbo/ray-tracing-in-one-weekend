.PHONY: open
open: image.ppm
	open $<

image.ppm: raytracing
	./$< > $@

raytracing: main.cpp
	clang++ -std=c++14 $< -Wall -o $@
