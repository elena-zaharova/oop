#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
const int matrixSize = 3;

void CreateMatrix(fstream &file, double matrix[matrixSize][matrixSize])
{
	int i, j;
	char input[255];
	while(!file.eof())
	{
		for (i = 0; i < matrixSize; ++i)
		{
			for (j = 0; j < matrixSize; ++j)
			{
				file >> input;
				matrix[i][j] = atof(input);
			}
		}
	}
	file.close();
}


int main(int argc, char * argv[])

{
	if ((argc < 3)|| (argc > 3))
	{
		cout << "Enter two text files with matrix" << endl;
		return 1;
	}

	fstream fileOfMatrix1;
	fstream fileOfMatrix2;
	fileOfMatrix1.open(argv[1]);
	fileOfMatrix2.open(argv[2]);

	if(!fileOfMatrix1)
	{
		cout << "File of " << argv[1] << " not found" << endl;
		return 1;
	}
	else
	{
		if (!fileOfMatrix2)
		{
			cout << "File " << argv[2] << " not found" << endl;
			return 1;
		}
	}

	double firstMatrix[matrixSize][matrixSize], secondMatrix[matrixSize][matrixSize], resultMatrix[matrixSize][matrixSize];
	int i, j, k;
	char input[255];

	CreateMatrix(fileOfMatrix1, firstMatrix);
	CreateMatrix(fileOfMatrix2, secondMatrix);

	cout << endl;
	for (i = 0; i < matrixSize; ++i)
	{
		for (j = 0; j < matrixSize; ++j)
		{
			resultMatrix[i][j] = 0;
			for(k = 0; k < matrixSize; ++k)
			{
				resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
			}
			cout << resultMatrix[i][j] << " ";
		}
		cout << endl;
	}
    return 0;
}