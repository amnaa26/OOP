#include <iostream>

using namespace std;

class Table {
private:
    const int defaultCapacity = 4;
    int capacity;
    int occupiedSeats;
    bool clean;

public:
    // Default constructor
    Table() : capacity(defaultCapacity), occupiedSeats(0), clean(true) {}

    // Parameterized constructor
    Table(int capacity) : occupiedSeats(0), clean(true) {
        if (capacity == 8 || capacity == 4) {
            this->capacity = capacity;
        } else {
            // Round to the closest capacity (4 or 8)
            this->capacity = (capacity <= 6) ? 4 : 8;
        }
    }

    // Getter for capacity (no setter as it should not be editable once set)
    int getCapacity() const {
        return capacity;
    }

    // Check if the table is clean
    bool isClean() const {
        return clean;
    }

    // Check if the table is fully occupied
    bool isFull() const {
        return occupiedSeats == capacity;
    }

    // Use the table by a group of friends
    bool useTable(int groupSize) {
        if (!clean || groupSize > capacity - occupiedSeats) {
            return false; // Table cannot be used
        }
        occupiedSeats += groupSize;
        return true;
    }

    // Have lunch on the table
    void haveLunch() {
        clean = false;
    }

    // Leave the table
    void leaveTable() {
        occupiedSeats = 0;
    }

    // Clean the table
    void cleanTable() {
        if (occupiedSeats == 0) {
            clean = true;
        }
    }
};

// Global function to occupy a table with a group of friends
void OccupyTable(Table tables[], int groupSize) {
    for (int i = 0; i < 5; ++i) {
        if (!tables[i].isFull()) {
            if (tables[i].useTable(groupSize)) {
                cout << "Group of " << groupSize << " has been assigned Table " << i + 1 << " with capacity " << tables[i].getCapacity() << endl;
                return;
            }
        }
    }
    cout << "No available table for a group of " << groupSize << endl;
}

// Global function to empty a table
void EmptyTable(Table tables[], int tableNumber) {
    tables[tableNumber].leaveTable();
}

int main() {
	cout << "Creator: Amna(23k-0066)" << endl << "FAST Dhaba" << endl << "--------Starting the Program--------" << endl;
    Table tables[5] = { Table(8), Table(8), Table(4), Table(4), Table(4) };

    OccupyTable(tables, 4); // Assign table to a group of 4
    OccupyTable(tables, 6); // Assign table to a group of 6

    // Actions for table 1
    tables[0].useTable(4) ? cout << "Table 1 is being used by a group of 4\n" : cout << "Table 1 is occupied or dirty\n";
    tables[0].haveLunch();
    tables[0].leaveTable();
    tables[0].cleanTable();

    // Empty table 2
    EmptyTable(tables, 1);

    return 0;
}
