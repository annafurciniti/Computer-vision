#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <iostream>
#include </home/local/furcann17861/Lab/4/Task 3/header/redRegion.h>

using namespace cv;
using namespace std;


int main(int argc, char** argv){
    Mat outImgGB, canny_image, gray;

    Mat img = imread("../street_scene.png");
    cvtColor(img, gray, COLOR_BGR2GRAY);
    
    //remove noise before canny that is sensitive to noise. Infact without this step the image and the detection of lines was less precise
    blur(gray, outImgGB, Size(3,3));
    Canny(outImgGB, canny_image, 50,  650);
    imshow("Canny", canny_image);
    waitKey(0);
    
    Mat dest_canny = img.clone();


    //detect lines
    vector<Vec2f> lines; // will hold the results of the detection
    vector<Point> point;
    HoughLines(canny_image, lines, 1, CV_PI/180, 120, 0, 0 ); // runs the actual detection
    regionOfInterest(lines, dest_canny, point);
 
    imshow("Intersection", dest_canny);
    waitKey(0);
    
    return 0;
    
   }
