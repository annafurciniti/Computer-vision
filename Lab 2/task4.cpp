#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include "opencv2/opencv.hpp"

using namespace cv;
using namespace std;

int main(int argc, char** argv){
    //load directly gray_img
    Mat img = imread("/home/local/furcann17861/Lab/2/Lab2/gray_img.jpg", IMREAD_GRAYSCALE);
    //cv::cvtColor(img, gray_img,COLOR_BGR2GRAY);
    //cv::imwrite("/home/local/furcann17861/Lab/2/Lab2/gray_img.jpg", gray_img);
    imshow( "Gray image", img);
    waitKey(0);
    
    //plotting histogram using 256 bins and range [0,255]
    int bins = 150;
    int histSize[] = {bins};
    
    float range[] = {0, 255}; 
    const float* histRange[] = {range};

    cv::Mat hist;
    int channels[] = {0};
  
    calcHist(&img, 1, channels, Mat(), hist, 1, histSize, histRange, true, false);
    normalize(hist, hist, 0, 255,NORM_MINMAX);
    
    //image to dispaly histogram
    int hist_w = 500; int hist_h = 255;
	int ratio = cvRound((double)hist_w/bins);
	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));

    //visualize each bin
	int x1, y1;
	int x2, y2;
	for (int i = 1; i < bins; i++){
		x1 = ratio*(i - 1);
		y1 = hist_h - cvRound(hist.at<float>(i - 1));

		x2 = ratio*(i);
		y2 = hist_h - cvRound(hist.at<float>(i));

		line(histImage, Point(x1,y1), Point(x2,y2),
			Scalar(255, 255, 255), 2, 8, 0);
	}
	
    namedWindow("calcHist");
	imshow("calcHist", histImage);
	waitKey(0);


    return 0;
    
}
