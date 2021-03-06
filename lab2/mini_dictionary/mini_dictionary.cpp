// mini_dictionary.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>
using namespace std;

int main(int argc, char * argv[])
{
	setlocale(LC_ALL, "Russian");
	fstream fileDictionary;
	multimap<string, string> miniDictionary;
	string englishWord, russianWord, searchWord;

	if((argc < 2)||(argc > 2))
	{
		cout << "Введите файл со словарем!" << endl;
	}

	fileDictionary.open(argv[1]);

	if(!fileDictionary)
	{
		cout << "Файл не найден" << endl;
		return 1;
	}

	while(!fileDictionary.eof())
	{
		fileDictionary >> englishWord >> russianWord;
		miniDictionary.insert(pair<string, string>(englishWord, russianWord));
	}
	bool exit = false;
	auto it = miniDictionary.begin();
	while(!exit)
	{
		cin >> searchWord;
		miniDictionary.find(searchWord);
		cout << it->second << endl;
		exit = true;
	}
	for (auto it = miniDictionary.begin(); it != miniDictionary.end(); ++it)
	{
		cout << it->first << " : " << it->second << endl;
	}
    return 0;
}




/*
for (auto it = miniDictionary.begin(); it != miniDictionary.end(); ++it)
{
	cout << it->first << " : " << it->second << endl;
}*/