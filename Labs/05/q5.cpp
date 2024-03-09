/*
 * Creator: Amna(23k-0066)
 * Desc: Keeping in mind our previous car example, write a class that represents a car, and use aggregation and composition to combine different components like engine, wheels,
         headlights and steering to create the car object.

		      Hint: create the individual classes first before performing the composition. Remember that for aggregation, you will need pointers! You’ll be needing
		      constructors and setters to set these values in case of aggregation. Same hint applies to other questions.
*/


#include <iostream>
#include <string>
using namespace std;

class Engine {
    string type;

public:
    Engine(string _type) : type(_type) {}

    void setType(string _type) {
        type = _type;
    }

    string getType() const {
        return type;
    }
};

class Wheel {
private:
    int size;

public:
    Wheel(int _size) : size(_size) {}

    void setSize(int _size) {
        size = _size;
    }

    int getSize() const {
        return size;
    }
};

class Headlight {
private:
    string brand;

public:
    Headlight(string _brand) : brand(_brand) {}

    void setBrand(string _brand) {
        brand = _brand;
    }

    string getBrand() const {
        return brand;
    }
};

class Steering {
private:
    string type;

public:
    Steering(string _type) : type(_type) {}

    void setType(string _type) {
        type = _type;
    }

    string getType() const {
        return type;
    }
};

class Car {
private:
    Engine* engine;
    Wheel* wheels[4];
    Headlight* headlights[2];
    Steering* steering;

public:
    Car(Engine* _engine, Wheel* _wheels[], Headlight* _headlights[], Steering* _steering) : engine(_engine), steering(_steering) {
        for (int i = 0; i < 4; ++i) {
            wheels[i] = _wheels[i];
        }
        for (int i = 0; i < 2; ++i) {
            headlights[i] = _headlights[i];
        }
    }

    ~Car() {
        delete engine;
        for (int i = 0; i < 4; ++i) {
            delete wheels[i];
        }
        for (int i = 0; i < 2; ++i) {
            delete headlights[i];
        }
        delete steering;
    }

    void display() {
        cout << "Car Details:" << endl;
        cout << "Engine Type: " << engine->getType() << endl;
        cout << "Wheel Sizes: ";
        for (int i = 0; i < 4; ++i) {
            cout << wheels[i]->getSize() << " ";
        }
        cout << endl;
        cout << "Headlight Brands: ";
        for (int i = 0; i < 2; ++i) {
            cout << headlights[i]->getBrand() << " ";
        }
        cout << endl;
        cout << "Steering Type: " << steering->getType() << endl;
    }
};

int main() {
    Engine* engine = new Engine("V8");
    Wheel* wheels[4] = {new Wheel(18), new Wheel(18), new Wheel(18), new Wheel(18)};
    Headlight* headlights[2] = {new Headlight("Philips"), new Headlight("Osram")};
    Steering* steering = new Steering("Power");

    Car myCar(engine, wheels, headlights, steering);
    myCar.display();

    return 0;
}

