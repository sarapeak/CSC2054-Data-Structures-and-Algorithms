#include <iostream>
#include <string>
using namespace std;

#include "add.h";

int add(int *ptr1, int *ptr2)
{	
	int result = *ptr1 + *ptr2;   //Adds the pointer values

	return result;   //Returns the result of the added pointers
}