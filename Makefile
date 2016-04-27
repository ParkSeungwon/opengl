CFLAG = -std=c++11 -lpthread -g -I/usr/include/libdrm -I/usr/include/GL
LIBS = -lGLU -lGL -lglut
CC = g++
SRC = $(wildcard *.cpp)
ccSRC = $(wildcard *.cc)
CSRC = $(wildcard *.C)
EXE = $(patsubst %.cpp, %.x, $(SRC))
EXE2 = $(patsubst %.C, %.x, $(CSRC))
OBJ = $(patsubst %.cc, %.o, $(ccSRC))

all : $(EXE) $(EXE2) 

%.x : %.cpp
	$(CC) $< -o $@ $(CFLAG) $(LIBS)

%.o : %.cc
	$(CC) -c $< $(CFLAG)

%.x : %.C $(OBJ)
	$(CC) $< -o $@ $(CFLAG) $(LIB) $(OBJ)
#	./$@

clean:
	rm $(EXE) $(OBJ)
