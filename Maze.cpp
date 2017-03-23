#include "Maze.h"
#include <iostream>

Maze::Maze(boost::gil::rgb8_image_t* p_img) : width((int)p_img->width()),
					      height((int)p_img->height()),
					      maze(boost::extents[width][height]),
					      maze_visited(boost::extents[width][height]),
					      start(-1, -1),
					      end(-1, -1) {
    std::cout << "In maze constructor" << std::endl;
    std::cout << p_img->width() << ',' << p_img->height() << std::endl;


    /*
     * Construct the maze as a 2d array representing walls and path in maze.
     */
    boost::gil::rgb8_pixel_t px;
    for (int i = 0; i < p_img->height(); i++)
    {
	for (int j = 0; j < p_img->width(); j++)
	{
	    px = *const_view(*p_img).at(j, i);
	    if (px[0] == 255)
	    {
		maze[j][i] = true;
	    }
	}
    }

    // Print the bool array
    for (size_t y = 0; y < maze.shape()[1]; y++)
    {
	for ( size_t x = 0; x < maze.shape()[0]; x++)
	{
	    std::cout << maze[x][y] << '\t';
	}
	std::cout << '\n';
    }

    // Top row buffer
    Node topNodes[width];
    // Start row
    for (int x = 1; x < width-1; x++)
    {
	if (maze[x][0] == true)
	{
	    //std::cout << "Found top pos at: " << x << '\n';
	    start.xpos = x, start.ypos = 0;
	    topNodes[x] = start;
	    count++;
	    break;
	}
    }

    for (int y = 1; y < height - 1; y++)
    {
	//std::cout << "Row: " << y << '\n';

	// Initialize previous, current and next values
	bool prv{false};
	bool cur{false};
	bool nxt{maze[1][y]};

	Node leftNode{};

	for (int x = 1; x < width - 1; x++)
	{
	    prv = cur;
	    cur = nxt;
	    nxt = maze[x + 1][y];

	    Node n{};

	    if (cur == false) continue; // ON WALL - No action

	    if (prv == true)
	    {
		
	    }
	}
    }
	
}
