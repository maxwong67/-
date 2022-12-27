#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;
Mat src, erosion_dst;
int erosion_elem = 0;
int erosion_size = 0;

int const max_elem = 2;
int const max_kernel_size = 21;
void Erosion( int, void* );

int main( int argc, char** argv )
{
  src = imread( "D://opencv//packages//img//RM.png", IMREAD_COLOR );
  if( src.empty() )
  {
    cout << "Could not open or find the image!\n" << endl;
    cout << "Usage: " << argv[0] << " <Input image>" << endl;
    return -1;
  }
  namedWindow( "hsv adjust", WINDOW_AUTOSIZE );

  createTrackbar( "h-max", "hsv adjust", &erosion_elem, max_elem,Erosion );
  createTrackbar( "h-min", "hsv adjust", &erosion_size, max_kernel_size, Erosion );
  createTrackbar( "s-max", "hsv adjust", &erosion_elem, max_elem,Erosion );
  createTrackbar( "s-min", "hsv adjust", &erosion_size, max_kernel_size, Erosion );
  createTrackbar( "v-max", "hsv adjust", &erosion_elem, max_elem,Erosion );
  createTrackbar( "v-min", "hsv adjust", &erosion_size, max_kernel_size, Erosion );
  Erosion( 0, 0 );
  string path = "D://opencv//packages//img//RM.png";
  Mat img = imread(path);
  imshow("Image", img);
  waitKey(0);
  return 0;
}
void Erosion( int, void* )
{
  int erosion_type = 0;
  if( erosion_elem == 0 ){ erosion_type = MORPH_RECT; }
  else if( erosion_elem == 1 ){ erosion_type = MORPH_CROSS; }
  else if( erosion_elem == 2) { erosion_type = MORPH_ELLIPSE; }
  Mat element = getStructuringElement( erosion_type,
                       Size( 2*erosion_size + 1, 2*erosion_size+1 ),
                       Point( erosion_size, erosion_size ) );
  erode( src, erosion_dst, element );
  imshow( "hsv adjust", erosion_dst );
}
