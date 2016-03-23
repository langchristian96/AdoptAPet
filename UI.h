#pragma once
#include "Controller.h"
class UI
{
private:
	Controller ctrl;

public:
	UI(const Controller& c) : ctrl(c) {}
	void run();

private:
	static void printMenu();
	static void printAdminMenu();
	static void printUserMenu();
	static void printAdoptionMenu();
	static void printAllDogsMenu();
	static void printBreedMenu();

	void addDogToCtrl();
	void updateDogToCtrl();
	void removeDogFromCtrl();
	void displayAllDogs();

};