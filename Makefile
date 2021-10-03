SOURCES = $(wildcard *.cpp)
HEADERS = $(wildcard *.hpp)

OBJECTS = $(SOURCES:%.cpp=%.o)
PROGRAM = $(shell basename `pwd`)

CC := clang++
CFLAGS := -std=c++14 -Wall -O3

$(PROGRAM): $(OBJECTS)
	$(CC) -o $@ $<

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c -o $@ $<

image.ppm: $(PROGRAM)
	./$< > $@

.PHONY: open
open: image.ppm
	open $<

.PHONY: clean
clean:
	rm -f image.ppm $(PROGRAM) $(OBJECTS)
