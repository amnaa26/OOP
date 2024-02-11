/*
	Programmer: Amna(23K-0066)
	Question: Your task is to implement a basic Student Registration System in C++. Define two structures, Register and Student, 
			  where Register includes attributes courseId and courseName, and Student inherits from Register while having additional 
			  attributes such as studentId, firstName, lastName, cellNo, and email. Your objective is to create an array of Student structures 
			  to store data for five students. Write a C++ program that accomplishes the following tasks:
				1. Implement the Register and Student structures.
				2. Inherit the Register structure in the Student structure.
				3. Create an array of Student structures to store data for 5 students.
				4. Take input for each student, including their courseId, courseName, studentId, firstName, lastName, cellNo, and email.
				5. Display the information for all 5 students.
*/

#include <iostream>
#include <string>
using namespace std;


struct Register {
    string courseId;
    string courseName;
};


struct Student {
    Register courseInfo;
    string studentId;
    string firstName;
    string lastName;
    string cellNo;
    string email;
};

int main() {
    Student students[5];

    // Input student information
    for (int i = 0; i < 5; ++i) {
        cout << "Enter details for Student " << i + 1 << ":" << endl;
        cout << "Course ID: ";
        getline(cin, students[i].courseInfo.courseId);
        cout << "Course Name: ";
        getline(cin, students[i].courseInfo.courseName);
        cout << "Student ID: ";
        getline(cin, students[i].studentId);
        cout << "First Name: ";
        getline(cin, students[i].firstName);
        cout << "Last Name: ";
        getline(cin, students[i].lastName);
        cout << "Cell No: ";
        getline(cin, students[i].cellNo);
        cout << "Email: ";
        getline(cin, students[i].email);
        
        cout << endl;
    }

    // Display student information
    cout << "\n-----Student Information------" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << "Student " << i + 1 << ":\n";
        cout << "Course ID: " << students[i].courseInfo.courseId << endl;
        cout << "Course Name: " << students[i].courseInfo.courseName << endl;
        cout << "Student ID: " << students[i].studentId << endl;
        cout << "Name: " << students[i].firstName << " " << students[i].lastName << endl;
        cout << "Cell No: " << students[i].cellNo << endl;
        cout << "Email: " << students[i].email << endl;
        cout << endl;
    }

    return 0;
}

