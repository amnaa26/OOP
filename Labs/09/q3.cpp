#include <iostream>
using namespace std;

class Employee{
private:
    string employeeID, employeeName;
public:
    Employee(string id, string name) : employeeID(id), employeeName(name) {}

    //Methods
    virtual double calculatePay() const = 0;
    virtual void displayDetails() const {
        cout << "\nEmployee ID: " << employeeID;
        cout << "\nName: " << employeeName;
    }
};

class FullTimeEmployee : public Employee{
private:
    double salary;
public:
    FullTimeEmployee(double money, string id, string name) : Employee(id, name), salary(money) {}
    double calculatePay() const {
        return salary;
    }
    void displayDetails() const {
        Employee :: displayDetails();
        cout << "\nType: Full-Time " ;
        cout << "\nMonthly Salary: " << salary << endl;
    }

};

class PartTimeEmployee : public Employee{
private:
    double hourlyWage, numberOfHours;
public:
    PartTimeEmployee(double wage, double hours, string id, string name) : Employee(id, name), hourlyWage(wage), numberOfHours(hours) {}
    double calculatePay() const {
        return hourlyWage * numberOfHours;
    }
    void displayDetails() const {
        Employee :: displayDetails();
        cout << "\nType: Part-Time";
        cout << "\nHourly Wage: " << hourlyWage;
        cout << "\nHours Worked: " << numberOfHours << endl;
    }
};


int main(){
    cout << "\nCreator: Amna(23k-0066)" << endl << endl;
    FullTimeEmployee fullTimeEmp(5000, "101", "AAA");
    PartTimeEmployee partTimeEmp(15, 40, "102", "BBB");

    //Using instances of classes
    cout << "Details of Employees: ";
    fullTimeEmp.displayDetails();
    partTimeEmp.displayDetails();
    cout << "\nCalculating Pay: " << endl;
    cout << "Full-time Employee Pay: $" << fullTimeEmp.calculatePay() << endl;
    cout << "Part-time Employee Pay: $" << partTimeEmp.calculatePay() << endl;

    //Using base-class pointer
    Employee* emp;
    emp = &fullTimeEmp;
    cout << "\nUsing base class pointer to display Full Time Employee Details:" ;
    emp->displayDetails();
    cout << "Pay: $" << emp->calculatePay() << endl << endl;

    emp = &partTimeEmp;
    cout << "Using base class pointer to display Part Time Employee Details:" ;
    emp->displayDetails();
    cout << "Pay: $" << emp->calculatePay() << endl << endl;

}