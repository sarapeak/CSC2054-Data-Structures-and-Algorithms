#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Pond;

class Duck
{
private:
	string duckName;
	int duckHeight = 0;

public:
	//Constructors
	Duck();
	Duck(string duckName);
	Duck(int duckHeight);
	
	//Functions
	int increaseFlyHeight();    //Mutator
	string getDuckName()const;  //Accessor
	int getDuckHeight()const;   //Accessor
};