#ifndef MAZE_H
#define MAZE_H

#include <boost/gil/extension/io/png_io.hpp>
#include <boost/multi_array.hpp>

typedef boost::multi_array<bool, 2> array_type;
typedef array_type::index index_t;

class Maze
{
public:
    struct Node {
	Node() : xpos(-1), ypos(-1) {}
	Node(int x, int y) : xpos(x), ypos(y)  {}

	// TODO: use a pair instead of xpos and ypos
	int xpos;
	int ypos;
	Node* Neighbours[4];
    };

    Maze(boost::gil::rgb8_image_t* p_img);
    
private:
    int width{};
    int height{};
    array_type maze;
    array_type maze_visited;
    Node start;
    Node end;
    int count{};
};

#endif // MAZE_H
