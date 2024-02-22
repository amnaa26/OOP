/*
 * Programmer: Amna(23k - 0066)
 * Date: 15/02/2024
 * Desc: Transform the Office class by replacing the furniture array with a pointer. Modify the constructor to accept the size of the furniture array 
         instead of the array itself, dynamically allocating memory for the furniture array within the constructor. Implement a destructor to deallocate 
		 memory allocated for the furniture pointer. In the main function, dynamically allocate an Office object, pass required values to the constructor, 
		 and then delete the dynamically allocated object to ensure proper invocation of the destructor.
*/

#include <iostream>
#include <string>
using namespace std;

class Office {
private:
    string Location;
    int SeatingCapacity;
    string* Furniture; 

public:
    // Parameterized constructor
    Office(string loc = " ", int capacity = 0, int furnitureSize = 3) :
        Location(loc), SeatingCapacity(capacity) {
        Furniture = new string[furnitureSize];
    }

    // Destructor
    ~Office() {
        delete[] Furniture;
        cout << "Furniture deleted!" << endl;
    }

    void setFurniture(int index, string item) {
        Furniture[index] = item;
    }

    void displayOffice() {
        cout << "Location: " << Location << endl;
        cout << "Seating Capacity: " << SeatingCapacity << endl;
        cout << "Furniture: ";
        for (int i = 0; i < 3; ++i) {
            cout << Furniture[i] << ", ";
        }
        cout << endl;
    }
};

int main() {
    Office* office = new Office("Downtown", 50);
    office->setFurniture(0, "Desk");
    office->setFurniture(1, "Chair");
    office->setFurniture(2, "Bookshelf");
    cout << "Office details:" << endl;
    office->displayOffice();

    // Deallocate dynamically allocated object
    delete office;

    return 0;
} 
