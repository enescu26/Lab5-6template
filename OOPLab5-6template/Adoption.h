#pragma once
#include "DynamicVector.h"
#include <string>

class Adoption 
{
private:
	DynamicVector<Dog> list;
public:
	// in lista de adoption trebuie adaugate obiecte din repository, nu obiecte noi
	void addAdoptionList(const Dog& dog) noexcept
	{
		this->list.add(dog);
	}
	const DynamicVector<Dog>& getAllAdopted() noexcept{
		return this->list;
	}
};
