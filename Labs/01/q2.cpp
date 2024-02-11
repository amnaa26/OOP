/*
Programmer: Amna(23K-0066)
Q2: Design a C++ program to manage student marks. Allow the user to input marks for students in three subjects (Mathematics, English, and Science). 
The program should calculate the total marks, average marks, and display the grade for each student. The user can specify the number of students and then input the marks for each subject for each student.
Finally, display the marks, total, average, and grade for each student. Assume a grading system with the following criteria:
90 or above: Grade A
80-89: Grade B
70-79: Grade C
60-69: Grade D
Below 60: Grade F
*/

struct student{
	int math, english, science, totalMarks;
	float average;
};

#include<iostream>
using namespace std;

int main() {
	int n, i;
	cout << "Enter the number of students: ";
	cin >> n;
	student Students[n];
	
	for(i = 0; i < n; ++i){
		cout << endl;
		cout << "Student " << i + 1;
		cout << "\nMaths: " ;
		cin >> Students[i].math;
		cout << "English: ";
		cin >> Students[i].english;
		cout << "Science: ";
		cin >> Students[i].science;
		Students[i].totalMarks = Students[i].math + Students[i].english + Students[i].science;
		Students[i].average = Students[i].totalMarks / 3;
	}
	
	cout << "\n-----Displaying the student's data------" << endl;
	for(i = 0; i < n; ++i){
		cout << endl;
		cout << "Student " << i + 1 <<endl;
		cout << "Maths: " << Students[i].math << "\nEnglish: " << Students[i].english << "\nScience: " << Students[i].science ;
		cout << "\nTotal Marks are: " << Students[i].totalMarks;
		cout << "\nAverage Marks are: " << Students[i].average;
		
		if(Students[i].average > 80) cout << "\nGrade A" << endl;
		else if (Students[i].average > 79 && Students[i].average < 81) cout << "\nGrade B" << endl;
		else if (Students[i].average && Students[i].average < 80) cout << "\nGrade C" << endl;
		else if (Students[i].average > 59 && Students[i].average < 70) cout << "\nGrade D" << endl;
		else if (Students[i].average < 60) cout << "\nGrade F" << endl;
	}
	
}
