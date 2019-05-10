#pragma once
#include "DynamicVector.h"
#include <string>

class Adoption 
{
private:
	DynamicVector<Dog> list;
public:
	void addAdoptionList(const Dog& dog) noexcept
	{
		this->list.add(dog);
	}
	const DynamicVector<Dog>& getAllAdopted() noexcept{
		return this->list;
	}
};
