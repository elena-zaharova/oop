
#include "stdafx.h"
#include "..\minvector\minvector.h"

vector<double> minVectorOne = {5, 34.5, 23.4, 7.3, 1.2};
vector<double> minVectorSecond = {-1, 4.3, 2.3, -3};
vector<double> minVectorThird = {0, 0, 0, 0, 0};




TEST_CASE("MinVector test")
{
	CHECK(MinInVector(minVectorThird) == 0);
	CHECK(MinInVector(minVectorOne) == 1.2);
	CHECK(MinInVector(minVectorSecond) == -3);
}