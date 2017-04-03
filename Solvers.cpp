// Solvers.cpp

#include "Solvers.h"
#include <iostream>
#include <deque>
#include <vector>

namespace solvers
{
    void breadthfirst(Maze maze)
    {
	std::cout << "In breadthfirst" << std::endl;
	//Node_ptr start = maze.start;
	//Node_ptr end = maze.end;

	//int width = maze.width;

	std::deque<Node_ptr> queue;
	queue.push_back(maze.start);

	
	
    }

    void depthfirst()
    {
	std::cout << "In depthfirst" << std::endl;
    }
}
