#include<iostream>
using namespace std;

const double PI = 3.141592653589793;

class Shape{
public:
    double calculateArea(double radius){
        return PI * (radius * radius);
    }
    double calculateArea(double length, double width){
        return length * width;
    }
    double calculateArea(double base, float height){
        return 0.5 * (base * height);
    }

    double calculatePerimeter(double radius){
        return PI * 2 * radius;
    }
    double calculatePerimeter(double length, double width){
        return 2 * (length + width);
    }
    double calculatePerimeter(double base, double perpendicular, float height){
        return base + height + perpendicular;
    }
};


void display() {
    cout << "Please select a shape: " << endl
         << "1. Circle " << endl
         << "2. Square" << endl
         << "3. Triangle " << endl << endl
         << ">>";
}


int main(){
    cout << "\nCreator: Amna(23k-0066)" << endl << endl;
    Shape shapes;
    int choice;
    display();
    cin >> choice;

    switch (choice){
        case 1: {
            double r;
            cout << "\nEnter the radius of the circle: ";
            cin >> r;

            cout <<"\nCircle:" << endl;
            cout << "Area: " << shapes.calculateArea(r) << endl;
            cout << "Perimeter: " << shapes.calculatePerimeter(r) << endl;
            return 0;
        }

        case 2: {
            double length, width;
            cout << "\nEnter the length of the rectangle: ";
            cin >> length;
            cout << "Enter the width of the rectangle: ";
            cin >> width;

            cout << "\nRectangle:" << endl;
            cout << "Area: " << shapes.calculateArea(length, width) << endl;
            cout << "Perimeter: " << shapes.calculatePerimeter(length, width) << endl;
            return 0;
        }

        case 3: {
            double s1, s2;
            float s3;
            cout << "Enter length of each side [3 sides]: " << endl;
            cin >> s1 >> s2 >> s3;

            cout << "\nTriangle:" << endl;
            cout << "Area: " << shapes.calculateArea(s1, s3) << endl;
            cout << "Perimeter: " << shapes.calculatePerimeter(s1, s2, s3) << endl;
            return 0;
        }
    }

    return 0;
}