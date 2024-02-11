/*
	Programmer: Amna(23K-0066)
	Question: Your assignment is to develop a C++ function that interchanges the values of two variables.
			  Construct a recursive function called recursiveSwap that accepts two variables as arguments and swaps their values recursively.
*/


#include <iostream>
using namespace std;

void recursiveSwap(int* a, int* b) {
    if (a == b || *a == *b) {
        return; // If the variables are the same, or their values are the same, no swapping is needed
    }

    // Swap the values of a and b recursively
    int temp = *a;
    *a = *b;
    *b = temp;

    // Recursively call the function with incremented a and decremented b
    recursiveSwap(a + 1, b - 1);
}

int main() {
    int x, y;
    cout << "Enter value of x: ";
    cin >> x;
    cout << "Enter value of y: ";
    cin >> y;
    cout << endl;
    
    cout << "Before swapping: x = " << x << ", y = " << y << endl;
    
    recursiveSwap(&x, &y);
    cout << "After swapping: x = " << x << ", y = " << y << endl;
    return 0;
}
