#pragma once
#ifndef TRAIN_H
#define TRAIN_H

#include <string>
#include <ostream>
using namespace std;

class Train
{
public:
	//Variables for the train name and number
	string trainName;
	int trainNumber;
	//A constructor that takes in a string and int
	Train(string name_in, int number_in);
	//The hash function that takes in an int
	unsigned int hash(int tablesize);
};
//Overload operator outside of the class
ostream& operator << (ostream& out, Train* t);

#endif