#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"
using namespace std; //imports

void addNode(Student* &newStudent, Node* &firstN){ //adds a node to end of list
	Node* current = firstN;
	if (current == NULL){//if the first node is undefined:
		firstN = new Node(newStudent);//create a new node at the start with value newStudent
	}
	else{
		while (current->getNext() != NULL){//get to end of node list
			current = current->getNext();
		}
		current->setNext(new Node(newStudent)); //make new node at end of the list
	}
}

void deleteNode(Node* &current, int indexesAway, Node* previous){//deletes a node at a given index in the linked list
	Node* temp = current->getNext();//set a temporary variable to hold next node of current
	if (indexesAway == 0){//if the current node is at the target node to delete:
		if (previous == NULL){//if current node is the first node:
			delete current;
			current = temp;//set new current to the temporary variable
		}
		else if (current->getNext() == NULL){//if current node is last node:
			previous->setNext(NULL);
			delete current;
		}
		else{//if current node is in the middle:
			previous->setNext(current->getNext());
			delete current;
		}
	}
	else{//if current node isn't at the target node:
		deleteNode(temp, indexesAway-1, current); //recursively runs the function again with the next node
	}
}

void printNode(Node* currentNode, Node* firstN){//prints the list
	if (currentNode == firstN){//prints List: at the top
		cout << "List: " << endl;
	}
	if (currentNode != NULL){//as long as current node is not at the end of the list, print the node and run the function again on the next node
		currentNode->getStudent()->print();
		printNode(currentNode->getNext(), firstN);
	}
	else{//if current node is at the end of the list, stop recursion
		cout << endl;
	}
}

int main(){
	bool quitVar = false;
	
	char add[] = "ADD";
	char print[] = "PRINT";
	char del[] = "DELETE";
	char quit[] = "QUIT";
	char avg[] = "AVERAGE";

	char command[1000];

	Node* first = NULL;
	Node* current = NULL;
	char iName[1000];
	int iID;
	float iGPA;
	
	int delIndex;

	float avgSUM;
	int numOfGPA;


	while(!quitVar){
		cout << "Enter command (ADD, PRINT, DELETE, QUIT, AVERAGE): ";
		cin >> command;
		cin.ignore();
		command[7] = '\0';

		if (strcmp(command, del) == 0){ //If you entered DELETE:
			if (first != NULL){
				cout << "Enter index of student to delete: "; //Get input
				cin >> delIndex;
				cin.ignore();
				deleteNode(first, delIndex, NULL);
			}
			else{
				cout << "Add a student first!" << endl;
			}
		}
		else if (strcmp(command, add) == 0){ //If you entered ADD:
			cout << "Enter name: "; //Gets input student variables
			cin.get(iName, 1000);
			cin.get();
			cout << "Enter student ID: ";
			cin >> iID;
			cin.ignore();
			cout << "Enter student GPA: ";
			cin >> iGPA;
			cin.ignore();

			Student *iStudent = new Student(iName, iID, iGPA);

			addNode(iStudent, first);
			cout << "Added student!" << endl;
		}
		else if (strcmp(command, quit) == 0){ //If you entered QUIT:
			cout << "Quitted Program" << endl;
			quitVar = true;//Set quitVar variable to true to break the while loop
		}
		else if (strcmp(command, print) == 0){ //If you entered PRINT:
			printNode(first, first);
		}
		else if (strcmp(command, avg) == 0){ //If you entered AVERAGE:
			current = first;
			avgSUM = 0;
			numOfGPA = 0;
			while (current != NULL){
				avgSUM += current->getStudent()->getGPA();
				numOfGPA += 1;
				current = current->getNext();
			}
			cout << "Average GPA: " << avgSUM/numOfGPA << endl;
		}
		else{ //If you entered non of the above:
			cout << "Unrecognized input. Please try again." << endl;
		}
	}
	return 0;
}
