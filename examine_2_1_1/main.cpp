#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
    string path = "D://opencv//packages//img//RM.png";
    Mat img = imread(path);
    Mat imgGray,imgBlur;


    cvtColor(img, imgGray, COLOR_BGR2GRAY); //灰度化
    GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0); //高斯模糊

    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));


    imshow("Image", img);
    imshow("ImageBlur", imgBlur);
    waitKey(0);

    return 0;
}

