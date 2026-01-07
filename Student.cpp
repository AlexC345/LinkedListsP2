#include <iostream>
#include <cstring>
#include <iomanip>
#include "Student.h"
using namespace std; //imports

Student::Student(char* inputName, int inputID, float inputGPA){ //constructor
	name = new char[1000];
	strcpy(name, inputName);
	ID = inputID;
	GPA = inputGPA;
}

Student::~Student(){//destructor
	delete name;
}

char* Student::getName(){//returns student name
	return name;
}

int Student::getID(){//returns student ID
	return ID;
}

float Student::getGPA(){//returns student GPA
	return GPA;
}

void Student::print(){//prints student info
	cout << "Name: " << name << " ID: " << ID << " GPA: " << fixed << setprecision(2) << GPA << endl;
}
