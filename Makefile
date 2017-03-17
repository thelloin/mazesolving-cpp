CCC		= g++
CCFLAGS		= -std=c++14

INCFLAGS	= -I ~/dev/boost_1_63_0
LDFLAGS		= -lpng

solve: main.o
	${CCC} ${CCFLAGS} -o solve main.o ${LDFLAGS}

main.o: Maze.h main.cc
	${CCC} ${CCFLAGS} ${INCFLAGS} -c main.cc

maze.o: Maze.h
	${CCC} ${CCFLAGS} ${INCFLAGS} -c Maze.h

clean:
	rm solve *.o
