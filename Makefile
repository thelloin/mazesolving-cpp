CCC		= g++
CCFLAGS		= -std=c++14

INCFLAGS	= -I ~/dev/boost_1_63_0
LDFLAGS		= -lpng

solve: main.o
	${CCC} ${CCFLAGS} -o solve main.o ${LDFLAGS}

main.o: main.cc
	${CCC} ${CCFLAGS} ${INCFLAGS} -c main.cc

clean:
	rm solve *.o
