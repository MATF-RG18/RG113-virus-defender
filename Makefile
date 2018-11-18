PROGRAM = VirusDefender
CC      = g++
CFLAGS  = -g -ansi -Wall -std=c++17 -Wextra -I/include
LFLAGS  = -lglut -lGLU -lGL
SRCDIR = src

$(PROGRAM): main.o
	$(CC) -o $(PROGRAM) main.o $(LFLAGS)

main.o : $(SRCDIR)/main.cpp
	$(CC) -c $(SRCDIR)/main.cpp -o main.o $(CFLAGS)

.PHONY: clean

clean:
	-rm *.o $(PROGRAM) *core

