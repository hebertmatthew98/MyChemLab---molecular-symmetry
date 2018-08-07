#ifndef LINEARTEST_H
#define LINEARTEST_H


class lineartest
{
    public:
        initpatch();

    protected:
        int numAtoms = 3;
        double inputCoord[100][3] = {{0,0,0},
                                     {1,1,1},
                                     {2,2,2}};

    private:
        struct solveRelativity
        {
            int test;
            int quadrant[3][4];
            int plane[3];
            int test1d[3];
            int plane3d;
            int octant[8];
            int inittest;
        };

        initval(solveRelativity &Solve);
        solving(solveRelativity &Solve);
        dimension(int an, solveRelativity &Solve);
        relativity(solveRelativity Solve);
        conclusion(solveRelativity Solve);
        double dx;
        double dy;
        double dz;


};

#endif // LINEARTEST_H
