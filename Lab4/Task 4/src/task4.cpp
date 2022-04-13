#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main(int argc, char** argv){

    int thresh_max =250;
    int thresh =200;
    Mat outImgGB, gray_img, canny_image;

    Mat img = imread("../street_scene.png");
    
    cvtColor(img, gray_img, COLOR_BGR2GRAY);
    GaussianBlur(gray_img, outImgGB, Size(7,7), 0, 0);
    Canny(outImgGB, canny_image, thresh, thresh_max, 3, true);
    
    Mat out = img.clone();
    vector<Vec3f> circles;

   // Apply the Hough Transform to find the circles. This function without correct paramters doesn't work very well. whith 1 instead of 2 doesn't work
   HoughCircles(canny_image, circles, cv::HOUGH_GRADIENT, 2, canny_image.rows/2, 50, 30, 6, 8);

   // Draw the circles detected
   for( size_t i = 0; i < circles.size(); i++ ){
      Vec3i c = circles[i];     
      circle(out, Point(c[0], c[1]), c[2], Scalar(0,255, 0), 3, cv::LINE_AA); // circle center  
      circle(out, Point(c[0], c[1]), 2, Scalar(0,255,0), 3, cv::LINE_AA); // circle outline
   }

    imshow("HoughCircles", out);
    waitKey(0);

    
    return 0;
    
}

