#ifndef LINEARSTUFF_H
#define LINEARSTUFF_H
#include <string>
using namespace std;


class Linearstuff
{
    public:
        checklinear();

    protected:
        int numAtoms = 3;
        double inputCoord[100][3] = {{0,0,0},
                                     {1,1,1},
                                     {2,2,2}};

    private:
        string filename;
        getCoords();
};

#endif // LINEARSTUFF_H
