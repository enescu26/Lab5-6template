#include "Controller.h"

void Controller::add(const Dog& dog) {
	repo.add(dog);
}
Dog Controller::getIndex(int index) {
	return this->repo.getIndex(index);
}
void Controller::addAdoptionList(string breed, string name, int age, string photograph)
{
	Dog dog{ breed,name,age,photograph };
	list.addAdoptionList(dog);
}

DynamicVector<Dog> Controller::getAllAdopted() {
	return this->list.getAllAdopted();
}

void Controller::remove(string breed, string name) {
	repo.remove(breed, name);
}

void Controller::update(string breed, string name, string newBreed, string newName, int newAge, string newPhotograph)
{
	repo.update(breed, name, newBreed, newName, newAge, newPhotograph);
}