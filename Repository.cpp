#include "Repository.h"
#include <string>
#include <fstream>
#include "Utils.h"
#include <assert.h>
#include <iostream>

using namespace std;
Repository::Repository(const std::string& filename)
{
	this->filename = filename;
	this->readFromFile();
}

int Repository::addDog(const Dog& s)
{

	std::string name = s.getName();
	Dog* elems = this->dogs.getAllElems();
	for (int i = 0; i < this->dogs.getSize(); i++)
	{
		if (elems[i].getName() == name)
		{
			return -1;
		}
	}
	this->dogs.add(s);
	this->writeToFile();
	return 0;

}


void Repository::updateDog(const Dog& s)
{
	std::string name = s.getName();
	Dog* elems = this->dogs.getAllElems();
	for (int i = 0; i < this->dogs.getSize(); i++)
	{
		if (elems[i].getName() == name)
		{
			this->dogs.update(s, i);
			break;
		}
	}
	this->writeToFile();


}

int Repository::deleteDog(const Dog& s)
{

	int exists = 0;
	std::string name = s.getName();
	Dog* elems = this->dogs.getAllElems();
	for (int i = 0; i < this->dogs.getSize(); i++)
	{
		if (elems[i].getName() == s.getName())
		{
			exists = 1;
			this->dogs.deleteOnPos(i);

			this->writeToFile();
			return 0;
		}
	}


	if (exists == 0)
		return -1;

}

void Repository::readFromFile()
{
	ifstream file(this->filename);
	string line;
	while (getline(file, line))
	{
		string tokens[20];
		int length = 0;
		tokenize(line, '|', tokens, length);
		if (length != 4)
			continue;

		Dog s(tokens[0], tokens[1], stoi(tokens[2]), tokens[3]);
		this->dogs.add(s);

	}
	file.close();

}

void Repository::writeToFile()
{

	ofstream file(this->filename);
	if (this->getDogs().getSize()==0)
	{
		file << " ";
		file.close();
		return;
	}
	Dog* elems = this->dogs.getAllElems();
	for (int i = 0; i < this->dogs.getSize(); i++)
	{
		Dog currentDog = elems[i];
		file << currentDog.getBreed() << " | " << currentDog.getName() << " | " << currentDog.getAge() << " | " << currentDog.getPhotograph() << endl;

	}
	file.close();

}

void testRepository()
{
	Repository repo("test.txt");
	Dog d{ "metis","patrocle",1,"google.ro" };
	DynamicVector v = repo.getDogs();
	assert(v.getSize() == 0);
	repo.addDog(d);
	v = repo.getDogs();
	assert(v.getSize() == 1);
	repo.deleteDog(d);

	v = repo.getDogs();
	assert(v.getSize() == 0);

}