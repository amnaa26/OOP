/*
 * Programmer : Amna(23k-0066)
 * Desc : Develop a class named "BoardMarker" possessing the subsequent characteristics:
		• Brand (such as Dollar, etc.)
		• Shade (black, red, etc.)
		• Refillable (Boolean - indicating whether it can be refilled or not)
		• Ink Status (Boolean - indicating if the ink is depleted or not)
  
	 Formulate appropriate getter and setter methods for the attributes of this class. Additionally, implement the following methods:
		• A writing method with a check to verify if the ink has run out. This method should exhibit an appropriate message based on the ink status.
		• A refill method for the board marker. This method should first confirm if the marker is refillable or not and then display a relevant message.

	 Illustrate the class functionality by creating an object, setting the values, and then invoking the methods.
*/

#include <iostream>
#include <string>

using namespace std;

class BoardMarker {
   //data members
    string brand;
    string shade;
    bool refillable;
    bool inkStatus;

public:
    // Setter
    void setBrand(string brand) {
        brand = brand;
    }
    void setShade(string shade) {
        shade = shade;
    }
    void setRefillable(bool refillable) {
        this->refillable = refillable;
    }
    void setInkStatus(bool inkStatus) {
        this->inkStatus = inkStatus;
    }

    // Getter 
    string getBrand() {
        return brand;
    }
    string getShade() {
        return shade;
    }
    bool isRefillable() {
        return refillable;
    }
    bool isInkEmpty() {
        return !inkStatus;
    }

    // Writing function
    void write() {
        if (isInkEmpty()) {
            cout << "Cannot write. Marker is out of ink." << endl;
        } else {
            cout << "Writing with " << brand << " board marker in " << shade << " shade." << endl;
        }
    }

    // Refill function
    void refill() {
        if (!isInkEmpty()) {
            cout << "Ink is not empty. No need to refill." << endl;
        } else {
            if (isRefillable()) {
                cout << "Refilling " << brand << " board marker." << endl;
                inkStatus = true; // Refilled the ink
            } else {
                cout << "Cannot refill. Marker is not refillable." << endl;
            }
        }
    }
};

int main() {
    BoardMarker marker;
    string brand, shade;
    int refillable; 
    bool inkStatus;

    cout << "Enter the brand of the board marker: ";
    getline(cin, brand);
    cout << "Enter the shade of the board marker: ";
    getline(cin, shade);
    cout << "Is the marker refillable? (1 for Yes, 0 for No): ";
    cin >> refillable;
    cout << "Is the ink status empty? (1 for Yes, 0 for No): ";
    cin >> inkStatus;

    marker.setBrand(brand);
    marker.setShade(shade);
    marker.setRefillable(static_cast<bool>(refillable)); 
    marker.setInkStatus(!inkStatus); 

    marker.write();
    marker.refill();

    return 0;
}

