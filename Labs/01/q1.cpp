/*
	Programmer: Amna(23K-0066)
	
	Q1. Write a C++ program to check whether a given number is prime or not. Allow the user to input a number and display whether it's prime or not?
*/

#include<iostream>
using namespace std;

int main(){
	int num;
	cout << "Enter a number: " << endl;
	cin >> num;
	if(num == 1 || num == 0){
		cout << "Not a prime number"<<endl;
		return 0;
	}
    int mul = num - 1;
    while(mul > 1){
        if(num % mul == 0){
            cout << "Not a prime number" << endl;
            return 0;
        }
        --mul;
    }
    
    cout << "It is a prime number";

}
