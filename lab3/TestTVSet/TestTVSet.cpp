// TestTVSet.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "../3lab/TVSet.h"
#include "../3lab/RemoteControl.h"
#include <string>

TEST_CASE("TurnOn Test")
{
	CTVSet tv;
	CHECK(tv.tv_isTurnedOn() == false);
	SECTION("Turn On Test") 
	{
		tv.TurnOn();
		CHECK(tv.tv_isTurnedOn() == true);
	}

	SECTION("Turn Off Test")
	{
		tv.TurnOff();
		CHECK(tv.tv_isTurnedOn() == false);
	}

	tv.TurnOn();

	SECTION("Select Channel And Previous Test")
	{
		CHECK(tv.SelectChannel(3) == true);
		CHECK(tv.SelectChannel(30) == true);
		CHECK(tv.SelectChannel(0) == false);
		CHECK(tv.SelectChannel(109) == false );
		CHECK(tv.SelectChannel(78) == true);
		CHECK(tv.GetChannel() == 78);
	}
	SECTION("Test TV")
	{
		tv.SelectChannel(98);
		tv.TurnOff();
		tv.TurnOn();
		CHECK(tv.GetChannel() == 98);
	}
	SECTION("Turn off")
	{
		tv.TurnOff();
		CHECK(tv.GetChannel() == 0);
	}
}
