// Lab5-7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "UI.h"
#include <Windows.h>

int main()
{
	testDog();
	testRepository();
	testController();
	Repository repo("Dogs.txt");
	Controller ctrl(repo);
	UI ui(ctrl);
	ui.run();
    return 0;
}

