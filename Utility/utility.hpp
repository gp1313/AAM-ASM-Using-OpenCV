#include <iostream>
#include <vector>

/* File system */
#include <fstream>


/* OpenCV */
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/videoio/videoio.hpp>

using namespace std;

/* Create list of vector of strings points to images */
void CreatList(string oFileStr, vector<string> &oImageList);

/* Read list of image and return array of matrix*/
vector<cv::Mat> ImportImages(vector<string> oImageList);


/* Read list of points and return array of float/double or int */

void dumy_function();

