CC = g++
FLAGS = -std=c++11

.PHONY: prim dijkstra

program: src/*.cpp src/*.h Makefile main.cpp
	$(CC) $(FLAGS) src/*.cpp main.cpp -o program

run:
	./program
