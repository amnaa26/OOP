/*
 * Creator: Amna(23k-0066)
 * Desc: Create a class called Square with the following attributes:
			• sideLength – float variable
			• area – float variable
			• allareas – static float variable
		 Create the following methods for your class:
			• Constructors (default and parameterized (only takes sideLength as input))
			• Function to calculate area, the calculated area should always be added to the all areas variable each time an area is calculated. (assume it’s called only once for each object)
			• Getters and Setters for all variables
		 In your main function create 3 Squares with different sideLength. Call the area method for each of those Square objects. 
		 After each time the area method is called, call that square’s getters for area and allareas to display the updated values.	
*/

#include <iostream>
using namespace std;

class Square {
    float sideLength;
    float area;
    static float allareas;

public:
    Square() {
        sideLength = 0.0;
        area = 0.0;
    }

    Square(float side) {
        sideLength = side;
        calculateArea();
    }

    // Methods
    void calculateArea() {
        area = sideLength * sideLength;
        allareas += area;
    }

    // Getters and Setters
    float getSideLength() {
        return sideLength;
    }

    void setSideLength(float side) {
        sideLength = side;
    }

    float getArea() {
        return area;
    }

    static float getAllAreas() {
        return allareas;
    }
};

float Square::allareas = 0.0;

int main() {
    Square square1(3.0);
    Square square2(5.0);
    Square square3(7.0);

    // Call the area method for each Square object
    square1.calculateArea();
    square2.calculateArea();
    square3.calculateArea();

    // Displaying the output
    cout << "Square 1 Area: " << square1.getArea() << ", All Areas: " << Square::getAllAreas() << endl;
    cout << "Square 2 Area: " << square2.getArea() << ", All Areas: " << Square::getAllAreas() << endl;
    cout << "Square 3 Area: " << square3.getArea() << ", All Areas: " << Square::getAllAreas() << endl;

    return 0;
}

