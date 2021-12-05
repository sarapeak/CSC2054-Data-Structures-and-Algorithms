#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
using namespace std;

#include "Level.h"

int main()
{
	vector<string> levels;   //A vector that stores the level files
	string levelName;        //Stores the level file name
	ifstream levelFiles;     //Helps to read the files
	Level* levelClass = 0;   //A Level* that haleps to call the functions from the level class

	//Pushes back each file
	levels.push_back("Level1.txt");
	levels.push_back("Level2.txt");
	levels.push_back("Level3.txt");

	//Loops through the files to print out the level name
	for (int i = 0; i < levels.size(); i++)
	{
		levelFiles.open(levels.at(i));   //Opens the file
		if (levelFiles.fail())    //If the file fails to open, it exits
		{
			cerr << "Unable to open the file.";
			exit(1);
		}
		else
		{
			levelFiles >> levelName;     //Reads in the level name
			cout << levelName << "\n";   //Prints out the level name
		}
		levelFiles.close();   //Closes the file
	}

	map<string, Level*> myMap;   //A map of string and level pointers
	//Reads each of the levels from the files
	Level* level1 = levelClass->readLevel("Level1.txt");
	Level* level2 = levelClass->readLevel("Level2.txt");
	Level* level3 = levelClass->readLevel("Level3.txt");

	//Inserts each level into the map
	myMap.insert(myMap.begin(), pair<string, Level*>("Level1.txt", level1));
	myMap.insert(myMap.begin(), pair<string, Level*>("Level2.txt", level2));
	myMap.insert(myMap.begin(), pair<string, Level*>("Level3.txt", level3));

	//Loops through the map
	for (map<string, Level*>::iterator it = myMap.begin(); it != myMap.end(); ++it)
	{
		pair<string, Level*> p = *it;   //Calls on each of the pairs
		levelClass->writeLevel(p.first + "_OUT", p.second);   //Outputs the information from the level into a new text file
	}
}