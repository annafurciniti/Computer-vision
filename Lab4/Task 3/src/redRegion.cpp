#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat regionOfInterest(vector<Vec2f> lines, Mat src, vector<Point> point){
    vector<Point> points;
    // Draw the lines
    for( size_t i = 0; i < lines.size(); i++ ){
            float rho = lines[i][0], theta= lines[i][1];
            Point pt1, pt2;
            double a = cos(theta), b = sin(theta);
            double x0 = a*rho, y0 = b*rho;
            //changing the number the detection will be different, with 1000 many lines
            pt1.x = cvRound(x0 + 1000*(-b));
            pt1.y = cvRound(y0 + 1000*(a));
            pt2.x = cvRound(x0 - 1000*(-b));
            pt2.y = cvRound(y0 - 1000*(a));
            points.push_back(pt1);
            points.push_back(pt2);
            line(src, pt1, pt2, Scalar(0,0,255), 3, LINE_AA);//first linea
            }
           
            //intersection
            float dx = (float)points[0].x - (float)points[1].x;
            float dy = (float)points[0].y - (float)points[1].y;
            float dx1 = (float)points[2].x - (float)points[3].x;
            float dy1 = (float)points[2].y - (float)points[3].y;
            float m1 = dy / dx;
            float c1 = (float)points[0].y - (m1 * (float)points[0].x);

            float m2 = dy1 / dx1;
            float c2 = (float)points[2].y - (m2 * (float)points[2].x);
       
            int ptx = (c1 - c2) / (m2 - m1);
            int pty = (m1 * ptx ) + c1;
           
            int max = src.rows-1;
            
            int max1 = ((max - c1) / m1);
            int max2 = ((max - c2) / m2);
 
            point.push_back(Point(ptx, pty));  
            point.push_back(Point(max1, max));  
            point.push_back(Point(max2, max)); 
            fillConvexPoly(src, point, Scalar(0,0,255), LINE_AA); 
            return src;   
            
}
