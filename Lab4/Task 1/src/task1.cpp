#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat gray_img,outImgGB, canny_image;
int thresh_max =200;
int thresh =150;
    
void trackChange(int, void*){
    
    //refresh
    if(thresh >= 1){
        GaussianBlur(gray_img, outImgGB, Size(3,3),0, 0, BORDER_DEFAULT);
        //input, output, low threshold, high threshold
        Canny(outImgGB, canny_image, thresh, thresh_max, 3, true);
        imshow("Canny Window", canny_image);
        }
}

int main(int argc, char** argv){
    
    Mat img = imread("../street_scene.png");
    imshow("Image", img);
    waitKey(0);
    //convert image to grayscale
    cvtColor(img, gray_img, COLOR_BGR2GRAY);
    namedWindow("Canny Window", WINDOW_AUTOSIZE);
    
    createTrackbar("Threshold","Canny Window",&thresh,thresh_max,trackChange);
    trackChange(0,0);
    
    waitKey(0);
    
    return 0;
    
}
