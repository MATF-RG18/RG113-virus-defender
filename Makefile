CC      = g++
CXXFLAGS  = -g -Wall -std=c++17 -Wextra
CPPFLAGS  = -lglut -lGLU -lGL

SRC_FILES := $(wildcard *.cpp)
OBJ_FILES := $(patsubst %.cpp, %.o, $(SRC_FILES))

main: $(OBJ_FILES)
	$(CC) -o $@ $^ $(CPPFLAGS)

%.o: %.cpp
	$(CC) $(CXXFLAGS) -c -o $@ $< $(CPPFLAGS)


.PHONY: clean

clean:
	-rm *.o $(PROGRAM) *core

