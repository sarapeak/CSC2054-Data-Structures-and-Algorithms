#include <iostream>
#include <string>
using namespace std;

#include "printMenu.h";

string printMenu()
{
	string menu;   //A string that is added on
	menu += "Menu:\n";
	menu += "s: set a value\n";
	menu += "p: print a value\n";
	menu += "d: delete a value\n";
	menu += "i: create a new int\n";
	menu += "w: add two values\n";
	menu += "q: quit\n";
	menu += " : ->> ";

	return menu;   //Returns the completed string
}