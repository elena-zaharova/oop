// GeneratePrimeNumbersSet.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "GeneratePrimeNumbersSet.h"

using namespace std;


set<int> GeneratePrimeNumbersSet(int upperBound)
{
	set<int>prime;
	vector<bool> isPrimeNumber(upperBound + 1, true);
	isPrimeNumber[0] = false;
	isPrimeNumber[1] = isPrimeNumber[0];

	for(int i = 2; i*i <= upperBound; ++i)
	{
		if(isPrimeNumber[i])
		{
			for(int j = i*i; j <= upperBound; j += i)
			{
				isPrimeNumber[j] = false;
			}
		}
	}

	for(int i = 2; i <= upperBound; ++i)
	{
		if (isPrimeNumber[i]) 
		{
			prime.insert(i);
		}
	}
	return prime;
}
