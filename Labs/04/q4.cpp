/*
 * Programmer: Amna(23k - 0066)
 * Date: 15/02/2024
 * Desc: Instantiate a class named Office to represent attributes of an office space, including Location (default value: " "), 
         SeatingCapacity (default value: 0), and Furniture (a string array with a size of 3, default: {"", "", ""}). Implement 
		 a parameterized constructor assigning default values to all attributes using a member initialization list. Create multiple 
		 instances of the Office class using different numbers of constructor arguments.
*/

#include <iostream>
#include <string>
using namespace std;

class Office {
private:
    string Location;
    int SeatingCapacity;
    string Furniture[3];

public:
    Office(string loc = " ", int capacity = 0, string furniture1 = "", string furniture2 = "", string furniture3 = "") :
        Location(loc), SeatingCapacity(capacity) {
        Furniture[0] = furniture1;
        Furniture[1] = furniture2;
        Furniture[2] = furniture3;
    }


    void displayOffice() {
        cout << "Location: " << Location << endl;
        cout << "Seating Capacity: " << SeatingCapacity << endl;
        cout << "Furniture: " << Furniture[0] << ", " << Furniture[1] << ", " << Furniture[2] << endl;
    }
};

int main() {
    Office office1("Downtown", 50, "Desk", "Chair", "Bookshelf");
    Office office2("Suburb", 30, "Table", "Sofa");
    Office office3("City Center", 20);

 
    cout << "Office 1 details:" << endl;
    office1.displayOffice();
    cout << endl;

    cout << "Office 2 details:" << endl;
    office2.displayOffice();
    cout << endl;

    cout << "Office 3 details:" << endl;
    office3.displayOffice();
    cout << endl;

    return 0;
}

