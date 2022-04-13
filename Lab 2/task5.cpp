#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv){
    //load directly gray_img
    Mat img = cv::imread("/home/local/furcann17861/Lab/2/Lab2/gray_img.jpg" ,IMREAD_GRAYSCALE);
    //cv::cvtColor(img, gray_img,COLOR_BGR2GRAY);
    //cv::imwrite("/home/local/furcann17861/Lab/2/Lab2/gray_img.jpg", gray_img);
    
	//equalization histogram
	Mat hist_equalized_image, outImg;
	equalizeHist(img, hist_equalized_image);
	imshow( "Gray image", img);
	resize(hist_equalized_image, outImg, cv::Size(), 0.60, 0.60);
	imshow("equalizationHist", outImg);
    waitKey(0);

    return 0;
    
}
