cc = g++
cc_standard = -std=c++20
optflags = -O3
deps = $(wildcard algos/*.cpp)
debugflags = -Wall -pedantic -g
raylibflags = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
target = visualizer.cpp
outfile = main.out

all: clean build exec

build:
	$(cc) ${cc_standard} ${debugflags} ${libs} ${target} ${deps} ${libs} ${raylibflags} -o ${outfile}

exec:
	./${outfile}

clean:
	rm -rf *.out
