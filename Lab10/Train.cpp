#include <vector>
#include <iostream>
#include <list>
using namespace std;

#include "Train.h"

//Constructor for train that takes in a string and int
Train::Train(string name_in, int number_in)
{
	//Sets the private variables equal to the variables inputted
	trainNumber = number_in;
	trainName = name_in;
}
//A hash function that takes in an int
unsigned int Train::hash(int tablesize)
{
	unsigned int value = trainNumber;   //Sets the value equal to the trainNumber
	for (int i = 0; i < trainName.size(); i++)
	{
		//Adds to value each loop
		value += (trainNumber + 11) * value + trainName[i];
	}
	return value % tablesize;   //Returns the modulus of value and tablesize
}
//An overload operator that prints out the train name and number
ostream& operator << (ostream& out, Train* t)
{
	out << t->trainName << " " << t->trainNumber;
	return out;
}