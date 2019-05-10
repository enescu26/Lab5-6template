#pragma once
#include <iostream>
using namespace std;
/*class that defines a dog with its atributes
*/
class Dog
{
private:
	string breed;
	string name;
	int age;
	string photograph;

public:
	//default constructor for a Dog
	Dog();

	//constructor for a  Dog
	Dog(const string&breed, const string&name, const int&age, const string&photograph);

	/* The methods that return all atributes of dog
	*/
	const string getBreed() const { return breed; }
	const string getName() const { return name; }
	int getAge() const { return age; }
	const string getPhotograph() const { return photograph; }


	/* The methods that update all atributes of dog
	*/
	void setBreed(const string&breed) { this->breed = breed; }
	void setName(const string&name) { this->name = name; }
	void setAge(int age) { this->age = age; }
	void setPhotograph(const string&photograph) { this->photograph = photograph; }


	/* The method that verify if two dogs are equal
	in: two dogs
	out: 1 if both are similar, 0 otherwise
	*/
	bool operator==(const Dog& other) {
		return (*this).name == other.name && (*this).breed == breed;
	}
};
