#include <iostream>
using namespace std;

class Vehicle{
protected:
    string make, model;
    int speed;

public:
     Vehicle(string model, string make, int speed) : make(make), model(model), speed(speed) {}
    virtual void accelerate() = 0;
    virtual void brake() = 0;
    virtual void calculateFuelEfficiency() = 0;

    string getMake() const { return this->make; }
    string getModel() const { return this->model; }
    int getSpeed() const { return this->speed; }
};


class Car : public Vehicle{
private:
    double fuelCapacity;

public:
    Car(string model, string make, int speed, double fuelCapacity) : Vehicle(model, make, speed), fuelCapacity(fuelCapacity) {}
    void accelerate() override { this->speed += 10; }

    void brake() override { 
        if(speed == 0) speed = 0;
        else this-> speed -= 5; 
    }

    void calculateFuelEfficiency() override {
        cout << "Fuel efficiency of the car is calculated based on its fuel capacity." << endl;
    }
};


class Truck : public Vehicle {
private:
    int cargoCapacity;

public:
    Truck(string model, string make, int speed, double cargoCapacity) : Vehicle(model, make, speed), cargoCapacity(cargoCapacity) {}
    void accelerate() override{
        this -> speed += 5;
    }

    void brake() override {
        this->speed -= 3; // Trucks have a longer braking distance
        if (speed < 0) {
            speed = 0; 
        }
    }

    void calculateFuelEfficiency() override {
        cout << "Fuel efficiency of the truck is calculated based on its cargo capacity." << endl;
    }

};

int main() {
    cout << "\nCreator: Amna(23k-0066)" << endl << endl;
    Car car("Toyota", "Camry", 60, 50.0);
    Truck truck("Ford", "F150", 50, 5000);

    car.accelerate();
    truck.accelerate();

    cout << "Car Speed: " << car.getSpeed() << endl;
    cout << "Truck Speed: " << truck.getSpeed() << endl;

    car.brake();
    truck.brake();

    cout << "Car Speed after braking: " << car.getSpeed() << endl;
    cout << "Truck Speed after braking: " << truck.getSpeed() << endl;

    car.calculateFuelEfficiency();
    truck.calculateFuelEfficiency();
}
