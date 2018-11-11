PROGRAM = VirusDefender
CC      = g++
CFLAGS  = -g -ansi -Wall -std=c++17 -Wextra
LFLAGS  = -lglut -lGLU -lGL

$(PROGRAM): main.o
	$(CC) -o $(PROGRAM) main.o $(LFLAGS)

main.o : main.cpp
	$(CC) -c main.cpp -o main.o $(CFLAGS)

.PHONY: clean

clean:
	-rm *.o $(PROGRAM) *core

