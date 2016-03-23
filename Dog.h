#pragma once
#include <string>

class Dog
{
private:
	std::string breed;
	std::string name;
	int age;
	std::string photograph;

	
public:
	
	Dog();	//default constructor
	
	Dog(const std::string& breed, const std::string& name, const int age, const std::string& photograph);	//constructor with parameters
	std::string getBreed() const { return breed; }	//getter for breed
	std::string getName() const { return name; }	//getter for name
	int getAge() const { return age; }				//getter for age
	std::string getPhotograph() const { return photograph; }	//getter for photograph

	
	void seePhotograph(); //The page corresponding to the dog's photograph is opened
	

};

void testDog();	//tester for Dog