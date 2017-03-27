#include <iostream>

#include <boost/gil/extension/io/png_io.hpp>

#include "Maze.h"

using namespace std;
namespace gil = boost::gil;

void solve(char* ipath, char* opath)
{
    cout << "Reading image...\n";
    gil::rgb8_image_t img;
    gil::png_read_and_convert_image(ipath, img);

    cout << "Read complete, got an image " << img.width()
	 << " by " << img.height() << " pixels\n";

    gil::rgb8_pixel_t px;
    for(int i = 0; i < img.height(); i++)
    {
	for(int j = 0; j < img.width(); j++)
	{
	    px = *const_view(img).at(j, i);
	    cout << (int)px[0] << '\t';
	}
	cout << '\n';
    }


    // TODO: Time this and display node count in maze
    Maze maze{&img};
    cout << "Found " << maze.getCount() << " nodes in maze" << endl;

}

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
	cerr << "Usage is: " << argv[0] << " <infile> <outfile>\n";
	return 1;
    }
    solve(argv[1], argv[2]);

    /*gil::rgb8_pixel_t px;
    for(int i = 0; i < img.height(); i++)
    {
	for(int j = 0; j < img.width(); j++)
	{
	    px = *const_view(img).at(j, i);
	    cout << "The pixel at " << i << ',' << j << " is "
		 << (int)px[0] << ','
		 << (int)px[1] << ',' << (int)px[2] << '\n';
	}
	}*/
    /*gil::rgb8_pixel_t px1 = *const_view(img).at(0, 0);
    cout << "The pixel at 0,0 is "
	 << (int)px1[0] << ','
	 << (int)px1[1] << ',' << (int)px1[2] << '\n';
    gil::rgb8_pixel_t px2 = *const_view(img).at(0, 3);
    cout << "The pixel at 0,3 is "
	 << (int)px2[0] << ','
	 << (int)px2[1] << ',' << (int)px2[2] << '\n';
    */
    return 0;
}
