#ifndef LINEARTESTWINPUT_H
#define LINEARTESTWINPUT_H


class lineartest
{
    public:
        initpatch();

    protected:
        int numAtoms;
        double inputCoord[][3];

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
