.PHONY: open
open: image.ppm
	open $<

.PHONY: clean
clean:
	rm image.ppm raytracing

image.ppm: raytracing
	./$< > $@

raytracing: main.cpp
	clang++ -std=c++14 $< -Wall -o $@
