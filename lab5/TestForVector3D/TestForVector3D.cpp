#include "stdafx.h"
#include <iostream>
#include "../lab5/CVector3D.h"

using namespace std;

TEST_CASE("Test Vector3D")
{
	setlocale(LC_ALL, "Russian");
	SECTION("Проверка Методов класса")
	{
		cout << "1) Проверка Методов класса" << endl;

		CVector3D zeroVec;
		CHECK(zeroVec.GetLength() == 0);

		const double lenght = 5;
		CVector3D v0(5, 1, 2);
		double len = round(v0.GetLength());
		CHECK(len == lenght);

		CVector3D v1(2, 2, 2);
		v1.Normalize();
		CHECK(v1.GetLength() == 1);

		CVector3D v2;
		CVector3D result;
		CVector3D v3(5, 1, 2);

		CHECK(v2.DotProduct(v0, v3) == 30);
		CHECK((result.CrossProduct(v0, v3) == CVector3D(0, 0, 0)) == true);

		CVector3D vec(0, 4, 3);
		CVector3D res;
		CHECK(res.Normalize(vec) == CVector3D(0, 0.8, 0.6));

	}

	SECTION("Сравнение 3-х мерных векторов")
	{
		cout << "2)Сравнение 3-х мерных векторов" << endl;
		CVector3D V(2, 4, 8);
		CHECK((V == CVector3D(2, 4, 8)));
		CHECK((V != CVector3D(2, 6, 8)) == false);

	}

	SECTION("Бинарный + и -")
	{
		cout << " 3)Бинарный + и - " << endl;
		CVector3D firstV(2, 4, 5);
		CVector3D secondV(5, 6, 8);
		CHECK((firstV + secondV) == CVector3D(7, 10, 13));
		CHECK((firstV - secondV) == CVector3D(-3, -2, -3));
	}

	SECTION("Унарный + и -")
	{
		cout << "4)Унарный + и - " << endl;
		CVector3D vector(5, 5, 5);

		vector = +vector;
		CHECK(vector == CVector3D(5, 5, 5));
		vector = -vector;

		CHECK(vector == CVector3D(-5, -5, -5));

	}

	SECTION("Операции += и -=")
	{
		cout << "5)Операции += и -=" << endl;

		CVector3D vec1(5, 6, 7);
		CVector3D vec2(1, 5, 3);
		CHECK((vec1 += vec2) == CVector3D(6, 11, 10));
		CHECK(((vec1 -= vec2) == CVector3D(5, 6, 7)) == true);

	}

	SECTION("Операции *, /, /=, *=")
	{
		cout << "6)Операции *, /, /=, *=" << endl;
		CVector3D vec1(5, 6, 7);
		CVector3D result;

		CHECK((((vec1*2.0) == CVector3D(10, 12, 14)) && ((2 * vec1) == CVector3D(10, 12, 14))) == true);
		result = vec1 / 2.0;
		CHECK(result == CVector3D(5, 6, 7));

		vec1 *= 3.0;
		CHECK(vec1 == CVector3D(15, 18, 21));
		vec1 /= 3.0;
		CHECK(vec1 == CVector3D(3, 6, 7));
	}
}