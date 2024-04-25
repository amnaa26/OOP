#include <iostream>
using namespace std;

class Shape{
private:
    double length, width;
public:
    Shape(double l, double w) : length(l), width(w) {}
    double Area(){
        return width*length;
    }

    double operator+(Shape& obj) {
        return this->Area() + obj.Area();
    }
};

int main(){
    cout << "\nCreator: Amna(23k-0066)" << endl << endl;
    Shape shape1(5.0, 4.0);
    Shape shape2(6.0, 8.0);
    cout << "Area of shape1: " << shape1.Area() << endl;
    cout << "Area of shape2: " << shape2.Area() << endl;
    cout << "Sum of areas: " << shape1 + shape2 << endl;
}