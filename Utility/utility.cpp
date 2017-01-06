#include "utility.hpp"

/* Definations */

void CreatList(string oFileStr, vector<string> &oImageList)
{

    ifstream oInputFStream;
    oInputFStream.open(oFileStr.c_str(), ifstream::in);
    string sReadLine;

    while (getline(oInputFStream, sReadLine)) 
    {
        cout << sReadLine << endl;
        oImageList.push_back(sReadLine);
#if 0
        Mat oImageMat = imread(sReadLine);
        imshow(oImageMat);
        waitKey(1);
#endif
    }



}

vector<cv::Mat> ImportImages(vector<string> oImageList)
{
    
}

