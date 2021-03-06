#include "stdafx.h"
#include "CTriangle.h"
#include "CTriangleDomainError.h"
#include "CTriangleErrorInvalid.h"
#include <iostream>
#include <cstdlib>
#include <string>


using namespace std;


int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "Russian");
	cout << "> ";

	if ((argc > 4) || (argc < 4))
	{
		cout << "Вы в вели неверные данные" << endl;
		return 1;
	}

	char firstSide[255], secondSide[255], thirdSide[255];
	int side1, side2, side3;
	strcpy_s(firstSide, argv[1]);
	strcpy_s(secondSide, argv[2]);
	strcpy_s(thirdSide, argv[3]);

	side1 = atoi(firstSide);
	side2 = atoi(secondSide);
	side3 = atoi(thirdSide);

	try
	{
		CTriangle triangle(side1, side2, side3);
	}
	catch(CTriangleErrorInvalid const &e)
	{
		cout << "Error : " << e.what() << endl;
		return 1;
	}
	catch (CTriangleDomainError const &e)
	{
		cout << "Error : " << e.what() << endl;
		return 1;
	}
	CTriangle triangle(side1, side2, side3);
	
	if ((side1 == side2) && (side2 == side3) && ( side1 == side3)) 
	{
		cout << " равносторонний " << endl;
	}
	else
	{
		if ((side1 == side2) || (side2 == side3) || (side1 == side3)) 
		{
			cout << "равнобедренный" << endl;
		}
		else
		{
			cout << "обычный" << endl;
		}
	}

    return 0;
}

