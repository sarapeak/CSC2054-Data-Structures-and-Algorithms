#pragma once
#include "Patient.h"

class Pediatric : public Patient
{
public:
	//A default constructor
	Pediatric();
	//A constructor for a child not going to school
	Pediatric(string name, string age, string meds, string stay, string allergy);
	//A constructor for a child going to school
	Pediatric(string name, string age, string meds, string stay, string allergy, string school, string contact);
	//A destructor for Pediatric
	~Pediatric();
	//A print function
	void print();
};