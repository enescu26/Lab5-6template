#include "Repository.h"

void Repository::add(const Dog& dog)
{

	vector.add(dog);
}
Dog Repository::getIndex(int index) {
	return vector.getDogs()[index];
}
void Repository::remove(string breed, string name) {
	vector.remove(breed, name);
}
void Repository::update(string breed, string name, string newBreed, string newName, int newAge, string newPhotograph) {
	vector.update(breed, name, newBreed, newName, newAge, newPhotograph);
}


