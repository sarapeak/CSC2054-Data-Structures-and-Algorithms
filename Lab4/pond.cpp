#include <iostream>
#include "duck.h"
#include "pond.h"
#include <vector>
using namespace std;

//Constructor that takes in the names and heights of the vectors Duck
Pond::Pond()
{
	vector<Duck> names;
	vector<Duck> heights;
}

//Adds the name and height to the pond
void Pond::addDuck(Duck name, Duck flyHeight)
{
	names.push_back(name);        //Pushes the name to the end of the vector
	heights.push_back(flyHeight); //Pushes the height to the end of the vector
}

//Increases the height of the duck
void Pond::increaseFly(string name)   //Takes in the name of the duck
{
	for (int i = 0; i < names.size(); i++)   //Loops through the names vector
	{
		Duck nameOfDuck = names.at(i);   //Assigns the object of duck to the name at the index of the vector

		if (nameOfDuck.getDuckName() == name)   //If the name matches the name inputted
		{
			heights.at(i).increaseFlyHeight();  //Increments the height at the same index as in names
		}
	}
}

//Prints the pond out
void Pond::print()
{
	for (int i = 0; i < names.size(); i++)   //Loops through the vector size
	{
		Duck theDuck = names.at(i);     //Finds the name at the i index
		Duck theHeight = heights.at(i); //Finds the height at the i index
		//Prints the pond out
		cout << "Name: " << theDuck.getDuckName() << "\tHeight: " << theHeight.getDuckHeight() << "\n";
	}
}