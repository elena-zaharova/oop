#include "stdafx.h"
#include "..\..\ReplaceVer2\ReplaceVer2\replace.h"

const string firstString = "";
const string secondString = "Hello my friend";
const string thirdString = "you are amazing person";
const string firstSearchString = "you";
const string secondSearchString = "";
const string firstReplaceString = "me";
const string secondReplaceString = "";


TEST_CASE("Find And Replace test")
{
	//Проверяет замену в пустой строке
	CHECK(FindAndReplace(firstString, firstSearchString, firstReplaceString) == "");
	//Заменяем в строке со всеми параметрами
	CHECK(FindAndReplace(thirdString, firstSearchString, firstReplaceString) == "me are amazing person");
	//проверяем замену подстроки когда искомой и заменяемой нет в строке
	CHECK(FindAndReplace(secondString, firstSearchString, firstReplaceString) == "");
}

