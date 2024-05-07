#include <iostream>
using namespace std;

#define L_TO_G 0.264172

class convert{
protected:
    double val1, val2;

public:
    convert(double v1) : val1(v1) {}
    virtual double compute() = 0;
};


class l_to_g : public convert{
public:
    l_to_g(double val) : convert(val){}
    double compute() override{
        val2 = val1 * L_TO_G;
        return val2;
    }
};


class f_to_c : public convert{
public:
    f_to_c(double val) : convert(val) {}
    double compute() override{
        val2 = (val1 - 32) * 5 / 9; 
        return val2;
    }
};


int main(){
    cout << "\nCreator: Amna(23K-0066)" << endl << endl;
    convert *lg = new l_to_g(4);
    convert *fc = new f_to_c(70);

    cout << "4 liter to gallon is: " << lg->compute() << endl;
    cout << "70 Fahrenheit to Celsius is: " << fc->compute() << endl;
}