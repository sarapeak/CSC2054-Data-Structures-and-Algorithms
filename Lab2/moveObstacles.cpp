#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "getString.h";   //Includes the getString h file

void moveObstacles(vector<int>& obstacles)   //Takes in a vector
{
	//Loops through the board
	for (int i = 0; i < 30; i++)
	{
		//Checks if the obstacle at a certain position has a 1 in the position 
		if (obstacles.at(i) == 1)
		{
			obstacles.at(i - 1) = 1;   //Moves the obstacle forward
			obstacles.at(i) = 0;   //Puts a 0 at the position
		}
	}
}