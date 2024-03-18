/*
 * Programmer: Amna(23k-0066)
 * Desc: Create two classes: Student and Course for a School Management System.
		 - Student class properties: student ID, student name, list of enrolled courses.
		 - Course class properties: course code, course name, course credit hours.

		 Student class member functions:
		 - Constructor to initialize student ID and name.
		 - "enroll" function to add a Course object to the list of enrolled courses.
		 - "drop" function to remove a Course object from the list of enrolled courses.
		 - "getTotalCreditHours" function to return the total credit hours of enrolled courses.
		 - "printEnrolledCourses" function to print details of enrolled courses.
*/

#include <iostream>
#include <string>
using namespace std;

class Courses {
    string code, name;
    int creditHour;

public:
    Courses() {}
    Courses(string code, string name, int time) {
        this->code = code;
        this->name = name;
        creditHour = time;
    }

    string getCourseCode() const { return code; }
    string getCourseName() { return name; }
    int getCreditHours() { return creditHour; }
};

class Student {
    string studentId;
    string studentName;
    Courses* enrolled_courses;
    int numOfCourses;

public:
    Student(string id, string name) {
        studentId = id;
        studentName = name;
        numOfCourses = 0;
        enrolled_courses = NULL;
    }

    void enroll(const Courses& course) {
        Courses* temp = new Courses[numOfCourses + 1];
        for (int i = 0; i < numOfCourses; ++i) {
            temp[i] = enrolled_courses[i];
        }
        temp[numOfCourses] = course;
        delete[] enrolled_courses;
        enrolled_courses = temp;
        numOfCourses++;
    }

    void drop(const Courses& course) {
        Courses* temp = new Courses[numOfCourses - 1];
        int j = 0;
        for (int i = 0; i < numOfCourses; ++i) {
            if (enrolled_courses[i].getCourseCode() != course.getCourseCode() ) {
                temp[j++] = enrolled_courses[i];
            }
        }
        delete[] enrolled_courses;
        enrolled_courses = temp;
        numOfCourses--;
    }

    int getTotalCreditHours() {
        int creditHour = 0;
        for (int i = 0; i < numOfCourses; ++i) {
            creditHour += enrolled_courses[i].getCreditHours();
        }
        return creditHour;
    }

    void printEnrolledCourses() {
        for (int i = 0; i < numOfCourses; ++i) {
            cout << "Course [" << i + 1 << "]" << endl;
            cout << "Code: " << enrolled_courses[i].getCourseCode() << endl;
            cout << "Name: " << enrolled_courses[i].getCourseName() << endl;
            cout << "Credit Hours: " << enrolled_courses[i].getCreditHours() << endl << endl;
        }
    }
};

int main() {
    Courses c1("CSCI101", "Introduction to Computer Science", 3);
    Courses c2("MATH201", "Calculus I", 4);

    Student s("S001", "John Doe");
    s.enroll(c1);
    s.enroll(c2);

    cout << "Total Credit Hours: " << s.getTotalCreditHours() << endl;
    s.printEnrolledCourses();

    s.drop(c1);
    cout << "Total Credit Hours after dropping a course: " << s.getTotalCreditHours() << endl;
    s.printEnrolledCourses();

    return 0;
}

