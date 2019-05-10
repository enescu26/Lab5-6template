#include "Iter.h"



Iter::Iter(const container& c, int index) : c{ c }, index{ 0 } {}


void Iter::first() {
	this->index = 0;
}
void Iter::next()
{
	if (valid())
		this->index++;
}

bool Iter::valid() const
{
	return this->index < c.getSize();
}
Dog Iter::getCurrent() const
{
	if (valid()) return c.getDogs()[this->index];

}