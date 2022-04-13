#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <iostream>
#include </home/local/furcann17861/Lab/4/Task 2/header/edges.h>

using namespace cv;
using namespace std;

int main(int argc, char** argv){

    Mat img = imread("../street_scene.png");
    
    Mat outImgGB, gray;
    //remove noise before canny that is sensitive to noise. Without this step the image and the detection of lines was less precise
    GaussianBlur(img, outImgGB, Size(3,3),0, 0, BORDER_DEFAULT);
    //convert image to grayscale
    cvtColor(outImgGB, gray, COLOR_BGR2GRAY);
    //sobel function
    Mat out = edge(gray);
    
    imshow("Sobel", out);
    waitKey(0);

    //create a mask
    Mat mask(out.rows, out.cols, out.type());
    //access pixels and search for white pixels
    for(int i=0; i<out.rows; i++){
        for(int j=0; j<out.cols; j++){
            //substitution
            if (out.at<unsigned char>(i,j)==255){
				mask.at<unsigned char>(i, j) = out.at<unsigned char>(i, j);
				}
        }}
    
    
    imshow("White", mask);
    waitKey(0);

    return 0;
}
