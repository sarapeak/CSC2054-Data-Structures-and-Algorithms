#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "getString.h";   //Includes the getString h file

void movePlayer(char letter, int & thePlayer)   //Takes in a char and int
{
	if (letter == 'a')   //If the letter is 'a'
	{
		thePlayer = thePlayer - 1;   //the player position is moved 1 to the left
		//If the player is -1, it makes the player's position equal to 0
		if (thePlayer == -1)
		{
			thePlayer = 0;
		}
	}
	else if (letter == 'd')   //If the letter is 'd'
	{
		thePlayer = thePlayer + 1;   //The player's position is moved 1 to the right
	}
	else if (letter == 'f')   //If the letter is 'f'
	{
		thePlayer = thePlayer + 2;   //The player's position is moved 2 to the right
	}
}