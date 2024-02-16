/*
 * Creater : Amna(23k-0066)
 * Desc: Establish a class termed "WaterBottle." This class encompasses attributes like company (manufacturer), color, and water capacity. 
 		 The water capacity is recorded in both litres (l) and millilitres (ml). Define variables and methods for this class, incorporating 
		 getters and setters. Additionally, introduce a method to update the water capacity (both in litters and millilitres) after prompting
		 the user regarding the amount of water consumed, presuming the input is consistently in millilitres.
		 Exhibit the functionality of the water bottle within the main method.
*/


#include <iostream>
#include <string>

using namespace std;

class WaterBottle {
private:
    string company;
    string color;
    int capacityLiters;
    int capacityMilliliters;

public:
    // Default constructor
    WaterBottle() {
        company = "Unnamed";
        color = "Transparent";
        capacityLiters = 1;
        capacityMilliliters = 0;
    }

    // Getters and Setters
    string getCompany() { return company; }
    void setCompany(string comp) { company = comp; }

    string getColor() { return color; }
    void setColor(string col) { color = col; }

    int getCapacityLiters() { return capacityLiters; }
    void setCapacityLiters(int capLit) { capacityLiters = capLit; }

    int getCapacityMilliliters() { return capacityMilliliters; }
    void setCapacityMilliliters(int capMl) { capacityMilliliters = capMl; }

    // Method to update water capacity
    void updateWaterCapacity(int mlConsumed) {
        int totalMl = capacityMilliliters - mlConsumed;
        if (totalMl >= 0) {
            capacityLiters = totalMl / 1000;
            capacityMilliliters = totalMl % 1000;
            cout << "Water consumed. Updated capacity: " << capacityLiters << "L " << capacityMilliliters << "ml" << endl;
        } else {
            cout << "Error: Not enough water in the bottle." << endl;
        }
    }
};

int main() {
    WaterBottle bottle;

    // Input information
    cout << "Enter the company name: ";
    string comp;
    getline(cin, comp);
    bottle.setCompany(comp);

    cout << "Enter the color: ";
    string col;
    getline(cin, col);
    bottle.setColor(col);

    cout << "Enter the capacity in liters: ";
    int lit;
    cin >> lit;
    bottle.setCapacityLiters(lit);

    cout << "Enter the capacity in milliliters: ";
    int ml;
    cin >> ml;
    bottle.setCapacityMilliliters(ml);

    // Display information
    cout << "\nWater Bottle Information:" << endl;
    cout << "Company: " << bottle.getCompany() << endl;
    cout << "Color: " << bottle.getColor() << endl;
    cout << "Capacity: " << bottle.getCapacityLiters() << "L " << bottle.getCapacityMilliliters() << "ml" << endl;

    // Simulate consuming water
    int consumed;
    cout << "\nEnter the amount of water consumed in milliliters: ";
    cin >> consumed;
    bottle.updateWaterCapacity(consumed);

    return 0;
}

