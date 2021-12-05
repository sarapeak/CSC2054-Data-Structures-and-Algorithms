#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Duck;

class Pond
{
private:
	string name;
	int flyHeight = 0;

	//Duck class vectors: one for names and one for heights
	vector<Duck> names;
	vector<Duck> heights;

public:
	//Constructor
	Pond();
	//Functions
	void addDuck(Duck name, Duck flyHeight);
	void increaseFly(string name);
	void print();
};