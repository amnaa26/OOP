#include <iostream>
#include <cmath>
#include <string>

using namespace std;
#define pi 3.14

class Shape{
public:
    virtual double Area() const = 0;
    virtual double Perimeter() const = 0;
    virtual void displayProperties() const = 0;

};

class Circle : public Shape{
private:
    double radius;
public:
    Circle(double radius) : radius(radius){}
    virtual double Area() const override{
        double area = pi * radius * radius;
        return area;
    }
    virtual double Perimeter() const override{
        double perimeter = 2 * pi * radius;
        return perimeter;
    }
    double diameter() const{
        double diameter = 2 * radius;
        return diameter;
    }
    virtual void displayProperties() const override{
        cout << "\n Properties of the Circle: " << endl;
        cout << " - Area : " << Area() << endl;
        cout << " - Perimeter : " << Perimeter() << endl;
        cout << " - Diameter : " << diameter() << endl;

    }
};

class Rectangle : public Shape{
private:
    double breadth, length;
public:
    Rectangle(double b, double l) : breadth(b), length(l){}
    double diagonal() const{
        double diagonal = sqrt ((length * length) + (breadth * breadth));
        return diagonal;
    }

    virtual double Area() const override{
        double area = length * breadth;
        return area;
    }
    virtual double Perimeter() const override{
        double perimeter = 2 * (length + breadth);
        return perimeter;
    }

    virtual void displayProperties() const override{
        cout << "\n Properties of the Rectangle: " << endl;
        cout << " - Area : " << Area() << endl;
        cout << " - Perimeter : " << Perimeter() << endl;
        cout << " - Diagonal : " << diagonal() << endl;

    }

};

class Square : public Shape{
private:
    double side;
public:
    Square(double s) : side(s){}
    double diagonal() const{
        double diagonal = side * (sqrt(2));
        return diagonal;
    }

    virtual double Area() const override{
        double area = side * side;
        return area;
    }
    virtual double Perimeter() const override{
        double perimeter = 4 * (side);
        return perimeter;
    }

    virtual void displayProperties() const override{
        cout << "\n Properties of the Square: " << endl;
        cout << " - Area : " << Area() << endl;
        cout << " - Perimeter : " << Perimeter() << endl;
        cout << " - Diagonal : " << diagonal() << endl;

    }
};

class Triangle : public Shape{
private:
    double base, perpendicular, hypo;
public:
    Triangle() = default;
    Triangle(double b, double p, double h) : base(b), perpendicular(p), hypo(h){}
    virtual double Area() const override{
        double area = 0.5 * hypo * base;
        return area;
    }
    virtual double Perimeter() const override{
        double perimeter = base + perpendicular + hypo;
        return perimeter;
    }

    virtual void displayProperties() const override{
        cout << "\n Properties of the Triangle: " << endl;
        cout << " - Area : " << Area() << endl;
        cout << " - Perimeter : " << Perimeter() << endl;

    }
};

class EquilateralTriangle : public Triangle {
private:
    double side;
public:
    EquilateralTriangle(double side) : side(side){}
    double Area() const override{
        double area = (sqrt(3) / 4) * side * side;
        return area;
    }
    double Perimeter() const override{
        double perimeter = 3 * side;
        return perimeter;
    }
    void displayProperties() const override{
        cout << "\n Properties of Equilateral Triangle: " << endl;
        cout << " - Area : " << Area() << endl;
        cout << " - Perimeter : " << Perimeter() << endl;
    }

};

void display() {
    cout << "Please select a shape: " << endl
         << "1. Circle " << endl
         << "2. Rectangle " << endl
         << "3. Square" << endl
         << "4. Triangle " << endl;
}

int main(){
    Shape* shapes;
    cout << "Creator: Amna(23k-0066)" << endl;
    cout << "\nWelcome to the Geometry Competition Calculator!" << endl << endl;

    int choice;
    string check = "yes";
    while (check == "yes"){
        display();
        cout << "Enter your choice: "; 
        cin >> choice;
        cout << endl;

        switch(choice){
            case 1: {
                double r;
                cout << "Enter the radius of the circle: ";
                cin >> r;

                shapes = new Circle(r);
                shapes->displayProperties();
                break;
            }

            case 2:{
                double length, width;
                cout << "Enter the length of the rectangle: ";
                cin >> length;
                cout << "Enter the width of the rectangle: ";
                cin >> width;

                shapes = new Rectangle(length, width);
                shapes->displayProperties();
                break;
            }

            case 3:{
                double side;
                cout << "Enter the side length of the square:";
                cin >> side;

                shapes = new Circle(side);
                shapes->displayProperties();
                break;
            }

            case 4:{
                double s1, s2, s3;
                cout << "Enter length of each side [3 sides]: " << endl;
                cin >> s1 >> s2 >> s3;

                if (s1 == s2 && s1 == s3 && s2 == s3)
                    shapes = new EquilateralTriangle(s1);
                else
                    shapes = new Triangle(s1, s2, s3);

                shapes->displayProperties();
                break;
            }

            break;
        }

        cout << "\nDo you want to calculate properties for another shape? (yes/no): ";
        cin >> check;
        cout << endl;
    }
}