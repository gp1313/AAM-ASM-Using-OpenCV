// This file is temp 
#include "test.hpp"

using namespace std;

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
}
