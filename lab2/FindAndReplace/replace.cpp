
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string FindAndReplace(std::string const& line, std::string const& search, std::string  const& replace)
{
	string input(line);
	string replacedString;
	size_t found;
	found = input.find(search);

	while(found != std::string::npos)
	{
		replacedString = input.replace(found, search.size(), replace);
		found = input.find(search, found);
	}
	return replacedString;
}

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
		if(outputString == "")
		{
			cout << inputString << " " ;
		}
		else
		{
			cout << outputString << " ";
		}
		outputString = "";
	} while (cin.peek() != '\n');


    return 0;
}