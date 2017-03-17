#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <boost/gil/extension/io/png_io.hpp>

class Maze
{
public:
    Maze(boost::gil::rgb8_image_t* p_img) : img(p_img) {
	std::cout << "In maze constructor" << std::endl;
	std::cout << img->width() << ',' << img->height() << std::endl;
    }
private:
    boost::gil::rgb8_image_t* img;
};

#endif // MAZE_H
