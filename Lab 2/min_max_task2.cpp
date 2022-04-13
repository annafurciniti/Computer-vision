#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat min(Mat img, int kernel_size){
    int centerX= (kernel_size-1)/2;
    int centerY= (kernel_size-1)/2;
    
    Mat outImg(img.rows-centerY*2, img.cols-centerX*2, img.type(), Scalar(255));

    unsigned char pixel;

    if(kernel_size%2!=0){
       //access pixels
       for(int i=centerX; i<img.rows-centerX; i++){
            for(int j=centerY; j<img.cols-centerY;j++){
                for(int k=-centerX; k<centerX+1; k++){//pixels around the center
                     for(int l=-centerY; l<centerY+1; l++){
                            pixel = img.at<uchar>(k+i,l+j) ;
                            //finding min value
                            if(pixel < outImg.at<uchar>(i-centerX, j-centerY)){
                                outImg.at<uchar>(i-centerX,j-centerY) = pixel;

                            }
                      }
                 }
            }
       }
    }else{
        cout << "image not processed";
    }
    return outImg;
}

Mat max(Mat img, int kernel_size){
    int centerX= (kernel_size-1)/2;
    int centerY= (kernel_size-1)/2;
    
    Mat outImg= Mat::zeros(img.rows-centerY*2, img.cols-centerX*2, img.type());

    unsigned char pixel;

    if(kernel_size%2!=0){
       //access pixels 
       for(int i=centerX; i<img.rows-centerX; i++){
            for(int j=centerY; j<img.cols-centerY;j++){
                for(int k=-centerX; k<centerX+1; k++){//kernel's pixels around the center
                     for(int l=-centerY; l<centerY+1; l++){
                            pixel = img.at<uchar>(k+i,l+j) ;
                            //finding max value
                            if(pixel > outImg.at<uchar>(i-centerX, j-centerY)){
                                outImg.at<uchar>(i-centerX,j-centerY) = pixel;

                            }
                      }
                 }
            }
       }
    }else{
        cout << "image not processed";
    }
    return outImg;
}


