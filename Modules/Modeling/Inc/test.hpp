#include <iostream>
#include <string>
#include "utility.hpp"
#include <vector>
using namespace std;
using namespace cv;

class ImportDataBase
{
    public:
        ImportDataBase();

    private:
        void create_shape_vector(vector<string> oImageListVecStr, vector< vector<Point> > &oLandmarkpathVec);
};

