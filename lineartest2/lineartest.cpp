#include "lineartest.h"
#include <cmath>
#include <iostream>
using namespace std;

lineartest::conclusion(solveRelativity Solve)
{
    if(Solve.inittest == 0 && Solve.test == numAtoms - 2)
        cout << "Molecule is linear" << endl;
    else
        cout << "Molecule is not linear" << endl;
}

lineartest::initpatch()
{
    solveRelativity Solve;

    initval(Solve);

    for(int an = 1; an < numAtoms; an++)
        dimension(an, Solve);

    Solve.inittest = relativity(Solve);

                     solving(Solve);

                     conclusion(Solve);
}

lineartest::initval(solveRelativity &Solve)
{
    Solve.plane3d = 0;
    Solve.test = 0;
    dx = inputCoord[1][0];
    dy = inputCoord[1][1];
    dz = inputCoord[1][2];

    for(int axis = 0; axis < 3; axis++)
    {
        Solve.plane[axis] = 0;
        Solve.test1d[axis] = 0;

        for(int oct = 0; oct < 8; oct++)
        {
            if(oct < 4)
                Solve.quadrant[axis][oct] = 0;

            Solve.octant[oct] = 0;
        }
    }

}

lineartest::solving(solveRelativity &Solve)
{
    for(int an = 2; an < numAtoms; an++)
    {
        for(double multiple = 1.00; multiple < 100; multiple += 0.000025)
        {
            if(abs(multiple*dx) == abs(inputCoord[1][0])&&
               abs(multiple*dy) == abs(inputCoord[1][1])&&
               abs(multiple*dz) == abs(inputCoord[1][2]))

                    Solve.test++;
        }
    }
}

lineartest::dimension(int an, solveRelativity &Solve)
{
//perform 1d tests
    if(inputCoord[an][0] != 0&&
       inputCoord[an][1] == 0&&
       inputCoord[an][2] == 0)
       Solve.test1d[0]++;


    else if(inputCoord[an][0] == 0&&
            inputCoord[an][1] != 0&&
            inputCoord[an][2] == 0)
            Solve.test1d[1]++;


    else if(inputCoord[an][0] == 0&&
            inputCoord[an][1] == 0&&
            inputCoord[an][2] != 0)
            Solve.test1d[2]++;

//perform 2d tests
    //xy axis
    else if(inputCoord[an][0] > 0&&
            inputCoord[an][1] > 0&&
            inputCoord[an][2] == 0)
            {
                Solve.quadrant[0][0]++;
                Solve.plane[0]++;
            }


    else if(inputCoord[an][0] < 0&&
            inputCoord[an][1] > 0&&
            inputCoord[an][2] == 0)
            {
                Solve.quadrant[0][1]++;
                Solve.plane[0]++;
            }


    else if(inputCoord[an][0] < 0&&
            inputCoord[an][1] < 0&&
            inputCoord[an][2] == 0)
            {
                Solve.quadrant[0][2]++;
                Solve.plane[0]++;
            }


    else if(inputCoord[an][0] > 0&&
            inputCoord[an][1] < 0&&
            inputCoord[an][2] == 0)
            {
                Solve.quadrant[0][3]++;
                Solve.plane[0]++;
            }


    //zy axis
    else if(inputCoord[an][0] == 0&&
            inputCoord[an][1] > 0&&
            inputCoord[an][2] > 0)
            {
                Solve.quadrant[1][0]++;
                Solve.plane[1]++;
            }


    else if(inputCoord[an][0] == 0&&
            inputCoord[an][1] > 0&&
            inputCoord[an][2] < 0)
            {
                Solve.quadrant[1][1]++;
                Solve.plane[1]++;
            }


    else if(inputCoord[an][0] == 0&&
            inputCoord[an][1] < 0&&
            inputCoord[an][2] < 0)
            {
                Solve.quadrant[1][2]++;
                Solve.plane[1]++;
            }


    else if(inputCoord[an][0] == 0&&
            inputCoord[an][1] < 0&&
            inputCoord[an][2] > 0)
            {
                Solve.quadrant[1][3]++;
                Solve.plane[1]++;
            }


    //xz axis
    else if(inputCoord[an][0] > 0&&
            inputCoord[an][1] == 0&&
            inputCoord[an][2] > 0)
            {
                Solve.quadrant[2][0]++;
                Solve.plane[2]++;
            }


    else if(inputCoord[an][0] < 0&&
            inputCoord[an][1] == 0&&
            inputCoord[an][2] > 0)
            {
                Solve.quadrant[2][1]++;
                Solve.plane[2]++;
            }


    else if(inputCoord[an][0] < 0&&
            inputCoord[an][1] == 0&&
            inputCoord[an][2] < 0)
            {
                Solve.quadrant[2][2]++;
                Solve.plane[2]++;
            }


    else if(inputCoord[an][0] > 0&&
            inputCoord[an][1] == 0&&
            inputCoord[an][2] < 0)
            {
                Solve.quadrant[2][3]++;
                Solve.plane[2]++;
            }

//octant tests
    else if(inputCoord[an][0] > 0&&
            inputCoord[an][1] > 0&&
            inputCoord[an][2] > 0)
        Solve.octant[0]++;

    else if(inputCoord[an][0] < 0&&
            inputCoord[an][1] > 0&&
            inputCoord[an][2] > 0)
        Solve.octant[1]++;

    else if(inputCoord[an][0] < 0&&
            inputCoord[an][1] < 0&&
            inputCoord[an][2] > 0)
        Solve.octant[2]++;

    else if(inputCoord[an][0] > 0&&
            inputCoord[an][1] < 0&&
            inputCoord[an][2] > 0)
        Solve.octant[3]++;

    else if(inputCoord[an][0] > 0&&
            inputCoord[an][1] > 0&&
            inputCoord[an][2] < 0)
        Solve.octant[4]++;

    else if(inputCoord[an][0] < 0&&
            inputCoord[an][1] > 0&&
            inputCoord[an][2] < 0)
        Solve.octant[5]++;

    else if(inputCoord[an][0] < 0&&
            inputCoord[an][1] < 0&&
            inputCoord[an][2] < 0)
        Solve.octant[6]++;

    else if(inputCoord[an][0] > 0&&
            inputCoord[an][1] < 0&&
            inputCoord[an][2] < 0)
        Solve.octant[7]++;

    else
        cout << "Error. Atom location not found." << endl;

//find 3d planes
    for(int an = 1; an < numAtoms; an++)
    {
        for(int an2 = 2; an2 < numAtoms; an2++)
        {
            if(inputCoord[an][0] == inputCoord[an2][0] &&
               inputCoord[an][1] != inputCoord[an2][1] &&
               inputCoord[an][2] != inputCoord[an2][2] ||
               inputCoord[an][0] != inputCoord[an2][0] &&
               inputCoord[an][1] == inputCoord[an2][1] &&
               inputCoord[an][2] != inputCoord[an2][2] ||
               inputCoord[an][0] != inputCoord[an2][0] &&
               inputCoord[an][1] != inputCoord[an2][1] &&
               inputCoord[an][2] == inputCoord[an2][2]  )
                Solve.plane3d = 1;
        }
    }
}

lineartest::relativity(solveRelativity Solve)
{
    if(Solve.plane[0] > 0 || Solve.plane[1] > 0 || Solve.plane[2] > 0)
    {
        if(Solve.test1d[0] > 0 || Solve.test1d[1] > 0 || Solve.test1d[2] > 0)
            return 1;

        else if(Solve.octant[0] > 0 || Solve.octant[1] > 0 || Solve.octant[2] > 0 || Solve.octant[3] > 0 ||
                Solve.octant[4] > 0 || Solve.octant[5] > 0 || Solve.octant[6] > 0 || Solve.octant[7] > 0)
                    return 1;

        else if(Solve.plane[0] > 0)
        {
            if(Solve.plane[1] > 0)
                return 1;
            else if(Solve.plane[2] > 0)
                return 1;

            else if(Solve.quadrant[0][0] > 0 && Solve.quadrant[0][2] == 0 &&
                    Solve.quadrant[0][1] == 0 && Solve.quadrant[0][3] == 0)
                        return 0;

            else if(Solve.quadrant[0][0] == 0 && Solve.quadrant[0][2] > 0 &&
                    Solve.quadrant[0][1] == 0 && Solve.quadrant[0][3] == 0)
                        return 0;

            else if(Solve.quadrant[0][0] == 0 && Solve.quadrant[0][2] == 0 &&
                    Solve.quadrant[0][1] > 0 && Solve.quadrant[0][3] == 0)
                        return 0;

            else if(Solve.quadrant[0][0] == 0 && Solve.quadrant[0][2] == 0 &&
                    Solve.quadrant[0][1] == 0 && Solve.quadrant[0][3] > 0)
                        return 0;

            else if(Solve.quadrant[0][0] > 0 && Solve.quadrant[0][2] > 0 &&
                    Solve.quadrant[0][1] == 0 && Solve.quadrant[0][3] == 0)
                        return 0;

            else if(Solve.quadrant[0][1] > 0 && Solve.quadrant[0][3] > 0 &&
                    Solve.quadrant[0][0] == 0 && Solve.quadrant[0][2] == 0)
                        return 0;

            else
                return 1;
        }

        else if(Solve.plane[1] > 0)
        {
            if(Solve.plane[0] > 0)
                return 1;

            else if(Solve.plane[2] > 0)
                return 1;

            else if(Solve.quadrant[1][0] > 0 && Solve.quadrant[1][2] == 0 &&
                    Solve.quadrant[1][1] == 0 && Solve.quadrant[1][3] == 0)
                        return 0;

            else if(Solve.quadrant[1][0] == 0 && Solve.quadrant[1][2] > 0 &&
                    Solve.quadrant[1][1] == 0 && Solve.quadrant[1][3] == 0)
                        return 0;

            else if(Solve.quadrant[1][0] == 0 && Solve.quadrant[1][2] == 0 &&
                    Solve.quadrant[1][1] > 0 && Solve.quadrant[1][3] == 0)
                        return 0;

            else if(Solve.quadrant[1][0] == 0 && Solve.quadrant[1][2] == 0 &&
                    Solve.quadrant[1][1] == 0 && Solve.quadrant[1][3] > 0)
                        return 0;

            else if(Solve.quadrant[1][0] > 0 && Solve.quadrant[1][2] > 0 &&
                    Solve.quadrant[1][1] == 0 && Solve.quadrant[1][3] == 0)
                        return 0;

            else if(Solve.quadrant[1][1] > 0 && Solve.quadrant[1][3] > 0 &&
                    Solve.quadrant[1][0] == 0 && Solve.quadrant[1][2] == 0)
                        return 0;

            else
                return 1;
        }

        else if(Solve.plane[2] > 0)
        {
            if(Solve.plane[1] > 0)
                return 1;

            else if(Solve.plane[0] > 0)
                return 1;

            else if(Solve.quadrant[2][0] > 0 && Solve.quadrant[2][2] == 0 &&
                    Solve.quadrant[2][1] == 0 && Solve.quadrant[2][3] == 0)
                        return 0;

            else if(Solve.quadrant[2][0] == 0 && Solve.quadrant[2][2] > 0 &&
                    Solve.quadrant[2][1] == 0 && Solve.quadrant[2][3] == 0)
                        return 0;

            else if(Solve.quadrant[2][0] == 0 && Solve.quadrant[2][2] == 0 &&
                    Solve.quadrant[2][1] > 0 && Solve.quadrant[2][3] == 0)
                        return 0;

            else if(Solve.quadrant[2][0] == 0 && Solve.quadrant[2][2] == 0 &&
                    Solve.quadrant[2][1] == 0 && Solve.quadrant[2][3] > 0)
                        return 0;

            else if(Solve.quadrant[2][0] > 0 && Solve.quadrant[2][2] > 0 &&
                    Solve.quadrant[2][1] == 0 && Solve.quadrant[2][3] == 0)
                        return 0;

            else if(Solve.quadrant[2][1] > 0 && Solve.quadrant[2][3] > 0 &&
                    Solve.quadrant[2][0] == 0 && Solve.quadrant[2][2] == 0)
                        return 0;

            else
                return 1;
        }
    }

    else if(Solve.octant[0] > 0 || Solve.octant[1] > 0 || Solve.octant[2] > 0 || Solve.octant[3] > 0 ||
            Solve.octant[4] > 0 || Solve.octant[5] > 0 || Solve.octant[6] > 0 || Solve.octant[7] > 0)
    {
        if(Solve.test1d[0] > 0 || Solve.test1d[1] > 0 || Solve.test1d[2] > 0)
            return 1;

        else if(Solve.plane3d > 0)
            return 1;

        else if(Solve.octant[0] > 0 && Solve.octant[6] > 0 && Solve.octant[1] == 0 && Solve.octant[2] == 0&&
                Solve.octant[3] == 0 && Solve.octant[4] == 0 && Solve.octant[5] == 0 && Solve.octant[7] == 0)
                    return 0;

        else if(Solve.octant[0] == 0 && Solve.octant[6] == 0 && Solve.octant[1] > 0 && Solve.octant[2] == 0&&
                Solve.octant[3] == 0 && Solve.octant[4] == 0 && Solve.octant[5] == 0 && Solve.octant[7] > 0)
                    return 0;

        else if(Solve.octant[0] == 0 && Solve.octant[6] == 0 && Solve.octant[1] == 0 && Solve.octant[2] > 0&&
                Solve.octant[3] == 0 && Solve.octant[4] > 0 && Solve.octant[5] == 0 && Solve.octant[7] == 0)
                    return 0;

        else if(Solve.octant[0] == 0 && Solve.octant[6] == 0 && Solve.octant[1] == 0 && Solve.octant[2] == 0&&
                Solve.octant[3] > 0 && Solve.octant[4] == 0 && Solve.octant[5] > 0 && Solve.octant[7] == 0)
                    return 0;

        else if(Solve.octant[0] > 0 && Solve.octant[6] == 0 && Solve.octant[1] == 0 && Solve.octant[2] == 0&&
                Solve.octant[3] == 0 && Solve.octant[4] == 0 && Solve.octant[5] == 0 && Solve.octant[7] == 0)
                    return 0;

        else if(Solve.octant[0] == 0 && Solve.octant[6] > 0 && Solve.octant[1] == 0 && Solve.octant[2] == 0&&
                Solve.octant[3] == 0 && Solve.octant[4] == 0 && Solve.octant[5] == 0 && Solve.octant[7] == 0)
                    return 0;

        else if(Solve.octant[0] == 0 && Solve.octant[6] == 0 && Solve.octant[1] > 0 && Solve.octant[2] == 0&&
                Solve.octant[3] == 0 && Solve.octant[4] == 0 && Solve.octant[5] == 0 && Solve.octant[7] == 0)
                    return 0;

        else if(Solve.octant[0] == 0 && Solve.octant[6] == 0 && Solve.octant[1] == 0 && Solve.octant[2] > 0&&
                Solve.octant[3] == 0 && Solve.octant[4] == 0 && Solve.octant[5] == 0 && Solve.octant[7] == 0)
                    return 0;

        else if(Solve.octant[0] == 0 && Solve.octant[6] == 0 && Solve.octant[1] == 0 && Solve.octant[2] == 0&&
                Solve.octant[3] > 0 && Solve.octant[4] == 0 && Solve.octant[5] == 0 && Solve.octant[7] == 0)
                    return 0;

        else if(Solve.octant[0] == 0 && Solve.octant[6] == 0 && Solve.octant[1] == 0 && Solve.octant[2] == 0&&
                Solve.octant[3] == 0 && Solve.octant[4] > 0 && Solve.octant[5] == 0 && Solve.octant[7] == 0)
                    return 0;

        else if(Solve.octant[0] == 0 && Solve.octant[6] == 0 && Solve.octant[1] == 0 && Solve.octant[2] == 0&&
                Solve.octant[3] == 0 && Solve.octant[4] == 0 && Solve.octant[5] > 0 && Solve.octant[7] == 0)
                    return 0;

        else if(Solve.octant[0] == 0 && Solve.octant[6] == 0 && Solve.octant[1] == 0 && Solve.octant[2] == 0&&
                Solve.octant[3] == 0 && Solve.octant[4] == 0 && Solve.octant[5] == 0 && Solve.octant[7] > 0)
                    return 0;

        else
            return 1;
    }
}
