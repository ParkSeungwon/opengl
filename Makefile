CFLAG = -std=c++11 -lpthread -g -I/usr/include/libdrm -I/usr/include/GL
LIBS = -lGLU -lGL -lglut
CC = g++
SRC = $(wildcard *.cpp)
EXE = $(patsubst %.cpp, %.x, $(SRC))

all : $(EXE)

%.x : %.cpp
	$(CC) $< -o $@ $(CFLAG) $(LIBS)
#	./$@

clean:
	rm $(EXE)
