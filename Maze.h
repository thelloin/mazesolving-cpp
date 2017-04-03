#ifndef MAZE_H
#define MAZE_H

#include <boost/gil/extension/io/png_io.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/multi_array.hpp>



typedef boost::multi_array<bool, 2> array_type;
typedef array_type::index index_t;


//typedef boost::shared_ptr<Node> Node_ptr;

struct Node {
    Node() : xpos(-1), ypos(-1) {}
    Node(int x, int y) : xpos(x), ypos(y)  {}

    // TODO: use a pair instead of xpos and ypos
    int xpos;
    int ypos;
    boost::shared_ptr<Node> up{NULL};
    boost::shared_ptr<Node> down{NULL};
    boost::shared_ptr<Node> left{NULL};
    boost::shared_ptr<Node> right{NULL};
};

using Node_ptr = boost::shared_ptr<Node>;

class Maze
{
public:
    Maze(boost::gil::rgb8_image_t* p_img);

    int getCount() { return count; };
    
    int width{};
    int height{};
    array_type maze;
    array_type maze_visited;
    Node_ptr start;
    Node_ptr end;
    int count{};
private:
    
};

#endif // MAZE_H
