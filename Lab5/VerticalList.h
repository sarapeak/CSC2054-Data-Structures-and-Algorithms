#pragma once
#include <iostream>
#include "LinkedList.h"
#include "Node.h"
#include "LinkedList.h"
using namespace std;

class VerticalList
{
private:
	Node* head;

public:
	//Constructors for VerticalList
	VerticalList();
	~VerticalList();   //Destructor
	VerticalList(const VerticalList& vl);   //Copy constructor
	
	//Functions
	const VerticalList& operator=(const VerticalList & rhs);   //= operator

	void incrementList();
	void printVerticalList();
};