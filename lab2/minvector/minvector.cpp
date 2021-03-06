
#include "stdafx.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include "minvector.h"

using namespace std;

double MinInVector(vector <double> &inputVector)
{
	int i;
	double min;
	min = inputVector[0];
	for (i = 0; i < inputVector.size(); ++i)
	{
		if ((inputVector[i] < min) && (i > 0))
		{
			min = inputVector[i];
		}
	}
	return min;
}

void PrintVector(vector <double> &inputVector, double min)
{
	int i;
	for (i = 0; i < inputVector.size(); ++i)
	{
		cout << inputVector[i] << endl;
	}
}

