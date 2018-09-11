#ifndef LINEARSTUFF_H
#define LINEARSTUFF_H
#include <string>
#include "lineartest.h"
#include "MyForm.h"
#include <fstream>


class Linearstuff
{
    public:
		std::string molefile;
		void initialize() {
			getCoords();
			line.initpatch(fout, numAtoms, inputCoord);
		}


    protected:
		std::ifstream fin;
		std::ofstream fout;
        int numAtoms;
		int numBonds;
		std::vector<std::vector<double>> inputCoord;
		struct atomT
		{
			std::string name;
			int electrons;
		};

    private:
		lineartest line;
        std::string filename;
		void setOrigin();
		void getCoords();


};

#endif // LINEARSTUFF_H
