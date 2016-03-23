#include "Controller.h"
#include "DynamicVector.h"
#include "Dog.h"
#include <assert.h>
int Controller::addDogToRepository(const std::string& breed, const std::string& name, const int age, const std::string& photograph)
{
	int rez;
	Dog s{ breed,name,age,photograph };
	rez=this->repo.addDog(s);
	return rez;
}

void Controller::updateDogToRepository(const std::string& breed, const std::string& name, const int age, const std::string& photograph)
{

	Dog s{ breed,name,age,photograph };
	this->repo.updateDog(s);

}
void Controller::cleanBreed()
{
	this->breed.cleanDogList();
}

int Controller::removeDogFromRepository(const std::string& name)
{
	int rez;
	Dog s{ "",name,0,"" };
	rez=this->repo.deleteDog(s);
	return rez;
}


void Controller::addDogToAll(const Dog& dog)
{
	this->allDogs.add(dog);

}
void Controller::addDogToAdoption(const Dog& dog)
{
	DynamicVector v = this->adoption.getDogs();
	Dog* elems = v.getAllElems();
	for (int i = 0; i < v.getSize(); i++)
	{
		if (dog.getName() == elems[i].getName())
			return;
	}
	this->adoption.add(dog);
}
void Controller::addDogToBreed(const Dog& dog)
{
	this->breed.add(dog);
}


void Controller::addAllDogs()
{

	DynamicVector v = this->repo.getDogs();
	Dog* dogs = v.getAllElems();
	for (int i = 0; i < v.getSize(); i++)
	{
		this->allDogs.add(dogs[i]);



	}
}

void Controller::addDogsByBreedAndAge(const std::string& breed, int age)
{
	DynamicVector v = this->repo.getDogs();
	Dog* dogs = v.getAllElems();
	for (int i = 0; i < v.getSize(); i++)
	{
		Dog d = dogs[i];
		if (d.getBreed() == breed&&d.getAge() <= age)
			this->addDogToBreed(dogs[i]);



	}
}



void Controller::startDogList()
{
	this->allDogs.startPhoto();
}
void Controller::nextDogList()
{
	this->allDogs.next();
}
void Controller::startAdoptionList()
{
	this->adoption.startPhoto();
}
void Controller::nextAdoptionList()
{
	this->adoption.next();

}
void Controller::startBreedList()
{
	this->breed.startPhoto();
}
void Controller::nextBreedList()
{
	this->breed.next();
}


void testController()
{

	Repository repo("test.txt");
	Controller ctrl(repo);
	DynamicVector v = repo.getDogs();
	assert(v.getSize() == 0);


	ctrl.addDogToRepository("metis", "patrocle", 1, "google.ro");

	v = ctrl.getRepo().getDogs();
	assert(v.getSize() == 1);
	ctrl.removeDogFromRepository("patrocle");

	v = ctrl.getRepo().getDogs();
	assert(v.getSize() == 0);


}