#include "DynamicVector.h"

DynamicVector::DynamicVector(int capacity)
{
	this->size = 0;
	this->capacity = capacity;
	this->elems = new TElement[capacity];
}
void DynamicVector::cleanDynamicVector()
{
	this->size = 0;
}
DynamicVector::DynamicVector(const DynamicVector& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < v.size; i++)
	{
		this->elems[i] = v.elems[i];
	}

}

DynamicVector::~DynamicVector()
{
	delete[] this->elems;

}

DynamicVector& DynamicVector::operator=(const DynamicVector& v)
{
	if (this == &v)
		return *this;
	this->size = v.size;
	this->capacity = v.capacity;
	delete[] this->elems;
	this->elems = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
		this->elems[i] = v.elems[i];
	return *this;

}

void DynamicVector::add(TElement e)
{

	if (this->size == this->capacity)
		this->resize();
	this->elems[this->size] = e;
	this->size++;

}
void DynamicVector::update(TElement e,int pos)
{
	if (pos > this->size)
		return;
	this->elems[pos]=e;
}
void DynamicVector::deleteOnPos(int pos)
{
	for (int i = pos; i < this->size - 1; i++)
		this->elems[i] = this->elems[i + 1];
	this->size--;

}
void DynamicVector::resize(double factor)
{

	this->capacity *= factor;
	TElement* els = new TElement[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		els[i] = this->elems[i];
	}
	delete[] this->elems;
	this->elems = els;


}

TElement* DynamicVector::getAllElems() const
{
	return this->elems;

}

int DynamicVector::getSize() const
{
	return this->size;

}