#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "movePlayer.h";   //Includes the movePlayer h file
#include "moveObstacles.h";   //Includes the moveObstacles h file

string getString(int& thePlayer, vector<int>& obstacles)   //Takes in an int and vector
{
	string board;   //A string that will be built up
	
	board += "B";   //Inserts a B to indicate the beginning of the board

	//Loops through to add onto the board
	for (int space = 0; space < 30; space++)
	{
		if (thePlayer == space)   //If thePlayer's position is at space, adds a P
		{
			board += "P";
		}
		else if (obstacles.at(space) == 1)   //If the obstacles position at space has a 1, adds a 0
		{
			board += "0";
		}
		else   //If above arguments are not true, adds a space to the board
		{
			board += " ";
		}
	}

	board += "E\n";   //Adds an E to indicate the end
	//Loops through and adds an X to the board
	for (int i = 0; i < 32; i++)
	{
		board += "X";
	}

	board += "\n\n";   //Adds two lines

	return board;   //Returns the board
}