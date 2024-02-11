/*

	Programmer: Amna(23K-0066)
	
Q3: Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
	You may assume that each input would have exactly one solution, and you may not use the same element twice.You can return the answer in any order.
*/


#include<iostream>
using namespace std;

int main(){
	int n, target, i, j, sum;
	cout << "Enter the size of array: " ;
	cin >> n;
	int array[n];
	
	cout << "Now, enter the elements: " ;
	for(i = 0; i < n; ++i){
		cin >> array[i];
	}
	
	cout << "\nEnter target: " ;
	cin >> target;
	
	for(i = 0; i < n; ++i){
		for(j = 0; j < n; ++j){
			sum = array[i] + array[j];
			if(sum == target){
				cout << "[" << i << ", " << j << "]" << endl;
				cout << "Because nums[" << i << "] + nums[" << j << "] == " << target << " , we return " << "[" << i << ", " << j << "]" << endl;
				return 0;
			}
		}
	}

}
