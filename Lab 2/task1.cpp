#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

using namespace cv;

int main(int argc, char** argv){

    Mat gray_img, outImg;
    Mat img = imread("/home/local/furcann17861/Lab/2/Lab2/image.jpg");
    imshow("Image", img);
    //conversion of the image into gray scale image
    cvtColor(img, gray_img,COLOR_BGR2GRAY);
    //save it
    imwrite("/home/local/furcann17861/Lab/2/Lab2/gray_img.jpg", gray_img);
    //reduce dimension of the image
    resize(gray_img, outImg, cv::Size(), 0.60, 0.60);
    imshow( "Gray image", outImg);
    waitKey(0);
    
    return 0;
    
}
