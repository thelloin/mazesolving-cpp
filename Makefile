CCC		= g++
CCFLAGS		= -std=c++14

INCFLAGS	= -I ~/dev/boost_1_63_0
LDFLAGS		= -lpng

solve: main.o Maze.o
	${CCC} ${CCFLAGS} -o solve main.o Maze.o ${LDFLAGS}

main.o: Maze.h main.cc
	${CCC} ${CCFLAGS} ${INCFLAGS} -c main.cc

Maze.o: Maze.h Maze.cpp
	${CCC} ${CCFLAGS} ${INCFLAGS} -c Maze.cpp

clean:
	rm solve *.o
