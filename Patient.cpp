#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Patient.h"

Patient::Patient()
{
	
}
Patient::~Patient()
{
	
}
string Patient::getName()const
{
	return name;
}
string Patient::changeName(string newPatientName)
{
	name = newPatientName;
	return name;
}

string Patient::getAge()const
{
	return age;
}
string Patient::changeAge(string newPatientAge)
{
	age = newPatientAge;
	return age;
}

string Patient::getMeds()const
{
	return meds;
}
string Patient::changeMeds(string newPatientMeds)
{
	meds = newPatientMeds;
	return meds;
}

string Patient::getStay()const
{
	return stay;
}
string Patient::changeStay(string newPatientStay)
{
	stay = newPatientStay;
	return stay;
}

string Patient::getAllergy()const
{
	return allergy;
}
string Patient::changeAllergy(string newPatientAllergy)
{
	allergy = newPatientAllergy;
	return allergy;
}

string Patient::getSchool()const
{
	return school;
}
string Patient::changeSchool(string newPatientSchool)
{
	school = newPatientSchool;
	return school;
}

string Patient::getContact()const
{
	return contact;
}
string Patient::changeContact(string newPatientContact)
{
	contact = newPatientContact;
	return contact;
}

bool Patient::getSchoolStatus()const
{
	return schooling;
}
bool Patient::changeSchoolStatus(bool schoolYN)
{
	schooling = schoolYN;
	return schooling;
}