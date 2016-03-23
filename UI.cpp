#include "UI.h"
#include <string>
#include <iostream>
using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "1 - enter admin mode" << endl;
	cout << "2 - enter user mode" << endl;
	cout << "0 - exit" << endl;

}

void UI::printUserMenu()
{
	cout << endl;
	cout << "1 - see all the dogs in the database" << endl;
	cout << "2 - see the adoption list" << endl;
	cout << "3 - see all the dogs of a given breed with age less than a given one" << endl;
	cout << "0 - return" << endl;
}
void UI::printAdoptionMenu()
{
	cout << endl;
	cout << "1 - see the next adopted dog" << endl;
	cout << "0 - Return" << endl;

}
void UI::printAllDogsMenu()
{

	cout << endl;
	cout << "1 - see the next dog" << endl;
	cout << "2 - adopt the current dog" << endl;
	cout << "0 - return" << endl;
}

void UI::printBreedMenu()
{

	cout << endl;
	cout << "1 - see the next dog" << endl;
	cout << "2 - adopt the current dog" << endl;
	cout << "0 - return" << endl;
}
void UI::printAdminMenu()
{
	cout << endl;
	cout << "1 - add Dog" << endl;
	cout << "2 - update Dog" << endl;
	cout << "3 - remove Dog" << endl;
	cout << "4 - show all Dogs" << endl;
	cout << "0 - return" << endl;
}

void UI::addDogToCtrl()
{
	int rez;
	cout << endl << "Enter the breed: " << endl;
	std::string breed;
	getline(cin, breed);
	cout << "Enter the name: "<<endl;
	std::string name;
	getline(cin, name);
	cout << "Enter the age: " << endl;
	int age;
	cin >> age;
	cin.ignore();
	cout << "Enter the link that contains the dog's photograph: " << endl;
	std::string photograph;
	getline(cin, photograph);
	rez=this->ctrl.addDogToRepository(breed, name, age, photograph);
	if (rez == 0)
		cout << "Dog succesfully added." << endl;
	else
		cout << "Dog with the given name already exists." << endl;
}

void UI::updateDogToCtrl()
{

	cout << endl << "Enter the breed: " << endl;
	std::string breed;
	getline(cin, breed);
	cout << "Enter the name: " << endl;
	std::string name;
	getline(cin, name);
	cout << "Enter the age: " << endl;
	int age;
	cin >> age;
	cin.ignore();
	cout << "Enter the link that contains the dog's photograph: " << endl;
	std::string photograph;
	getline(cin, photograph);
	this->ctrl.updateDogToRepository(breed, name, age, photograph);
}

void UI::removeDogFromCtrl()
{
	int rez;
	cout << "Enter the name: " << endl;
	std::string name;
	getline(cin, name);
	rez=this->ctrl.removeDogFromRepository(name);

	if (rez == 0)
		cout << "Dog succesfully removed." << endl;
	else
		cout << "Dog with the given name does not exist." << endl;
}
void UI::displayAllDogs()
{
	DynamicVector v = this->ctrl.getRepo().getDogs();
	Dog* dogs = v.getAllElems();
	if (dogs == NULL)
		return;
	if (v.getSize() == 0)
	{
		cout << "There are no dogs in the database" << endl;
		return;
	}
	for (int i = 0; i < v.getSize(); i++)
	{
		Dog s = dogs[i];
		cout << "Breed: " << s.getBreed() << " Name: " << s.getName() << " Age: " << s.getAge() << endl;
	}

}

void UI::run()
{
	while (true)
	{
		UI::printMenu();
		int command{ 0 };
		cout << "Input the command: ";
		cin >> command;
		cin.ignore();
		if (command == 0)
			break;
		if (command == 1)
		{
			while (true)
			{
				UI::printAdminMenu();
				int commandAdmin{ 0 };
				cout << "Input the command: ";
				cin >> commandAdmin;
				cin.ignore();
				if (commandAdmin == 0)
					break;
				switch (commandAdmin)
				{
				case 1:
					this->addDogToCtrl();
					break;

				case 2:
					this->updateDogToCtrl();
					break;

				case 3:
					this->removeDogFromCtrl();
					break;
				case 4:
					this->displayAllDogs();
					break;
				}

			}
		}
		if (command == 2)
		{
			while (true)
			{
				UI::printUserMenu();
				int commandUser{ 0 };
				cout << "Input the command: ";
				cin >> commandUser;
				cin.ignore();
				if (commandUser == 0)
					break;
				switch (commandUser)
				{
				case 1:
				{
					this->ctrl.addAllDogs();
					if (this->ctrl.getDogList().isEmpty())
					{
						cout << "The database is empty. No dogs available for adoption."; continue;
					}
					this->ctrl.startDogList();
					Dog d = this->ctrl.getDogList().getCurrentDog();
					cout << "The current dog -  Breed: " << d.getBreed() << " NAME: " << d.getName() << " AGE: " << d.getAge() << endl;

					while (true)
					{

						UI::printAllDogsMenu();
						int commandAll{ 0 };
						cout << "Input the command: ";
						cin >> commandAll;
						cin.ignore();
						if (commandAll == 0)
							break;
						switch (commandAll)
						{
						case 1:
						{
							if (this->ctrl.getDogList().isEmpty())
							{
								cout << "The database is empty. No dogs available for adoption."; continue;
							}
							this->ctrl.nextDogList();
							Dog d = this->ctrl.getDogList().getCurrentDog();

							cout << "The current dog -  Breed: " << d.getBreed() << " NAME: " << d.getName() << " AGE: " << d.getAge() << endl;
							break;
						}

						case 2:
						{
							if (this->ctrl.getDogList().isEmpty())
							{
								cout << "The database is empty. No dogs available for adoption."; continue;
							}

							Dog d1 = this->ctrl.getDogList().getCurrentDog();
							this->ctrl.addDogToAdoption(d1);

							cout << "You just adopted this dog -  Breed: " << d1.getBreed() << " NAME: " << d1.getName() << " AGE: " << d1.getAge() << endl;
							break;
						}
						}
					}
					break;
				}

				case 3:
				{

					this->ctrl.addAllDogs();
					this->ctrl.cleanBreed();
					std::string breedreq;
					cout << endl << "Enter the breed you want ";
					cin >> breedreq;
					int age;
					cout << endl << "Enter the age ";
					cin >> age;
					this->ctrl.addDogsByBreedAndAge(breedreq, age);
					if (this->ctrl.getBreedList().isEmpty())
					{
						cout << "The database is empty. No dogs of the given breed and age available for adoption."; continue;
					}
					this->ctrl.startBreedList();
					Dog ddd = this->ctrl.getBreedList().getCurrentDog();
					cout << "The current dog -  Breed: " << ddd.getBreed() << " NAME: " << ddd.getName() << " AGE: " << ddd.getAge() << endl;

					while (true)
					{

						UI::printBreedMenu();
						int commandAll{ 0 };
						cout << "Input the command: ";
						cin >> commandAll;
						cin.ignore();
						if (commandAll == 0)
							break;
						switch (commandAll)
						{
						case 1:
						{
							if (this->ctrl.getBreedList().isEmpty())
							{
								cout << "The database is empty. No dogs available for adoption."; continue;
							}
							this->ctrl.nextBreedList();
							Dog dd = this->ctrl.getBreedList().getCurrentDog();

							cout << "The current dog -  Breed: " << dd.getBreed() << " NAME: " << dd.getName() << " AGE: " << dd.getAge() << endl;
							break;
						}

						case 2:
						{
							if (this->ctrl.getBreedList().isEmpty())
							{
								cout << "The database is empty. No dogs available for adoption."; continue;
							}

							Dog d2 = this->ctrl.getBreedList().getCurrentDog();
							this->ctrl.addDogToAdoption(d2);

							cout << "You just adopted this dog -  Breed: " << d2.getBreed() << " NAME: " << d2.getName() << " AGE: " << d2.getAge() << endl;
							break;
						}
						}
					}
					break;
				}
				case 2:
				{
					if (this->ctrl.getDogList().isEmpty())
					{
						cout << "You did not adopt any dog."; continue;
					}
					this->ctrl.startAdoptionList();
					Dog d = this->ctrl.getAdoptionList().getCurrentDog();

					cout << "The current adopted dog -  Breed: " << d.getBreed() << " NAME: " << d.getName() << " AGE: " << d.getAge() << endl;
					while (true)
					{
						UI::printAdoptionMenu();
						int commandAdopt{ 0 };
						cout << "Input the command: ";
						cin >> commandAdopt;
						cin.ignore();
						if (commandAdopt == 0)
							break;
						switch (commandAdopt)
						{
						case 1:
						{
							if (this->ctrl.getAdoptionList().isEmpty())
							{
								cout << "No dogs adopted."; continue;
							}
							this->ctrl.nextAdoptionList();
							Dog d4 = this->ctrl.getAdoptionList().getCurrentDog();

							cout << "The current adopted dog -  Breed: " << d4.getBreed() << " NAME: " << d4.getName() << " AGE: " << d4.getAge() << endl;
							break;
						}

						}
					}
					break;
				}

				}


			}
		}
	}
}
