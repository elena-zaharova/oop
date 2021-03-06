// ReplaceVer2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "replace.h"


int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "Russian");

	if ((argc < 3) || (argc > 3))
	{
		cout << "Введие искомую и заменяемую строки" << endl;
		return 1;
	}

	string searchString, replaceString, inputString, outputString;
	outputString = "";


	searchString = argv[1];
	replaceString = argv[2];


	do
	{
		cin >> inputString;
		outputString = FindAndReplace(inputString, searchString, replaceString);
		if (outputString == "")
		{
			cout << inputString << " ";
		}
		else
		{
			cout << outputString << " ";
		}
		outputString = "";
	} while (cin.peek() != '\n');


	return 0;
}

