#include <iostream>
#include <string>
using namespace std;

#include "menu.h"

string printMenu()
{
	string menu;   //A string that will have menu items added onto it

	menu += "\nWhat would you like to do?\n";
	menu += "1. Add a duck.\n";
	menu += "2. Fly a duck.\n";
	menu += "3. Print the pond.\n";
	menu += "4. Quit.\n";
	menu += ">> ";

	return menu;   //Returns the string menu
}