// This file is temp 
#include "test.hpp"

using namespace std;
using namespace cv;

ImportDataBase::ImportDataBase()
{
    string oImageFileStr =  "./ImageDatabase.txt";
    string oLandmarkFileStr =  "./LandmarkDatabase.txt";

    vector<string> oImageListVecStr;
    vector<string> oLDPointsListVecStr;

    CreatList(oImageFileStr, oImageListVecStr);
    CreatList(oLandmarkFileStr, oLDPointsListVecStr);

    if (oImageListVecStr.size() == 0)
    {
        cout << "image vector size is 0: list is empty\n";
    }
    cout << "Number of images imported : " << oImageListVecStr.size() << endl;
    
    if (oLDPointsListVecStr.size() == 0)
    {
        cout << "LD points vector size is 0: list is empty\n";
    }
    cout << "Number of LD files imported : " << oLDPointsListVecStr.size() << endl;
    
        
    int iImgCount = oImageListVecStr.size();
    int iLandmarkPtsCount = oLDPointsListVecStr.size();

    if(iImgCount != iLandmarkPtsCount)
    {
        cout << "iImgCount != iLandmarkPtsCount \n";
        return;
    }

    vector <Point> oPerImgPts(68);
    vector< vector<Point> > oLandmarkPointsVec(iLandmarkPtsCount, oPerImgPts);

    /* load landmark points into a vector */
    create_shape_vector(oImageListVecStr, oLandmarkPointsVec);


#if 1
    /* Display database */
    Mat oInputMat;
    namedWindow("Input_with_features", 0);
    for(int i =0; i <  iImgCount; i++)
    {
        oInputMat = imread(oImageListVecStr[i]);
        for(int j =0; j < 68; j++)
        {
        circle(oInputMat,
                oLandmarkPointsVec[i][j],
                1,
                cv::Scalar(0,0,0)
              );
        }
        imshow("Input_with_features", oInputMat);
        waitKey(0);
    }
#endif
}

void ImportDataBase::create_shape_vector(vector<string> oImageListVecStr, vector< vector<Point> > &oLandmarkpathVec)
{


    FILE *poFileToParse;
    string oImageStr, oToSaveStr;
#ifdef DEBUG 
    namedWindow("Input", 0);
#endif

    for(int c =0; c < oImageListVecStr.size(); c++)
    {
        oImageStr = oImageListVecStr[c];
        string oPointsFileStr(oImageStr);
        int iLen = oPointsFileStr.size();
        oPointsFileStr[iLen-1] = 's';
        oPointsFileStr[iLen-2] = 't';
        oPointsFileStr[iLen-3] = 'p';

        poFileToParse = fopen(oPointsFileStr.c_str(), "r");
        if(poFileToParse == NULL)
        {
            cout << "cannot read file!! \n";
            return;
        }
        char oTempString[10000];
        fscanf(poFileToParse, "%[^\n]\n", oTempString);
#ifdef DEBUG 
        cout << oTempString << endl;
#endif
        fscanf(poFileToParse, "%[^\n]\n", oTempString);

#ifdef DEBUG     
        cout << oTempString << endl;
#endif

        fscanf(poFileToParse, "%[^\n]\n", oTempString);

#ifdef DEBUG     
        cout << oTempString << endl;
        Mat oInputMat = imread(oImageStr);
#endif
        float fTemp1, fTemp2;
        for (int i = 0; i < 68; i++)
        {
            fscanf(poFileToParse, "%f %f \n", &fTemp1, &fTemp2);
#ifdef DEBUG         
            cout << fTemp1 << " & " << fTemp2 << endl;
#endif
            oLandmarkpathVec[c][i] = Point((int)fTemp1, (int)fTemp2);
#ifdef DEBUG         
            circle(oInputMat,
                    Point((int)fTemp1, (int)fTemp2),
                    1,
                    cv::Scalar(0,0,0)
                  );
#endif
        }
#ifdef DEBUG         
        imshow("Input", oInputMat);
        waitKey(0);
#endif
    }
}
