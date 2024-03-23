#include <iostream>
#include <string>
using namespace std;

class Person{
 public:
    string name;
    int age;
    Person(string name, int age){
        this -> name = name;
        this -> age = age;
    }
};

class Student : public Person{
public:
    string studentID;
    int gradeLevel;
    Student(string id, int level, string name, int age): Person(name, age){
        studentID = id;
        gradeLevel = level;
    }
};

class Teacher : public Person{
public:
    int roomnumber;
    string subject;
    Teacher(int no, string course, string name, int age): Person(name, age){
        roomnumber = no;
        subject = course;
        name = "talha";
    }
};

class GraduateStudent : public Student, public Teacher{
public:
    GraduateStudent(string name, int age, string id, int level, string course, int no): Student(id, level, name, age), Teacher(no, course, name, age){
       
    }
   
    void display(){
        cout << "Name: " << Student :: name << endl;
        cout << "Age: " << Student :: age << endl;
        cout << "Student ID: " << studentID << endl;
        cout << "Grade level: " << gradeLevel << endl;
        cout << "Room number: " << roomnumber << endl;
        cout << "Subject: " << subject << endl;
       
    }
};

int main(){
   GraduateStudent object("Alice", 22, "5678", 10, "Computer Science", 201);
   object.display();
}
