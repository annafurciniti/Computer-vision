#include <opencv2/core/utility.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

#include <stdio.h>


using namespace std;
using namespace cv;


int main(int argc, char* argv[]){


    Mat image = cv::imread("../robocup.jpg");
    //divide channels
    Mat hsvImg, threshImg;
    cvtColor(image, hsvImg, cv::COLOR_BGR2HSV);
  
    //yellow color
    inRange(hsvImg, Scalar(20, 100, 100), Scalar(30, 255, 255), threshImg);
    imshow("thresh.png", threshImg);
    
    waitKey(0);
    

    return 0;
}
