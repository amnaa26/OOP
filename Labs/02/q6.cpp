/*
	Programmer: Amna(23K-0066)
	Question: You are asked to write a C++ program that calculates the Least Common Multiple (LCM) and Greatest Common Divisor (GCD) of two numbers.
			  Implement two separate recursive functions, calculateLCM and calculateGCD, each handling the corresponding task.
*/

#include <iostream>
using namespace std;

//functin to calculate GCD
int calculateGCD(int a, int b) {
    if (b == 0)
        return a;
    return calculateGCD(b, a % b);
}

//function to calculate LCM
int calculateLCM(int a, int b) {
    return (a * b) / calculateGCD(a, b);
}

int main() {
    int num1, num2;
    
    cout << "Enter two numbers " <<endl;
    cout << "Enter x: "; cin >> num1;
    cout << "Enter y: "; cin >> num2;
    
    cout << "GCD of " << num1 << " and " << num2 << " is: " << calculateGCD(num1, num2) << endl;
    cout << "LCM of " << num1 << " and " << num2 << " is: " << calculateLCM(num1, num2) << endl;
    
    return 0;
}

