//Creator: Amna(23k-0066)

#include <iostream>
using namespace std;

class operatorOverloading{
private:
    int x;
public:
    operatorOverloading(int x) : x(x) {}

    //Prefix decrement operator --x
    operatorOverloading& operator--(){
        x *= 4;
        return *this;
    }

    //Postfix decrement operator x--
    operatorOverloading& operator--(int){
        operatorOverloading temp = *this;
        x /= 4;
        return *this;
    }

    int getValue(){
        return x;
    }
};

int main(){
    cout << "\nProgrammer: Amna(23k-0066)" << endl << endl;
    operatorOverloading obj(4);
    cout << "Initial Value: " << obj.getValue();
    
    //Prefix
    --obj;
    cout << "\nAfter prefix decrement: " << obj.getValue() << endl;

    //Postfix
    obj--;
    cout << "After postfix decrement: " << obj.getValue() << endl;
}