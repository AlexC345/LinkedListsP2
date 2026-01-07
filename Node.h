//using Vishnu's Node.h
#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;

class Student;



class Node {
private:
    Student* student;
    Node* next;      

public:
   
    Node(Student* newStudent);

   
    ~Node();

   
    Node* getNext();

   
    Student* getStudent();

   
    void setNext(Node* newNext);
};

#endif
