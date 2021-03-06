#include "stdafx.h"
#include "../lab6/CTriangle.h"
#include"../lab6/CTriangleDomainError.h"
#include "../lab6/CTriangleErrorInvalid.h"
using namespace std;


TEST_CASE("Test For Tringle")
{
	setlocale(LC_ALL, "Russian");
	SECTION("Методы класса треугольника")
	{
		CTriangle tr(3.4, 4.5, 6);
		CHECK(tr.GetSide1() == 3.4);
		CHECK(tr.GetSide2() == 4.5);
		CHECK(tr.GetSide3() == 6);
		CHECK(tr.GetPerimeter() == 13.9);

		double area = tr.GetArea();

		area = round(area * 100) / 100;
		CHECK(area == 7.58);
	}

	SECTION("Проверка на исключения")
	{
		const string negative = "Argument  can not be negative.";
		const string side1Greater = "Side 1 can not be greater than sum of side 2 and side 3";
		const string side2Greater = "Side 2 can not be greater than sum of side 1 and side 3";
		const string side3Greater = "Side 3 can not be greater than sum of side 2 and side 1";

		try
		{
			CTriangle triangleOne(-1, 2, 4);
		}
		catch (CTriangleErrorInvalid const &e)
		{
			CHECK(e.what() == negative);
		}

		try
		{
			CTriangle triangleOne(7, 2, 4);
		}
		catch (CTriangleDomainError const &e)
		{
			CHECK(e.what() == side1Greater);
		}

		try
		{
			CTriangle triangleOne(2, 7, 4);
		}
		catch (CTriangleDomainError const &e)
		{
			CHECK(e.what() == side2Greater);
		}

		try
		{
			CTriangle triangleOne(4, 2, 7);
		}
		catch (CTriangleDomainError const &e)
		{
			CHECK(e.what() == side3Greater);
		}

	}
}