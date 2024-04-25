//Programmer: Amna(23k-0066)

#include <iostream>
using namespace std;

class Perimeter{
private:
    double length, breadth;
public:
    Perimeter(double l, double b) : length(l), breadth(b) {}
    friend class PrintClass;
    double calculatePerimeter();
};

class PrintClass{
public:
    void printPerimeter(Perimeter& perimeter);
};

double Perimeter :: calculatePerimeter(){
    return 2 * (length + breadth);
}

void PrintClass :: printPerimeter(Perimeter& perimeter){
    cout << "Perimeter: " << perimeter.calculatePerimeter() << endl;
}


int main(){
    cout << "Programmer: Amna(23k-0066)" << endl << endl;
    Perimeter perimeter(5, 4);
    PrintClass print;
    print.printPerimeter(perimeter);
}
