#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include </home/local/furcann17861/Lab/2/task2.h>

using namespace cv;

int main(int argc, char** argv){
    Mat gray_img, outImg;
    
    int kernel_sz =3;
    
    Mat img = imread("/home/local/furcann17861/Lab/2/Lab2/gray_img.jpg", IMREAD_GRAYSCALE);
    //cv::cvtColor(img, gray_img,COLOR_BGR2GRAY);
    //cv::imwrite("/home/local/furcann17861/Lab/2/Lab2/gray_img.jpg", gray_img);
    resize(img, outImg, cv::Size(), 0.30, 0.30);
    imshow( "Gray image", outImg);

    //task2
    Mat outMax;
    Mat Max = max(img, kernel_sz);
    cv::resize(Max, outMax, cv::Size(), 0.50, 0.50);
    cv::imshow("Max", outMax);

    Mat outMin;
    Mat Min = min(img, kernel_sz);
    resize(Min, outMin, cv::Size(), 0.50, 0.50);
    imshow("Min", outMin);
    
    //task3
    Mat outImgMB, outRImgMB, outImgGB, outRImgGB;
    
    medianBlur(img, outImgMB, 9);
    resize(outImgMB, outRImgMB, Size(), 0.60, 0.60);
    imshow("Median", outRImgMB);
    
    GaussianBlur(img, outImgGB, Size(7,7), 0, 0);
    resize(outImgGB, outRImgGB, Size(), 0.60, 0.60);
    imshow("Gaussian", outRImgGB);
    waitKey(0);
    
    return 0;
    
}
