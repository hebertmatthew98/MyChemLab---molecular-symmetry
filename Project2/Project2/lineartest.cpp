#include "lineartest.h"
#include <cmath>
#include <iostream>
#include <fstream>


void lineartest::conclusion(solveRelativity Solve, std::ofstream &fout)
{
    if(Solve.inittest == 0 && Solve.test == numAtoms - 2)
        fout << "Molecule is linear" << std::endl;
    else
        fout << "Molecule is not linear" << std::endl;
}

void lineartest::initpatch(std::ofstream &fout, int numAtomss, std::vector<std::vector<double>> inputCoord)
{
	numAtoms = numAtomss;
    solveRelativity Solve;

    initval(Solve, inputCoord);

    for(int an = 1; an < numAtoms; an++)
        dimension(an, Solve, inputCoord);

    Solve.inittest = relativity(Solve);

                     solving(Solve, inputCoord);

                     conclusion(Solve, fout);
}

void lineartest::initval(solveRelativity &Solve, std::vector<std::vector<double>> inputCoord)
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

void lineartest::solving(solveRelativity &Solve, std::vector<std::vector<double>> inputCoord)
{
    for(int an = 2; an < numAtoms; an++)
    {
        for(double multiple = 1.00; multiple < 100; multiple += 0.000025)
        {
            if(abs(multiple*dx) == abs(inputCoord[an][0])&&
               abs(multiple*dy) == abs(inputCoord[an][1])&&
               abs(multiple*dz) == abs(inputCoord[an][2]))

                    Solve.test++;
        }
    }
}

void lineartest::dimension(int an, solveRelativity &Solve, std::vector<std::vector<double>> inputCoord)
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
        std::cout << "Error. Atom location not found." << std::endl;

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

int lineartest::relativity(solveRelativity Solve)
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
