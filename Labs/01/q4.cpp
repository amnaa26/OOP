/*
Programmer: Amna(23K-0066)
Q4: You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
    Find two lines that together with the x-axis form a container, such that the container contains the most water. Return the maximum amount of water a container can store. 
    Notice that you may not slant the container.
*/


#include <iostream>
using namespace std;

int maxArea(int array[], int n) {
    int maxWater = 0;
    int i, j;

    for (i = 0; i < n; ++i) {
        for (j = i + 1; j < n; ++j) {
            int height = min(array[i], array[j]);
            int width = j - i;
            int area = height * width;

            maxWater = max(maxWater, area);
        }
    }

    return maxWater;
}

int main() {
	int n, i;
	cout << "Enter the size of array: ";
	cin >> n;

	//Taking heights as inputs
	int array[n];
	for(i = 0; i < n; ++i){
		cout << "Enter element " << i + 1 << ": " ;
		cin >> array[i];
	}
	
	//solving the problem
	int result = maxArea(array, n);
	cout << "Maximum amount of water that the container can store: " << result << endl;
	
}
