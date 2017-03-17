#include <iostream>

//#include <boost/gil/gil_all.hpp>
#include <boost/gil/extension/io/png_io.hpp>
//#include <boost/gil/extension/io/png_dynamic_io.hpp>
//#include <boost/mpl/vector.hpp>
//#include <boost/gil/extension/io/jpeg_io.hpp>

using namespace std;
namespace gil = boost::gil;

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
	cerr << "Usage is: " << argv[0] << " <infile> <outfile>\n";
	return 1;
    }
    /*typedef boost::mpl::vector<
	boost::gil::gray8_image_t,
	boost::gil::bgr8_image_t,
	boost::gil::argb8_image_t,
        boost::gil::rgb8_image_t,
        boost::gil::rgb8_planar_image_t, 
        boost::gil::cmyk8_image_t,
        boost::gil::cmyk8_planar_image_t, 
        boost::gil::rgba8_image_t, 
        boost::gil::rgba8_planar_image_t
     > my_img_types;
    cout << "We are here" << endl;
    boost::gil::any_image<my_img_types> input;
    boost::gil::png_read_image(argv[1], input);
    cout << "We are here1" << endl;*/
    //gil::rgb8_image_t img;
    gil::rgb8_image_t img;
    cout << "trying to read in file: " << argv[1] << endl;
    gil::png_read_and_convert_image(argv[1], img);
    //gil::png_read_and_convert_image(argv[1], img);
    cout << "Read complete, got an image " << img.width()
	 << " by " << img.height() << " pixels\n";

    return 0;
}
