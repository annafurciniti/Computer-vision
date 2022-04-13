#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat edge(Mat gray){

    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;
    
    //edge detection and orientation
    Mat grad_x, grad_y;
    //calculates derivatives in x and y using Sobel
    Sobel(gray, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT );
    Sobel(gray, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT );
    
    Mat abs_grad_x, abs_grad_y;
    //convert CV_8U
    convertScaleAbs( grad_x, abs_grad_x );
    convertScaleAbs( grad_y, abs_grad_y );
    
    Mat grad;
    //approximation of gradient 
    addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );
    
    return grad;
}
