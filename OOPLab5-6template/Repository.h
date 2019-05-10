#pragma once
#include "DynamicVector.h"
class Repository
{
private:
	DynamicVector<Dog> vector;

public:
	Repository() {}

	/*Function that adds a dog element to the repository
	in:dog-an instance of Dog class
	out:
	*/
	void add(const Dog& dog);

	/*Function that returns a dog found on a certain position in the vector
	in:index-the position
	out:
	*/
	Dog getIndex(int index);

	/*Function that returns the number of dog objects in repository
	*/
	int getSize() const { return this->vector.getSize(); };
	/* Function that deletes a dog found by breed and name
	in:2 atributes: breed,name
	*/
	void remove(string breed, string name);

	/* Functions that updates a dog found by breed and name and changes all the atributes
	in:4 atributes:breed,name,age,photograph
	*/
	void update(string breed, string name, string newBreed, string newName, int newAge, string newPhotograph);
	/*Function that returns the vector of elements
	*/
	Dog* getAllPtr() const { return this->vector.getDogs(); }
	DynamicVector<Dog> getAll() const { return this->vector; }
};

