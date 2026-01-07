#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>
using namespace std;
//header guard and imports
class Student{
	public: //public constructor, destructor, and functions
		Student(char*, int, float);
		~Student();
		char* getName();
		int getID();
		float getGPA();
		void print();
	private: //private variables
		char* name;
		int ID;
		float GPA;
};
#endif //header guard end
