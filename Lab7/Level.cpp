#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

#include "Level.h"

Level::Level()
{ }

Level* Level::readLevel(string name)
{
    ifstream fileIf;   //Allows niformation from a file to be inputted into a variable
    Level* levelPtr = new Level();   //A Level pointer that creates a new level memory block
    
    string ifFileName;   //Takes in the file name

    //Integers that take in the z, x, and y size
    int z = 0;
    int x = 0;
    int y = 0;
    //Integers that take in the z, x, and y location
    int positionZ = 0;
    int positionX = 0;
    int positionY = 0;

    fileIf.open(name);   //Opens the file
    
    //Puts information from the file into the specificed variables
    fileIf >> ifFileName;
    fileIf >> z;
    fileIf >> x;
    fileIf >> y;
    //Has the level pointer set each of the variables
    levelPtr->setFileName(ifFileName);
    levelPtr->setZSize(z);
    levelPtr->setXSize(x);
    levelPtr->setYSize(y);

    levelPtr->levelArray = new int** [levelPtr->getZSize()];   //Points to the z size
    for (int a = 0; a < levelPtr->getZSize(); a++)   //Loops through the z size
    {
        levelPtr->levelArray[a] = new int* [levelPtr->getYSize()];   //Points to the y size
        for (int b = 0; b < levelPtr->getYSize(); b++)    //Loops through the y size
        {
            levelPtr->levelArray[a][b] = new int [levelPtr->getXSize()];   //Points to the x size
            for (int c = 0; c < levelPtr->getXSize(); c++)   //Loops through the x size
            {
                fileIf >> levelPtr->levelArray[a][b][c];   //Inputs the array information from the file to the array
            }
        }
    }
    //Takes in the positions of z, x, and y
    fileIf >> positionZ;
    fileIf >> positionX;
    fileIf >> positionY;
    //Sets each of the z, x, y locations
    levelPtr->setLocationZ(positionZ);
    levelPtr->setLocationX(positionX);
    levelPtr->setLocationY(positionY);
    fileIf.close();   //Closes the file
    return levelPtr;
}
void Level::writeLevel(string name, Level* level)
{
    ofstream fileOf;   //Helps to output the file
    fileOf.open(name, ios::out);   //Opens the file

    //Puts the information of the name and z, x, y sizes to the new file
    fileOf << level->getFileName() << "\n\n";
    fileOf << level->getZSize() << "\n";
    fileOf << level->getXSize() << "\n";
    fileOf << level->getYSize() << "\n\n\n";

    //Loops through the 3D array
    for (int d = 0; d < level->getZSize(); d++)   //Loops through the z size
    {
        for (int e = 0; e < level->getYSize(); e++)   //Loops through the y size
        {
            for (int f = 0; f < level->getXSize(); f++)   //Loops through the x size
            {
                fileOf << level->levelArray[d][e][f] << " ";   //Outputs each section of the array
            }
            fileOf << "\n";   //After a line is finished, it creates a new line
        }
        fileOf << "\n";   //Creates a new block
    }
    //Gets the z, x, and y locations
    fileOf << level->getLocationZ() << " ";
    fileOf << level->getLocationX() << " ";
    fileOf << level->getLocationY() << " ";
    fileOf.close();   //Closes the file
}

string Level::getFileName() const
{
    return fileName;
}
int Level::getZSize() const
{
    return sizeZ;
}
int Level::getXSize() const
{
    return sizeX;
}
int Level::getYSize() const
{
    return sizeY;
}
void Level::setFileName(string name)
{
    fileName = name;
}
void Level::setZSize(int zSize)
{
    sizeZ = zSize;
}
void Level::setXSize(int xSize)
{
    sizeX = xSize;
}
void Level::setYSize(int ySize)
{
    sizeY = ySize;
}
int Level::getLocationZ() const
{
    return locationZ;
}
int Level::getLocationX() const
{
    return locationX;
}
int Level::getLocationY() const
{
    return locationY;
}
void Level::setLocationZ(int zLoc)
{
    locationZ = zLoc;
}
void Level::setLocationX(int xLoc)
{
    locationX = xLoc;
}
void Level::setLocationY(int yLoc)
{
    locationY = yLoc;
}