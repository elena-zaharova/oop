#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char * argv[])
{
	if ((argc < 3) || (argc > 3))
	{
		cout << "Input error" << endl;
		return 1;
	}
	
	ifstream text;
	text.open(argv[1]);
	
	int i, findString;
	string inputString, stringInText;
	size_t found;
	
	i = 1;
	findString = 0;
	if(!text)
	{
		cout << "File not found" << endl;
		return 1;
	}
	
	inputString = argv[2];
	while(!text.eof())
	{
		getline(text, stringInText, '\n');
		found = stringInText.find(inputString);

		if (found != std::string::npos)
		{
			findString = i;
			cout << findString << endl;
		}
		++i;
	}
	text.close();
	if(findString == 0)
	{
		cout << "Text not found" << endl;
		return 1;
	}
    return 0;
}