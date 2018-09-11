#ifndef LINEARTEST_H
#define LINEARTEST_H
#include <string>
#include <vector>
#include <fstream>


class lineartest
{
    public:
		void initpatch(std::ofstream &fout, int numAtomss, std::vector<std::vector<double>> inputCoord);


    protected:
		int numAtoms;
        /*double inputCoord[100][3] = {{0,0,0},
                                     {1,1,1},
                                     {2,2,2}};
									 */
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

        void initval(solveRelativity &Solve, std::vector<std::vector<double>> inputCoord);
        void solving(solveRelativity &Solve, std::vector<std::vector<double>> inputCoord);
        void dimension(int an, solveRelativity &Solve, std::vector<std::vector<double>> inputCoord);
        int relativity(solveRelativity Solve);
        void conclusion(solveRelativity Solve, std::ofstream &fout);
        double dx;
        double dy;
        double dz;


};

#endif // LINEARTEST_H
