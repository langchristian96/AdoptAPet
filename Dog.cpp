#include "Dog.h"
#include <Windows.h>
#include <assert.h>
#include <shellapi.h>


Dog::Dog() : breed(""), name(""), age(0), photograph("") {}
Dog::Dog(const std::string& breed, const std::string& name, const int age, const std::string& photograph)
{
	this->breed = breed;
	this->name = name;
	this->age = age;
	this->photograph = photograph;
}

void Dog::seePhotograph()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getPhotograph().c_str(), NULL, SW_SHOWMAXIMIZED);
}


void testDog()
{
	Dog d{ "metis","aurel",12,"google.ro" };
	assert(d.getAge() == 12);
	assert(d.getBreed() == "metis");
	assert(d.getName() == "aurel");
	assert(d.getPhotograph() == "google.ro");


}