#include "Dog.h"
using namespace std;

Dog::Dog() : breed(""), name(""), age(), photograph("") {}

Dog::Dog(const string & breed, const string & name, const int & age, const string & photograph)
{
	this->breed = breed;
	this->name = name;
	this->age = age;
	this->photograph = photograph;
}