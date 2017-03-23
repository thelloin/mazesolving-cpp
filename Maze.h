#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <boost/gil/extension/io/png_io.hpp>
#include <boost/multi_array.hpp>

typedef boost::multi_array<bool, 2> array_type;
typedef array_type::index index_t;

class Maze
{
public:
    struct Node {
	Node() {
	    position = -1;
	}
	Node(int pos) {
	    position = pos;
	}
	int position;
	Node* Neighbours[4];
    };

    Maze(boost::gil::rgb8_image_t* p_img) : width((int)p_img->width()),
					    height((int)p_img->height()),
					    maze(boost::extents[width][height]),
	                                    maze_visited(boost::extents[width][height]),
					    start(-1),
					    end(-1) {
	std::cout << "In maze constructor" << std::endl;
	std::cout << p_img->width() << ',' << p_img->height() << std::endl;


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
	
	
	for (size_t y = 0; y < maze.shape()[1]; y++)
	{
	    for ( size_t x = 0; x < maze.shape()[0]; x++)
	    {
		std::cout << maze[x][y] << '\t';
	    }
	    std::cout << '\n';
	}

	// Top row buffer
	Node topnodes[width];
	for (int x = 1; x < width-1; x++)
	{
	    if (maze[x][0] == true)
	    {
		std::cout << "Found top pos at: " << x << '\n';
	    }
	}
	
    }
private:
    //boost::gil::rgb8_image_t* img;
    int width{};
    int height{};
    array_type maze;
    array_type maze_visited;
    Node start;
    Node end;
    int count{};
};

#endif // MAZE_H
