// CoursePlanner.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int maximumPreRequisite;
int choice;

//Structure of a course

struct Course {
	string courseNumber = NULL;
	string name = NULL;
	string prerequisite1 = NULL;
	string prerequisite2 = NULL;
};

//Tree node structure

struct Node {
	Course course;
	Node* left;
	Node* right;

	//Constructor
	Node() {
		left = nullptr;
		right = nullptr;
	}

	//Init with a course
	Node(Course aCourse) :
		Node() {
		course = aCourse;
	}
};

class BinarySearchTree {
private:
	Node* root;

	void printCourseList(Node* node);
	void printCourse(Node* node);
	void loadFile();
public:
	Course Search(Node* node, string courseNumber);
};

//Default Tree Constructor
BinarySearchTree::BinarySearchTree() {
	root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
	delete root;
}

void BinarySearchTree::printCourseList(Node* node) {
	if (root != nullptr) {
		if (node->left != nullptr) {
			printCourseList(node->left);
		}
		cout << node->course.courseNumber << " " << node->course.name << endl;
		if(node->right != nullptr){
			printCourseList(node->right);
		}
	}
	else {
		cout << "No Courses Loaded." << endl;
	}
}

//Attempt to load and read file contents
void loadFile(){
	fstream myfile("courseFile.csv");
	if (myfile.is_open()) {
		string line;
		while (getline(myfile, line)) {
			Course course;
			course.courseNumber[0];
			course.name[1];
			course.prerequisite1[2];
			course.prerequisite2[3];
		}
		myfile.close();
	}
}

void BinarySearchTree::printCourse(Node* node) {
	cout << node->course.courseNumber << ", " << node->course.name << endl;

	//prerequisite2 has no course in it, enter into if prerequisite1 has no course or a course
	if (node->course.prerequisite2.empty()) {
		if (node->course.prerequisite1.empty()) {
			cout << "No Pre-Requisite Courses";
		}
		else {
			cout << "Pre-Requisite Course:" << node->course.prerequisite1;
		}
		//prerequisite2 has a course in it so both fields have something in them
	}
	else {
		cout << "Prerequisites: " << node->course.prerequisite1 << ", " << node->course.prerequisite2;
	}

}


Course BinarySearchTree::Search(Node* node, string courseNumber) {
	Node* curNode = root;

	while (curNode != nullptr) {
		//If the curNode equal to search it will send up the course and pre-reqs
		if (curNode->course.courseNumber == courseNumber) {
			return printCourse(node);
		}
		//curNode not equal to search key
		else {
			if (curNode->course.courseNumber < courseNumber) {
				curNode = curNode->left;
			}
			else {
				curNode = curNode->right;
			}
		}
	}
		cout << "Course is not in this program.";
}




int main()
{
	
	BinarySearchTree* BST;
	BST = new BinarySearchTree();
	Course course;

//Menu
	while (choice != 4) {
		cout << "Course Menu" << endl;
		cout << " 1. Load Data Structure." << endl;
		cout << " 2. Print Course List." << endl;
		cout << " 3. Print Course. " << endl;
		cout << " 4. Exit" << endl;
		cout << endl;
		cout << "What would you like to do? " << endl;
		cin >> choice;
		cout << choice;

		switch (choice) {
		case 1:
			loadFile();
			break;
		case 2:
			printCourseList(root);
			break;
		case 3:
			printCourse(node);
			break;
		case 4:
			cout << "Thank you for using the course planner!" << endl;
			choice = 4;
			break;
		default:
			cout << choice << " is not a valid option" << endl;
			break;
		}

	}
	
}

