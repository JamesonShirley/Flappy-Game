all: compile

compile:
	g++ -o main game/main.cpp -lpng -lstdc++fs -lGL -lGLU -pthread -lX11

run:
	./main

test: compile run
