#pragma once
#include "DynamicVector.h"

class DogList
{
private:
	DynamicVector dogs;
	int current;
public:
	DogList();

	void add(const Dog& dog); //adds a dog to the DogList

	Dog getCurrentDog();
	void cleanDogList();
	void startPhoto();
	DynamicVector getDogs();
	int getNumberOfDogs();
	void next();

	bool isEmpty();


};