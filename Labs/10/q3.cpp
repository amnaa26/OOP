#include <iostream>
using namespace std;

class Shape{
private:
    double length, width;
public:
    Shape(double l, double w) : length(l), width(w) {}
    double Area(){
        return length*width;
    }

    Shape operator+(const Shape& obj) const{
        double totalWidth = this->width + obj.width;
        double totalLength = this->length + obj.length;
        return Shape(totalWidth, totalLength);
    }
};

int main(){
    cout << "\nCreator: Amna(23k-0066)" << endl << endl;
    Shape shape1(10.0, 14.2);
    Shape shape2(5, 5);
    Shape sumShape = shape1 + shape2;
    cout << "Area of shape1: " << shape1.Area() << endl;
    cout << "Area of shape2: " << shape2.Area() << endl;
    cout << "Sum of areas: " << sumShape.Area() << endl;
}