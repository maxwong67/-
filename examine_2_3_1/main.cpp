#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
Mat src1,gray_src,src2,dst;
int main()
{
    string path = "D:/opencv/packages/img/board.jpg";
    Mat img = imread(path);
    Mat imgGray, imgBlur, imgCanny, imgDil, imgErode;

    cvtColor(img, imgGray, COLOR_BGR2GRAY); //灰度化
    GaussianBlur(img, imgBlur, Size(3, 3), 3, 0); //高斯模糊
    Canny(imgBlur, imgCanny, 25, 75); //边缘检测

    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(imgCanny, imgDil, kernel);
    erode(imgDil, imgErode, kernel);


    imshow("Image", img);
    imshow("ImageGray", imgGray);
    imshow("ImageBlur", imgBlur);
    imshow("ImageCanny", imgCanny);
    imshow("ImageDilation", imgDil);
    imshow("ImageErode", imgErode);

    Mat src1,gray_src,src2,dst;

    src1 = imread("D:/opencv/packages/img/board.jpg");
    if (src1.empty())
    {
        cout << "could not find src1" << endl;
        return -1;
    }
    namedWindow("input", WINDOW_AUTOSIZE);//namedWindow( "hsv adjust", WINDOW_AUTOSIZE );
    imshow("input", src1);
    //霍夫直线   canny边缘提取 --> cvtcolor转灰度 --> HoughLinesP霍夫边缘检测
    cvtColor(src1,src1,COLOR_BGR2GRAY);
    Canny(src1,gray_src,100,200,3,false);
    cvtColor(gray_src,dst,COLOR_GRAY2BGR);
    vector<Vec4f> lines;
    //'1'生成极坐标时候的像素扫描步长，'CV_PI/180'生成极坐标时候的角度步长，'10'最小直线长度，'0'最大间隔（能构成一条直线）
    HoughLinesP(gray_src,lines,1,CV_PI/180,10,0,0);
    Scalar color = Scalar(0,0,255);
    for (size_t i = 0; i < lines.size(); i++)
    {
        Vec4f plines=lines[i];  //一个plines里边是四个点一条直线
        line(dst,Point(plines[0],plines[1]),Point(plines[2],plines[3]),color,3,LINE_AA);
    }
    imshow("output", dst);





    waitKey(0);

    return 0;
}
