#include <iostream>
#include "duck.h"
#include "pond.h"
#include <vector>
using namespace std;

//Defualt DUck constructor
Duck::Duck()
{
}

//Constructor that takes in the name of the duck
Duck::Duck(string name)
{
	duckName = name;
}

//Constructor that takes in the height of the duck
Duck::Duck(int height)
{
	duckHeight = height;
}

//Mutator to increment the height of the duck by 1
int Duck::increaseFlyHeight()
{
	duckHeight = getDuckHeight() + 1;   //Adds 1 to the duckHeight
	return duckHeight;
}

//Accessor that returns the duck name
string Duck::getDuckName()const
{
	return duckName;
}

//Accessor that returns the duck height
int Duck::getDuckHeight()const
{
	return duckHeight;
}