//LinkedList.h
#pragma once
#include "Node.h"
class LinkedList
{
public:
	LinkedList();   //A constructor
	void append(int value);   //An append function

	void print();   //A print function
private:
	Node* head;
};
