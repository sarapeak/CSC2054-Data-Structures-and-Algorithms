#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Adult.h"

Adult::Adult()
{

}
//Takes in the adult's information
Adult::Adult(string adultName, string adultAge, string adultMeds, string adultStay, string adultAllergy)
{
	name = adultName;
	age = adultAge;
	meds = adultMeds;
	stay = adultStay;
	allergy = adultAllergy;
}
Adult::~Adult()
{
	
}
//Prints out the adult's information
void Adult::print()
{
	cout << "\nPatient Name: " << name << "\n";
	cout << "Patient Age: " << age << "\n";
	cout << "Medications: " << meds << "\n";
	cout << "Length of Stay: " << stay << "\n";
	cout << "Allergies: " << allergy << "\n";
	cout << "\n";
}