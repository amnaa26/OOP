#include<iostream>
#include <string>
using namespace std;

class Vehicle{
public:
    string make, model; int year;
    Vehicle(string make, string model, int year) : make(make), model(model), year(year){}
};

class Car : public Vehicle{
public:
    int numberOfDoors; float fuelEfficiency;
    Car(string make, string model, int year, int doors, float efficiency) : Vehicle(make, model, year), numberOfDoors(doors), fuelEfficiency(efficiency) {}
};

class ElectricCar : public Car{
public:
    double batteryLife;
    ElectricCar(string make, string model, int year, int doors, float efficiency, double battery) : Car(make, model, year, doors, efficiency), batteryLife(battery) {}
    void display() {
        cout << "Make: " << make << "\n";
        cout << "Model: " << model << "\n";
        cout << "Year: " << year << "\n";
        cout << "Doors: " << numberOfDoors << "\n";
        cout << "Fuel Efficiency: " << fuelEfficiency << " mpg" << endl;
        cout << "Battery Life: " << batteryLife << " kWh" << endl;
    }
};

int main(){
    ElectricCar electricCar("Tesla", "Model S", 2022, 4, 100.0, 75.0);
    electricCar.display();
}