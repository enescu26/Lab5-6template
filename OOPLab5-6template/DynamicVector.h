#pragma once
#include "Dog.h"

template <typename T>
class DynamicVector
{
private:
	T* elems;
	int size;
	int capacity;
public:
	//default constructor for a DynamicVector
	DynamicVector(int capacity = 10);

	//copy constructor for a DynamicVector
	DynamicVector(const DynamicVector& v);

	//destructor for a DynamicVector
	~DynamicVector();

	// assignment operator for a DynamicVector
	DynamicVector& operator=(const DynamicVector& v);

	// Adds an element to the current DynamicVector
	void add(const T e);

	/*Overloading the subscript operator
	in:: pos - a valid position within the vector
	out: a reference to the element o position pos.
	*/
	T& operator[](int index);


	int getSize() const;
	T *getDogs() const;

	void remove(string breed, string name);
	void update(string breed, string name, string newBreed, string newName, int newAge, string newPhotograph);
	/*
	The method that returns the stored dog to index-1 position (indexed from 0) from the array elem
	in: index
	out: the corresponding dog
	*/
	T getIndex(int index);
private:
	// Resizes the current DynamicVector, multiplying its capacity by a given factor (real number)
	void resize(double factor = 2);

};


template <typename T>
DynamicVector<T>::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new T[capacity];
}
template <typename T>
DynamicVector<T>::DynamicVector(const DynamicVector& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
}
template <typename T>
DynamicVector<T>::~DynamicVector() {
	delete[] this->elems;
}
template <typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector& v) // pentru repo 
{
	if (this == &v)
		return *this;

	this->size = v.size;
	this->capacity = v.capacity;

	delete[] this->elems;
	this->elems = new T[this->capacity];

	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];

	return *this;
}
template <typename T>
void DynamicVector<T>::resize(double factor)
{
	this->capacity *= static_cast<int>(factor);

	T* elem = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
		elem[i] = this->elems[i];

	delete[] this->elems;
	this->elems = elem;
}

template <typename T>
void DynamicVector<T>::add(const T e) {
	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;
}

template <typename T>
T& DynamicVector<T>::operator[](int index) {
	return this->elems[index];
}

template <typename T>
void DynamicVector<T>::remove(string breed, string name)
{
	int res = -1;
	for (int index = 0; index < this->getSize(); index++)
	{
		if (this->elems[index].getBreed() == breed && this->elems[index].getName() == name) {
			res = index;
			break;
		}
	}
	if (res != -1) {
		for (int index = res; index <= this->getSize()-2; index++)
		{
			this->elems[index] = this->elems[index + 1];
		}
		this->size--;
	}
}

template <typename T>
void DynamicVector<T>::update(string breed, string name, string newBreed, string newName, int newAge, string newPhotograph) {
	int ok = 0;
	for (int index = 0; index < this->getSize(); index++)
		if (this->elems[index].getBreed() == breed && this->elems[index].getName() == name)
		{
			ok = 1;
			this->elems[index].setBreed(newBreed);
			this->elems[index].setName(newName);
			this->elems[index].setAge(newAge);
			this->elems[index].setPhotograph(newPhotograph);
		}
}

template <typename T>
T DynamicVector<T>::getIndex(int index) {
	return this->elems[index];
}
template <typename T>
int DynamicVector<T>::getSize() const { return this->size; }
template <typename T>
T* DynamicVector<T>::getDogs() const { return this->elems; }
//DynamicVector<T> DynamicVector<T>::getDogs() const { return this->elems; }