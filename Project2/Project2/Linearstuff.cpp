#include "Linearstuff.h"
#include "lineartest.h"
#include <fstream>
#include <iostream>
#include <iomanip>

//void Linearstuff::initialize()
//{
//	getCoords();
//	line.initpatch();
//}

void Linearstuff::getCoords()
{
	std::string line1;

	//declare atomType vector
	std::vector<atomT> atomType;
	
	//find file location
	fin.open("output2.txt");
	fout.open("output.txt");
	fin >> molefile;
	fin.close();
	fin.open(molefile);

	//std::getline(fin, line1);
	fin >> line1;
	
	//validate format
	if (line1 == "string")
	{
		//get numAtoms & Bonds
		fin.ignore();
		std::getline(fin, line1);
		std::getline(fin, line1);
		fin >> numAtoms >> numBonds;
		std::getline(fin, line1);

		//resize vectors
		atomType.resize(numAtoms);
		inputCoord.resize(numAtoms);

		//print numAtoms & Bonds
		fout << "numAtoms: " << numAtoms << " numBonds: " << numBonds << std::endl;

		//get coord and atom type
		for (int i = 0; i < numAtoms; i++)
		{
			inputCoord[i].resize(3);

			for (int z = 0; z < 3; z++)
			{
				//get atomCoords
				fin >> inputCoord[i][z];
				fout << "Atom " << i << " Axis " << z << " " << inputCoord[i][z] << " ";
			}

			fin >> atomType[i].name;
			fout << atomType[i].name << std::endl;
			std::getline(fin, line1);

		}
	}

	else
	{
		numAtoms = atoi(line1.c_str());
		fin >> numBonds;
		std::getline(fin, line1);
		fout << "numAtoms: " << numAtoms << " numBonds: " << numBonds << std::endl;

		//resize vectors
		atomType.resize(numAtoms);
		inputCoord.resize(numAtoms);

		for (int i = 0; i < numAtoms; i++)
		{
			inputCoord[i].resize(3);

			for (int xyz = 0; xyz < 3; xyz++)
			{
				//get atomCoords
				fin >> inputCoord[i][xyz];
				fout << "Atom " << i << " Axis " << xyz << " " << std::setprecision(5) 
					 << std::fixed << inputCoord[i][xyz] << " ";
			}

			fin >> atomType[i].name;
			std::getline(fin, line1);
			fout << std::endl;
		}

	}

	setOrigin();
	fout << "\n\n\n";

	for (int i = 0; i < numAtoms; i++)
	{
		for (int xyz = 0; xyz < 3; xyz++)
		{
			fout << "After setOrigin" << std::endl <<
				"atom: " << i << " axis: " << xyz << " " << inputCoord[i][xyz] << std::endl;
		}
	}

}

void Linearstuff::setOrigin()
{
	double dx = 0, dy = 0, dz = 0;

	//find respective origin to molecule
	if (inputCoord[0][0] != 0 ||
		inputCoord[0][1] != 0 ||
		inputCoord[0][2] != 0)
	{
		if (inputCoord[0][0] < 0||
			inputCoord[0][0] > 0)
			dx = -1 * inputCoord[0][0];

		if (inputCoord[0][1] < 0||
			inputCoord[0][1] > 0)
			dy = -1 * inputCoord[0][1];

		if (inputCoord[0][2] < 0||
			inputCoord[0][2] > 0)
			dz = -1 * inputCoord[0][2];
	}

	//translate molecule
	for (int i = 0; i < numAtoms; i++)
	{
		inputCoord[i][0] += dx;
		inputCoord[i][1] += dy;
		inputCoord[i][2] += dz;
	}
}

