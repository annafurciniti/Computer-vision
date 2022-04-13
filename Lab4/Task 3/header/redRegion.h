#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat regionOfInterest(vector<Vec2f> lines, Mat src, vector<Point> point);
