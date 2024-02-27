#include <iostream>
#include <string>

using namespace std;

class RollerCoaster {
private:
    string name;
    unsigned height;
    unsigned length;
    unsigned speed;
    unsigned capacity;
    unsigned currentNumRiders;
    bool rideInProgress;

public:
    // Default Constructor
    RollerCoaster() : name("Roller Coaster"), height(500), length(2000), capacity(20), speed(0), currentNumRiders(0), rideInProgress(false) {}

    // Parameterized Constructor
    RollerCoaster(string name, unsigned height, unsigned length, unsigned capacity) :
        name(name), height(height), length(length), capacity(capacity), speed(0), currentNumRiders(0), rideInProgress(false) {
        adjustCapacity();
    }

    // Getter and Setter functions
    string getName() const { return name; }
    void setName(string name) { this->name = name; }

    unsigned getHeight() const { return height; }
    void setHeight(unsigned height) { this->height = height; }

    unsigned getLength() const { return length; }
    void setLength(unsigned length) { this->length = length; }

    unsigned getSpeed() const { return speed; }
    void setSpeed(unsigned speed) { this->speed = speed; }

    unsigned getCapacity() const { return capacity; }
    void setCapacity(unsigned capacity) {
        this->capacity = capacity;
        adjustCapacity();
    }

    unsigned getCurrentNumRiders() const { return currentNumRiders; }
    void setCurrentNumRiders(unsigned currentNumRiders) { this->currentNumRiders = currentNumRiders; }

    bool isRideInProgress() const { return rideInProgress; }
    void setRideInProgress(bool rideInProgress) { this->rideInProgress = rideInProgress; }

    // Function to load/seat riders into the roller coaster
    unsigned seatRiders(unsigned riders) {
        if (rideInProgress) {
            cout << "Ride in progress. Riders cannot be seated." << endl;
            return riders;
        }

        unsigned availableSeats = capacity - currentNumRiders;
        if (riders <= availableSeats) {
            currentNumRiders += riders;
            return 0;
        } else {
            currentNumRiders = capacity;
            return riders - availableSeats;
        }
    }

    // Function to start the ride
    int start() {
    if (rideInProgress) {
        cout << "Ride is already in progress." << endl;
        return -1;
    }

    if (currentNumRiders != capacity) {
        return capacity - currentNumRiders;
    } else {
        rideInProgress = true;
        currentNumRiders = capacity; // Update to reflect all seats are occupied
        cout << "Ride started! Total " << currentNumRiders << " riders seated." << endl;
        return 0;
    }
}


    // Function to stop the ride
    void stop() {
        if (rideInProgress) {
            rideInProgress = false;
            cout << "Ride stopped." << endl;
        } else {
            cout << "Ride is not in progress." << endl;
        }
    }

    // Function to unload riders from the roller coaster
    void unloadRiders() {
        if (rideInProgress) {
            cout << "Cannot unload riders while ride is in progress." << endl;
        } else {
            currentNumRiders = 0;
            cout << "Riders unloaded." << endl;
        }
    }

    // Function to accelerate the roller coaster
    void accelerate() {
        speed += 4; // Last non-zero digit of roll number
        cout << "Roller coaster accelerated. Current speed: " << speed << endl;
    }

    // Function to apply brakes to slow down the roller coaster
    void applyBrakes() {
        speed -= 2; // First non-zero digit of roll number
        if (speed < 0)
            speed = 0;
        cout << "Roller coaster slowed down. Current speed: " << speed << endl;
    }

private:
    // Adjust capacity to be a multiple of 2 or 3 and greater than 3
    void adjustCapacity() {
        if (capacity < 3)
            capacity = 3;
        else if (capacity % 2 != 0 && capacity % 3 != 0) {
            unsigned remainder2 = capacity % 2;
            unsigned remainder3 = capacity % 3;
            capacity += (remainder2 < remainder3) ? (2 - remainder2) : (3 - remainder3);
        }
    }
};

int main() {
	cout << "Creator: Amna(23k-0066)" << endl << "Program: Roller Coaster System" << endl << "--------Starting the Program--------" << endl;
    int numberOfRiders = 30;
    RollerCoaster rc1; // Default constructor
    RollerCoaster rc2("Thrill Max", 700, 1500, 27); // Parameterized constructor

    cout << "Roller Coaster 1 Name: " << rc1.getName() << endl;
    cout << "Roller Coaster 1 Height: " << rc1.getHeight() << endl;
    cout << "Roller Coaster 1 Length: " << rc1.getLength() << endl;
    cout << "Roller Coaster 1 Capacity: " << rc1.getCapacity() << endl << endl;

    cout << "Roller Coaster 2 Name: " << rc2.getName() << endl;
    cout << "Roller Coaster 2 Height: " << rc2.getHeight() << endl;
    cout << "Roller Coaster 2 Length: " << rc2.getLength() << endl;
    cout << "Roller Coaster 2 Capacity: " << rc2.getCapacity() << endl << endl;

    // Demonstrate other functionalities
    cout << "Details about Thrill Max" << endl;
    cout << "Number of riders wanting to take ride: " << numberOfRiders << endl;
    unsigned notSeated = rc2.seatRiders(numberOfRiders);
    if (notSeated > 0) {
        cout << "Total " << (numberOfRiders - notSeated) << " riders seated." << endl;
        cout << "Unable to seat " << notSeated << " riders due to insufficient space." << endl;
    } else {
        cout << "Total " << numberOfRiders << " riders seated." << endl;
    }
    int emptySeats = rc2.start();
    if (emptySeats > 0) {
        cout << "Ride started with " << (rc2.getCapacity() - emptySeats) << " riders." << endl;
        cout << "Remaining empty seats: " << rc2.start() << endl;
    } else if (emptySeats == 0) {
        cout << "Ride started with full capacity." << endl;
    }
    rc2.accelerate();
    rc2.applyBrakes();
    rc2.stop();
    rc2.unloadRiders();
    

    return 0;
}

