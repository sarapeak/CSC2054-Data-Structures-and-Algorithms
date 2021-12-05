#pragma once

class Patient
{
protected:
	//Variables that can be used in the child classes
	string name, age, meds, stay, allergy, school, contact;
	bool schooling = false;

public:
	Patient();   //A constructor
	virtual void print() = 0;   //An abstract print function
	virtual ~Patient();   //A virtual destructor

	//Mutators and accessors for the different information
	string getName()const;
	string changeName(string name);

	string getAge()const;
	string changeAge(string age);

	string getMeds()const;
	string changeMeds(string meds);

	string getStay()const;
	string changeStay(string stay);

	string getAllergy()const;
	string changeAllergy(string allergy);

	string getSchool()const;
	string changeSchool(string school);

	string getContact()const;
	string changeContact(string contact);

	bool getSchoolStatus()const;
	bool changeSchoolStatus(bool schooling);
};