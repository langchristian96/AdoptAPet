#pragma once
#include "Dog.h"

typedef Dog TElement;

class DynamicVector
{
private:
	TElement* elems;
	int size;
	int capacity;

public:
	DynamicVector(int capacity = 10); //Default constructor for dynamic vector
	DynamicVector(const DynamicVector& v); //Copy constructor for a dynamic vector
	~DynamicVector();

	DynamicVector& operator=(const DynamicVector& v); //assignment operator for Dynamic Vector
	void cleanDynamicVector();
	void add(TElement e); //Adds an element to the Dynamic Vector
	void update(TElement e,int pos);
	void deleteOnPos(int pos);


	int getSize() const;

	TElement* getAllElems() const;
private:
	void resize(double factor = 2); //Resizez the current dynamic vector, multiplying its capacity by a given factor






};