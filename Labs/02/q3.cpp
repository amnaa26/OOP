/*
	Programmer: Amna(23K-0066)
	Question: You’re given an integer array and a target sum. Your job is to write a recursive function in C++ that checks if 
			  there’s a subset of the array whose elements sum up to the target sum. 
			  • Develop a recursive function named hasSubsetSum that accepts an integer array, the array’s size, and a target 
			  	sum as input and returns a boolean indicating whether a subset with the specified sum exists. 
			  • The function should have the following signature:
				bool hasSubsetSum(int arr[], int size, int targetSum).
*/

#include <iostream>
using namespace std;

//Recursive function finding the target sum
bool hasSubsetSum(int arr[], int size, int targetSum) {
    if (targetSum == 0)
        return true;
    if (size == 0 || targetSum < 0)
        return false;

    return hasSubsetSum(arr, size - 1, targetSum - arr[size - 1]) ||
           hasSubsetSum(arr, size - 1, targetSum);
}

int main() {
	int n, i;
	cout << "Enter your desired size for an array: ";
	cin >> n;
	cout << endl;
	
	//Taking array as an input from the user
	int arr[n];
	for(i = 0; i < n; ++i){
		cout << "Enter element " << i + 1 << ": ";
		cin >> arr[i];
	}
	
	cout << endl;
    int size = sizeof(arr) / sizeof(arr[0]);
    int targetSum ;
    cout << "Enter your target: ";
    cin >> targetSum;

	//Finding subset
	cout << "\nOuput: " <<endl ;
    if (hasSubsetSum(arr, size, targetSum))
        cout << "Subset with sum " << targetSum << " exists in the array." << endl;
    else
        cout << "Subset with sum " << targetSum << " does not exist in the array." << endl;

    return 0;
}

