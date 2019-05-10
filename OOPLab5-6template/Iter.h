#pragma once
#include "DynamicVector.h"
#include "Dog.h"
typedef DynamicVector<Dog> container;
class Iter
{
	friend class DynamicVector<Dog>;
private:
	int index;
	const container& c;
public:
	Iter(const container& c, int index);
	void first();
	void next();
	bool valid() const;
	Dog getCurrent() const;
};

