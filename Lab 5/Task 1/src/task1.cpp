#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <vector>
#include </home/local/furcann17861/Lab/5/Task 1/header/watershed.h>

using namespace std;
using namespace cv;


int main(int argc, char* argv[]){
    
    Mat image = imread("../Asphalt-1.png");
    Mat image1 = imread("../Asphalt-2.png");
    Mat image2 = imread("../Asphalt-3.png");

    Mat hsvImg, hsvImg1, hsvImg2;
    //divide the images into channels using hsv to detect different colors
    cvtColor(image, hsvImg, cv::COLOR_BGR2HSV);
    cvtColor(image1, hsvImg1, cv::COLOR_BGR2HSV);
    cvtColor(image2, hsvImg2, cv::COLOR_BGR2HSV);
  
    Mat threshImg, threshImg1, threshImg2;
    //black color to detect the crack
    inRange(hsvImg, Scalar(0,0,0),Scalar(30,30,30), threshImg);
    inRange(hsvImg1, Scalar(0,0,0),Scalar(51, 51, 51), threshImg1);
    inRange(hsvImg2, Scalar(0,0,0),Scalar(1, 1, 1), threshImg2);
    
    //remove noise
    GaussianBlur(threshImg, threshImg, Size(3,3),0, 0, BORDER_DEFAULT);
    GaussianBlur(threshImg1, threshImg1, Size(3,3),0, 0, BORDER_DEFAULT);
    GaussianBlur(threshImg2, threshImg2, Size(3,3),0, 0, BORDER_DEFAULT);

    imshow("Threshold", threshImg);
    waitKey(0);

    imshow("Threshold1", threshImg1);
    waitKey(0);

    imshow("Threshold2", threshImg2);
    waitKey(0);

    return 0;
}
