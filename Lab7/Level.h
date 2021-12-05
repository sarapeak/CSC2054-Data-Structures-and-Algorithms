#pragma once

class Level
{
private:
	int*** levelArray;   //A 3D pointer array
	
	string fileName;     //A string for the file name

	//Integers to hold the size of the array
	int sizeZ = 0;
	int sizeX = 0;
	int sizeY = 0;
	
	//Integers for the start locations of x, y, and z
	int locationZ = 0;
	int locationX = 0;
	int locationY = 0;

public:
	Level();   //A default constructor that does nothing
	Level* readLevel(string fileName);   //Takes in a string
	void writeLevel(string fileName, Level* levelType);   //Takes in a strng and a Level*
	
	//Accessors to access information in the program
	string getFileName() const;
	int getZSize() const;
	int getXSize() const;
	int getYSize() const;
	int getLocationZ() const;
	int getLocationX() const;
	int getLocationY() const;

	//Sets information given from the program
	void setFileName(string fileName);
	void setZSize(int sizeZ);
	void setXSize(int sizeX);
	void setYSize(int sizeY);
	void setLocationZ(int locationZ);
	void setLocationX(int locationX);
	void setLocationY(int locationY);
};