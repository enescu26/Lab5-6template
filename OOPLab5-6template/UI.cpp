#include "UI.h"
#include <string>

using namespace std;

void UI::printMenu()
{
	cout << endl;
	cout << "0 Exit" << endl;
	cout << "1 Manage dog repository" << endl;
	cout << "2 Pet adoption interface" << endl;
}

void UI::printRepositoryMenu()
{
	cout << endl;
	cout << "1 Add dog" << endl;
	cout << "2 Print all" << endl;
	cout << "3 Delete" << endl;
	cout << "4 Update" << endl;
	cout << "0 Exit" << endl;
}

void UI::printUserMenu()
{
	cout << endl;
	cout << "1 Adopt pet" << endl;
	cout << "2 Choose breed" << endl;
	cout << "3 See adoption list" << endl;
	cout << "0 Exit" << endl;
}


void UI::add()
{
	cout << "Enter the breed: ";
	string breed;
	cin >> breed;
	cout << "Enter the name: ";
	string name;
	cin >> name;
	cout << "Enter the age: ";
	int age;
	cin >> age;
	cout << "Enter the photograph: ";
	string photograph;
	cin >> photograph;
	Dog d = Dog(breed, name, age, photograph);
	ctrl.add(d);
}
void UI::getAll()
{

	Dog* dogs = ctrl.getAllPtr();

	if (dogs == NULL)
		return;

	if (this->getSize() == 0) {
		cout << "There are no dogs to display." << endl;
		//return;
	}

	for (int i = 0; i < this->getSize(); i++)
	{
		Dog d = dogs[i];
		cout << d.getBreed() << " " << d.getName() << " " << d.getAge() << " " << d.getPhotograph() << endl;
	}
}
void UI::remove() {
	cout << "Enter the breed: ";
	string breed;
	cin >> breed;
	cout << "Enter the name: ";
	string name;
	cin >> name;
	int x = this->ctrl.getSize();
	ctrl.remove(breed, name);
	int y = this->ctrl.getSize();
	if (x == y)
		cout << "The dog is not in the database\n";
}
void UI::update() {
	cout << "Enter the breed: ";
	string breed;
	cin >> breed;
	cout << "Enter the name: ";
	string name;
	cin >> name;
	int x = this->ctrl.getSize();
	if (x == 0) {
		cout << "The dog is not in the (empty) database\n";
	}
	else {
		cout << "Enter the  new breed: ";
		string newBreed;
		cin >> newBreed;
		cout << "Enter the new name: ";
		string newName;
		cin >> newName;
		cout << "Enter the new age: ";
		int newAge;
		cin >> newAge;
		cout << "Enter the new photograph: ";
		string newPhotograph;
		cin >> newPhotograph;
		ctrl.update(breed, name, newBreed, newName, newAge, newPhotograph);
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
		if (command == 0)
			break;

		// repository management
		else if (command == 1)
		{
			while (true)
			{
				UI::printRepositoryMenu();
				int commandRepo{ 0 };
				cout << "Input the command: ";
				cin >> commandRepo;
				if (commandRepo == 0) {
					cout << "\nWe left the menu";
					break;
				}
				switch (commandRepo)
				{
				case 1: {
					this->add();
					break;
				}
				case 2: {
					this->getAll();
					break;
				}
				case 3: {
					this->remove();
					break;
				}
				case 4: {
					this->update();
					break;
				}
				}
			}
		}
		else if (command == 2) {//user interface
			while (true)
			{
				printUserMenu();
				int commandUser{ 0 };
				cout << "Input the command: ";
				cin >> commandUser;
				if (commandUser == 0) {
					cout << "\nWe left the menu";
					break;
				}
				switch (commandUser)
				{
				case 1: {
					int i = 0;
					int optAdopt{ -1 };
					bool exit = false;
					while (this->ctrl.getAll().getSize() != 0) {//we still have dogs left at the impound
						i = 0;
						while (i != this->ctrl.getAll().getSize()) {//we iter through the list till we reach the end
							Dog localDog = this->ctrl.getAll().getIndex(i);//current dog
							cout << endl << "\nRASA: " << localDog.getBreed() << " NUME: " << localDog.getName() << " VARSTA: " << localDog.getAge() << " PHOTO " << localDog.getPhotograph();

							cout << endl << "1. Adopt";
							cout << endl << "2. Next";
							cout << endl << "3. STOP";

							cin >> optAdopt;

							if (optAdopt == 1) {//we adopt one dog: we add it to the adoption list and remove it from the impound list(repo)
								this->ctrl.addAdoptionList(localDog.getBreed(), localDog.getName(), localDog.getAge(), localDog.getPhotograph());
								this->ctrl.remove(localDog.getBreed(), localDog.getName());
								
								cout << endl << "\nYou have just addopted:\n\nRASA: " << this->ctrl.getAll()[i].getBreed() << " NUME: " << this->ctrl.getAll()[i].getName() << " VARSTA: " << this->ctrl.getAll()[i].getAge() << " PHOTO " << this->ctrl.getAll()[i].getPhotograph()<<"\n\n\n";
								

							}
							else if (optAdopt == 2) {//next dog, we just increment the index of the list
								i++;
							}
							else if (optAdopt == 3) {//stop adopting
								exit = true;
								break;
							}
							else {
								cout << "\nWrong input!";
							}
						}
						//print one pet (from the repo or a local list)
						//print option 1 = adopt
						//print option 2 = pass
						//print option 3 = exit list
						//if 1 then add pet to adoption list (delete it from repo maybe - because the pet no longer is in the pound)
						//if 2 continue with the next pet
						//if 3 stop iteration
						
						if (exit == true)//exit both while loops(1st for repo, 2nd for index)
							break;
					}
					break;
				}
				case 2: {
					//input breed
					//filter by breed
					//while true iter through the filtered list analogue case 1
					cout << "\nINPUT BREED:";
					string breed;
					cin >> breed;

					DynamicVector<Dog> originalRepo = this->ctrl.getAll();// we use originalrepo variable not to call getAll so many times
					DynamicVector<Dog> filteredRepo;
					//we filter the copy of the repo

					if (breed == "") {
						filteredRepo = originalRepo;
					}
					else {
						for (int i = 0; i < originalRepo.getSize(); i++)

							if (originalRepo[i].getBreed() == breed)
								filteredRepo.add(originalRepo[i]);
					}
					//here, we have our filtered version of the impound list 


					if (filteredRepo.getSize() == 0) {
						cout << "\nTHE FILTER OPERATION GAVE NO RESULTS!";
					}

					int i = 0;
					int optAdopt{ -1 };
					bool exit = false;
					while (filteredRepo.getSize() != 0) {//we still have dogs left at the filtered list
						i = 0;
						while (i != filteredRepo.getSize()) {//we iter through the list till we reach the end
							Dog localDog = filteredRepo[i];//current dog
							cout << endl << "\nRASA: " << localDog.getBreed() << " NUME: " << localDog.getName() << " VARSTA: " << localDog.getAge() << " PHOTO " << localDog.getPhotograph();

							cout << endl << "1. Adopt";
							cout << endl << "2. Next";
							cout << endl << "3. STOP";

							cin >> optAdopt;

							if (optAdopt == 1) {
								this->ctrl.addAdoptionList(localDog.getBreed(), localDog.getName(), localDog.getAge(), localDog.getPhotograph());
								this->ctrl.remove(localDog.getBreed(), localDog.getName());//remove the dog from the impound
								filteredRepo.remove(localDog.getBreed(), localDog.getName());//remove the dog from the local filtered repo

								cout << endl << "\nYou have just addopted:\n\nRASA: " << this->ctrl.getAll()[i].getBreed() << " NUME: " << this->ctrl.getAll()[i].getName() << " VARSTA: " << this->ctrl.getAll()[i].getAge() << " PHOTO " << this->ctrl.getAll()[i].getPhotograph() << "\n\n\n";


							}
							else if (optAdopt == 2) {//next dog, we just increment the index of the list
								i++;
							}
							else if (optAdopt == 3) {//stop adopting
								exit = true;
								break;
							}
							else {
								cout << "\nWrong input!";
							}
						}

						if (exit == true)
							break;
					}

					break;
				}
				case 3: {
					//print adoption list
					DynamicVector<Dog> getThem = this->ctrl.getAllAdopted();
					std::cout << "\nADOPTED DOGS:\n";
					for (int i = 0; i <= getThem.getSize() - 1; i++) {
						cout << endl << "\nRASA: " << getThem[i].getBreed() << " NUME: " << getThem[i].getName() << " VARSTA: " << getThem[i].getAge() << " PHOTO " << getThem[i].getPhotograph();
					}
				}
				}
			}
		}
		else {
			cout << "\nNOT GOOD!";
		}
	}
}