#include <iostream>
#include <string>
#include <vector>
using namespace std;

#include "Adult.h"
#include "Pediatric.h"
#include "Patient.h"

int main()
{
	//Variables used to take in the user's input
	char userInput;
	string patientName;
	int patientAge = 0;
	string age;
	string patientMeds;
	string patientStay;
	string patientAllergy;
	string patientYN;
	string kidSchool;
	string contact;
	string info;

	//These variables help to change information
	string newName;
	int newAge = 0;
	string newPatientAge;
	string newMeds;
	string newStay;
	string newAllergy;
	bool newYN = false;
	string newSchool;
	string newContact;
	string status;

	//The menu
	cout << "1. Enter a new patient.\n";
	cout << "2. List of all patients.\n";
	cout << "3. Remove patient from records.\n";
	cout << "4. Change patient information.\n";
	cout << "5. Find information for a particular patient.\n";
	cout << "6. Quit.\n";
	cout << "Choose a number for what you want to do:\n";
	cout << "> ";

	//A vector of Patient pointers
	vector<Patient*> patients;
	//p and a are Patient pointers to help store a child or adult in the system
	Patient* p;
	Patient* a;

	//Loops through until statement is false
	do
	{
		cin >> userInput;   //Takes in a user's input

		//A switch statement for the menu items
		switch (userInput)
		{
			//User enters a new patient and their information
			case '1':
				//Asks for the patient's name
				cout << "What is the patient's name?\n";
				cout << "> ";
				cin >> patientName;

				//Asks for the patient's age
				cout << "How old is the patient?\n";
				cout << "> ";
				cin >> patientAge;
				age = to_string(patientAge);   //Changes the age to a string

				//Asks for the patient's medications
				cout << "List the medications the patient is taking. If there are none, say 'None'.\n";
				cout << "> ";
				cin >> patientMeds;

				//Asks for how long the paitent is staying
				cout << "How long is the patient staying? Enter the number of days.\n";
				cout << "> ";
				cin >> patientStay;

				//Asks for the patient's allergies
				cout << "List any allergies the patient has. If there are none, say 'None'.\n";
				cout << "> ";
				cin >> patientAllergy;

				//Determines if the patient is going to be apart of pediatric or adult
				if (patientAge < 18)
				{
					//Asks if the patient will resume school
					cout << "Will the patient resume school while staying? Enter 'Yes' or 'No'.\n";
					cout << "> ";
					cin >> patientYN;
					//Determines if the patient is continuing school or not
					if (patientYN == "Yes" || patientYN == "yes" || patientYN == "YES")
					{
						//Asks for the name of the patient's school
						cout << "What is the name of the patient's school?\n";
						cout << "> ";
						cin >> kidSchool;

						//Asks for the school's contact information
						cout << "Who should we contact at the school? What is his/her contact information?\n";
						cout << "> ";
						cin >> contact;

						//Adds p (a child) with school info to the vector
						p = new Pediatric(patientName, age, patientMeds, patientStay, patientAllergy, kidSchool, contact);
						patients.push_back(p);
					}
					else
					{
						//Adds p (a child) with no school to the vector
						p = new Pediatric(patientName, age, patientMeds, patientStay, patientAllergy);
						patients.push_back(p);
					}
				}
				else
				{
					//Adds a (an adult) to the vector
					a = new Adult(patientName, age, patientMeds, patientStay, patientAllergy);
					patients.push_back(a);
				}
				cout << "Patient added.\n";
				cout << "Choose another number:\n";
				cout << "> ";
				break;

			//Lists all of the patients in the system
			case '2':
				//Loops through to print out the list
				for (int i = 0; i < patients.size(); i++)
				{
					//Does nothing if the index is NULL
					if (patients.at(i) == NULL)
					{}
					//Prints out if the index has information
					else
					{
						patients.at(i)->print();
					}
				}
				cout << "Choose another number:\n";
				cout << "> ";
				break;

			//Remove a patient from the system
			case '3':
				//Asks for the name of the patient to remove
				cout << "What is the name of the patient you would like to remove?\n";
				cout << "> ";
				cin >> patientName;

				//Loops through the vector to find the matching name
				for (int i = 0; i < patients.size(); i++)
				{
					//Deletes the vector point and sets it to NULL
					if (patients.at(i)->getName() == patientName)
					{
						delete patients.at(i);
						patients.at(i) = NULL;
					}
				}
				cout << "Patient removed.\n";
				cout << "Choose another number:\n";
				cout << "> ";
				break;

			//User can change a patient's information
			case '4':
				//Asks for the patient's name
				cout << "Which patient?\n";
				cout << "> ";
				cin >> patientName;

				//Asks for which information the user would like to change
				cout << "Which information would you like to change?\n";
				cout << "Say Name, Age, Medications, Length, Allergies, inSchoolStatus, School, or SchoolContact.\n";
				cout << "> ";
				cin >> info;

				//Loops through the vector
				for (int i = 0; i < patients.size(); i++)
				{
					//If NULL, it does nothing
					if (patients.at(i) == NULL)
					{}
					//If the name matches
					else if (patients.at(i)->getName() == patientName)
					{
						//Changes the patient's name
						if (info == "Name")
						{
							cout << "What is the patient's new name?\n";
							cin >> newName;
							patients.at(i)->changeName(newName);
							break;
						}
						//Changes the patient's age
						else if (info == "Age")
						{
							cout << "What is the patient's new age?\n";
							cout << "> ";
							cin >> newAge;
							newPatientAge = to_string(newAge);
							patients.at(i)->changeAge(newPatientAge);
							//If the person's age is 18 or above, it changes the child to an adult
							if (newAge >= 18)
							{
								patientName = patients.at(i)->getName();
								patientMeds = patients.at(i)->getMeds();
								patientStay = patients.at(i)->getStay();
								patientAllergy = patients.at(i)->getAllergy();
							
								a = new Adult(patientName, age, patientMeds, patientStay, patientAllergy);
								patients.at(i) = a;
							}
							break;
						}
						//Changes the patient's medications
						else if (info == "Medications")
						{
							cout << "What is the patient's new medications?\n";
							cout << "> ";
							cin >> newMeds;
							patients.at(i)->changeMeds(newMeds);
							break;
						}
						//Changes the patient's length of stay
						else if (info == "Length")
						{
							cout << "What is the patient's new length of stay?\n";
							cout << "> ";
							cin >> newStay;
							patients.at(i)->changeStay(newStay);
							break;
						}
						//Changes the patient's allergies
						else if (info == "Allergies")
						{
							cout << "What is the patient's new allergies?\n";
							cout << "> ";
							cin >> newAllergy;
							patients.at(i)->changeAllergy(newAllergy);
							break;
						}
						//CHanges the person's in school status
						else if (info == "inSchoolStatus")
						{
							cout << "What is the patient's new school status? Please enter in yes for true or no for false.\n";
							cout << "> ";
							cin >> patientYN;
							//If yes, the user is asked about the school and contact information
							if (patientYN == "yes" || patientYN == "Yes" || patientYN == "YES")
							{
								newYN = true;
								cout << "What is the name of the patient's school?\n";
								cout << "> ";
								cin >> kidSchool;

								cout << "Who should we contact at the school? What is his/her contact information?\n";
								cout << "> ";
								cin >> contact;

								patientName = patients.at(i)->getName();
								age = patients.at(i)->getAge();
								patientMeds = patients.at(i)->getMeds();
								patientStay = patients.at(i)->getStay();
								patientAllergy = patients.at(i)->getAllergy();

								p = new Pediatric(patientName, age, patientMeds, patientStay, patientAllergy, kidSchool, contact);
								patients.at(i) = p;
							}
							//If no, the patient's in school status is set to false
							else if (patientYN == "no" || patientYN == "No" || patientYN == "NO")
							{
								newYN = false;
							}
							patients.at(i)->changeSchoolStatus(newYN);
							break;
						}
						//Changes the patient's school information
						else if (info == "School")
						{
							cout << "What is the patient's new school?\n";
							cout << "> ";
							cin >> newSchool;
							patients.at(i)->changeSchool(newSchool);
							break;
						}
						//Changes the patient's school contact information
						else if (info == "SchoolContact")
						{
							cout << "What is the patient's new school contact?\n";
							cout << "> ";
							cin >> newContact;
							patients.at(i)->changeContact(newContact);
							break;
						}
					}
				}
				cout << "Choose another number:\n";
				cout << "> ";
				break;

			//Shows information for a paticular patient
			case '5':
				//Asks for the patient's name
				cout << "Which patient?\n";
				cout << "> ";
				cin >> patientName;

				//Asks for the information the user wants to find for the indicated patient
				cout << "Which information would you like to find?\n";
				cout << "Say Age, Medications, Length, Allergies, inSchoolStatus, School, or SchoolContact.\n";
				cout << "> ";
				cin >> info;

				//Loops through the vector
				for (int i = 0; i < patients.size(); i++)
				{
					//If NULL, it does nothing
					if (patients.at(i) == NULL)
					{}
					//If the name matches up
					else if (patients.at(i)->getName() == patientName)
					{
						//Returns the patient's age
						if (info == "Age")
						{
							cout << "The patient's age is " << patients.at(i)->getAge() << "\n";
							break;
						}
						//Returns the patient's medications
						else if (info == "Medications")
						{
							cout << "The patient's medications is " << patients.at(i)->getMeds() << "\n";
							break;
						}
						//Returns the patient's length of stay
						else if (info == "Length")
						{
							cout << "The patient's length of stay is " << patients.at(i)->getStay() << "\n";
							break;
						}
						//Returns the patient's allergies
						else if (info == "Allergies")
						{
							cout << "The patient's allergies are " << patients.at(i)->getAllergy() << "\n";
							break;
						}
						//Returns the patient's in school status
						else if (info == "inSchoolStatus")
						{
							if (patients.at(i)->getSchoolStatus() == true)
							{
								status = "true.";
							}
							else if (patients.at(i)->getSchoolStatus() == false)
							{
								status = "false.";
							}
							cout << "The patient's school status is " << status << "\n";
							break;
						}
						//Returns the patient's school
						else if (info == "School")
						{
							cout << "The patient's school is " << patients.at(i)->getSchool() << "\n";
							break;
						}
						//Returns the patient's school contact information
						else if (info == "SchoolContact")
						{
							cout << "The patient's school contact is " << patients.at(i)->getContact() << "\n";
							break;
						}
					}
				}
				cout << "Choose another number:\n";
				cout << "> ";
				break;

			//Ends the Program
			case '6':
				break;
		}
	} while (userInput != '6');
}