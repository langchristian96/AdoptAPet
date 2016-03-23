#include "DogList.h"

DogList::DogList()
{
	this->current = 0;
}

DynamicVector DogList::getDogs()
{
	return this->dogs;
}


void DogList::add(const Dog& dog)
{

	this->dogs.add(dog);

}

void DogList::cleanDogList()
{
	this->dogs.cleanDynamicVector();
}

Dog DogList::getCurrentDog()
{
	if (this->current == this->dogs.getSize())
		this->current = 0;
	Dog* elems = this->dogs.getAllElems();
	if (elems != NULL)
		return elems[this->current];
	return Dog{};


}


void DogList::startPhoto()
{
	if (this->dogs.getSize() == 0)
		return;
	this->current = 0;
	Dog currentDog = this->getCurrentDog();
	currentDog.seePhotograph();

}


void DogList::next()
{
	if (this->dogs.getSize() == 0)
		return;
	this->current++;
	Dog currentDog = this->getCurrentDog();
	currentDog.seePhotograph();


}

bool DogList::isEmpty()
{
	return this->dogs.getSize() == 0;
}