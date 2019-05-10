#pragma once
#include "Repository.h"
#include "Adoption.h"
#include <iostream>
using namespace std;

class Controller
{
private:
	Repository repo;
	Adoption list;

public:
	Controller(const Repository& repo) : repo(repo) {}
	/*Function that adds a dog element to the repository
	in:dog-an instance of Dog class
	out:
	*/
	void add(const Dog& dog);

	/*Function that returns the vector of elements
	*/
	
	

	Dog* getAllPtr()const { return this->repo.getAllPtr(); }
	DynamicVector<Dog> getAll()const { return this->repo.getAll(); }



	void remove(string breed, string name);
	void update(string breed, string name, string newBreed, string newName, int newAge, string newPhotograph);
	/*Function that returns the number of dog objects in repository
	*/
	int getSize() const { return this->repo.getSize(); };
	/*Function that returns a dog found on a certain position in the vector
	inex-the position
	*/
	Dog getIndex(int index);
	
	
	//METHODS for adoption list
	void addAdoptionList(string breed, string name, int age, string photograph);
	DynamicVector<Dog> getAllAdopted();

};