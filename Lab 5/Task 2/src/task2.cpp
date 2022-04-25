#include <opencv2/core/utility.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

#include <stdio.h>


using namespace std;
using namespace cv;

int main(int argc,const char** argv){

    Mat img = imread("../street_scene.png");

    Mat hsvImg, threshImg, threshImg1;
    //divide the image into channels using hsv to detect different colors
    cvtColor(img, hsvImg, cv::COLOR_BGR2HSV);
  
    //blu color to detect the sky
    inRange(hsvImg, Scalar(0, 0, 255),Scalar(204,255,255), threshImg);
    //gray color to detect the street
    inRange(hsvImg, Scalar(0, 0, 70),Scalar(180, 20, 255), threshImg1);
    //combine two masks
    Mat threshold = max(threshImg, threshImg1);

    imshow("Threshold", threshold);
    waitKey(0);
    
    return 0;
    
  }
