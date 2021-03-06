// dec2bin.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <cstdlib>
#include <cstring>

using namespace std;

int main(int argc, char * argv[])
{
	cout << "This program converts a number from decimal to a binary" << endl;
	if ((argc > 2) || (argc < 2))
	{
		cout << "Error" << endl;
		return 1;
	}
	cout << "Enter number : ";
	cout << argv[1] << endl;

	stack <int> stack_of_binary;
	char input[256];
	int decNum, binNum;
	int i, len;

	strcpy_s(input, argv[1]);
	len = strlen(input);

	for (i = 0; i < len; ++i)
	{
		if ((input[i] < '0') || (input[i] > '9'))
			decNum = -1;
	}

	if (decNum != -1)
		decNum = atoi(input);

	
	if ((decNum <= 0) || (decNum >= INT_MAX))
	{
		cout << "It is incorrect number entry";
		return 1;
	}
	while (decNum != 1)
	{
		binNum = decNum % 2;
		decNum /= 2;
		stack_of_binary.push(binNum);
	}
	cout << "Binary number : ";
	cout << decNum;
	while (stack_of_binary.empty() == false)
	{
		cout << stack_of_binary.top();
		stack_of_binary.pop();
	}
	cout << endl;
    return 0;
}