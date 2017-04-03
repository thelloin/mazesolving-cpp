#include "Maze.h"
#include <iostream>

#include <boost/make_shared.hpp>

Maze::Maze(boost::gil::rgb8_image_t* p_img) : width((int)p_img->width()),
					      height((int)p_img->height()),
					      maze(boost::extents[width][height]),
					      maze_visited(boost::extents[width][height]),
					      start(new Node),
					      end(new Node) {
    //std::cout << "In maze constructor" << std::endl;
    //std::cout << p_img->width() << ',' << p_img->height() << std::endl;


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

    /*
    // Print the bool array, for testing
    for (size_t y = 0; y < maze.shape()[1]; y++)
    {
	for ( size_t x = 0; x < maze.shape()[0]; x++)
	{
	    std::cout << maze[x][y] << '\t';
	}
	std::cout << '\n';
    }
    */

    // Top row buffer
    Node_ptr topNodes[width];
    // Start row
    for (int x = 1; x < width-1; x++)
    {
	if (maze[x][0] == true)
	{
	    //std::cout << "Found top pos at: " << x << '\n';
	    start->xpos = x, start->ypos = 0;
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

	Node_ptr leftNode(new Node());

	for (int x = 1; x < width - 1; x++)
	{
	    prv = cur;
	    cur = nxt;
	    nxt = maze[x + 1][y];

	    Node_ptr n(new Node());

	    if (cur == false) continue; // ON WALL - No action

	    if (prv == true)
	    {
		if (nxt == true)
		{
		    // PATH PATH PATH
		    // Create node only if paths above or below
		    if (maze[x][y-1] == true || maze[x][y+1] == true)
		    {
			n->xpos = x;
			n->ypos = y;
			leftNode->right = n;
			n->left = leftNode;
			leftNode = n;
		    }
		} else
		{
		    // PATH PATH WALL
		    // Create path at end of corridor
		    n->xpos = x;
		    n->ypos = y;
		    leftNode->right = n;
		    n->left = leftNode;
		    leftNode = NULL;
		}
	    } else
	    {
		if (nxt == true)
		{
		    // WALL PATH PATH
		    // Create path at start of corridor
		    n->xpos = x;
		    n->ypos = y;
		    leftNode = n;
		} else
		{
		    // WALL PATH WALL
		    // Create node only if in dead end
		    if (maze[x][y-1] == false || maze[x][y-1] == false)
		    {
			//std::cout << "Found a dead end at (" << x << ',' << y << ")\n";
			n->xpos = x;
			n->ypos = y;
		    }
		}
	    }

	    // If node's x and y isn't -1, we can assume we can connect N-S somewhere
	    if (n->xpos != -1) {
		// If clear above, connect to waiting top node
		if (maze[x][y - 1] == true)
		{
		    // Clear above, connect to waiting top node
		    Node_ptr temp = topNodes[x];
		    temp->down = n;
		    n->up = temp;
		}
		// If clear above, put this new node in the top row for the next connection
		if (maze[x][y + 1] == true)
		    topNodes[x] = n;
		else
		    topNodes[x] = boost::make_shared<Node>();
		
		count++;
	    }

	}
    }

    // End row
    for (int x = 1; x < width - 1; x++)
    {
	if (maze[x][height - 1] == true)
	{
	    end->xpos = x, end->ypos = height - 1;
	    Node_ptr temp = topNodes[x];
	    temp->down = end;
	    end->up = temp;
	    count++;
	    break;
	}
    }
}
