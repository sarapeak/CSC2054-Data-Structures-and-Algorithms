#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Pediatric.h"

Pediatric::Pediatric()
{

}
//Takes in the child information and sets schooling to false
Pediatric::Pediatric(string kidName, string kidAge, string kidMeds, string kidStay, string kidAllergy)
{
	name = kidName;
	age = kidAge;
	meds = kidMeds;
	stay = kidStay;
	allergy = kidAllergy;

	schooling = false;
}
//Takes in the chold's information and sets the schooling to true
Pediatric::Pediatric(string kidName, string kidAge, string kidMeds, string kidStay, string kidAllergy, string kidSchool, string kidContact)
{
	name = kidName;
	age = kidAge;
	meds = kidMeds;
	stay = kidStay;
	allergy = kidAllergy;
	school = kidSchool;
	contact = kidContact;

	schooling = true;
}
Pediatric::~Pediatric()
{
	
}
//Prints out
void Pediatric::print()
{
	cout << "\nPatient Name: " << name << "\n";
	cout << "Patient Age: " << age << "\n";
	cout << "Medications: " << meds << "\n";
	cout << "Length of Stay: " << stay << "\n";
	cout << "Allergies: " << allergy << "\n";
	//If schooling is true, it prints out the school information
	if (schooling == true)
	{
		cout << "The patient is continuing school while staying.\n";
		cout << "The patient's school is " << school << "\n";
		cout << "The school's contact information is " << contact << "\n";
	}
	//Otherwise prints out that the kid is not continuing school
	else
	{
		cout << "The patient is not continuing school while staying.\n";
	}
	cout << "\n";
}