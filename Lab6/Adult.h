#pragma once
#include "Patient.h"

class Adult : public Patient
{
public:
	//Default adult constructor
	Adult();
	//A constructor that takes in the adult's information
	Adult(string name, string age, string meds, string stay, string allergy);
	//A estructor for adult
	~Adult();
	//Print function for adult
	void print();
};