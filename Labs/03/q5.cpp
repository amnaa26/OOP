/*
 * Programmer : Amna(23k-0066)
 * Decs: Construct a class for a stationary shop. This class maintains lists for all items it sells (hint: an array of strings) and their corresponding
		 prices (hint: an array of prices). Design a menu-driven program to:
			• Enable the shop owner to add items and their prices.
			• Retrieve the list of items.
			• Modify the prices of items.
			• Display all items along with their prices.
		 Generate a receipt that the shopkeeper can share with customers. This receipt can only be generated after the shopkeeper inputs 
		 the items and their quantities bought by the customer.
*/

#include <iostream>
#include <string>

using namespace std;

class StationaryShop {
private:
    static const int MAX_ITEMS = 100;
    string items[MAX_ITEMS];
    double prices[MAX_ITEMS];
    int itemCount;

public:
    StationaryShop() : itemCount(0) {}

    void addItem(const string& itemName, double price) {
        if (itemCount < MAX_ITEMS) {
            items[itemCount] = itemName;
            prices[itemCount] = price;
            itemCount++;
            cout << "Item added successfully!" << endl;
        } else {
            cout << "Failed to add item. Shop is full." << endl;
        }
    }

    void displayItems() const {
        cout << "Items available in the shop:" << endl;
        for (int i = 0; i < itemCount; ++i) {
            cout << i + 1 << ". " << items[i] << " - $" << prices[i] << endl;
        }
    }

    void modifyPrice(const string& itemName, double newPrice) {
        for (int i = 0; i < itemCount; ++i) {
            if (items[i] == itemName) {
                prices[i] = newPrice;
                cout << "Price of " << itemName << " modified successfully!" << endl;
                return;
            }
        }
        cout << "Item not found." << endl;
    }

    void generateReceipt(const string& customerName, const string items[], const int quantities[], int itemCount) const {
        double totalAmount = 0;
        cout << "\nReceipt for " << customerName << ":" << endl;
        cout << "-----------------------------------------" << endl;
        for (int i = 0; i < itemCount; ++i) {
            double itemPrice = 0;
            for (int j = 0; j < itemCount; ++j) {
                if (this->items[j] == items[i]) {
                    itemPrice = prices[j];
                    break;
                }
            }
            cout << items[i] << " x " << quantities[i] << " - $" << itemPrice * quantities[i] << endl;
            totalAmount += itemPrice * quantities[i];
        }
        cout << "-----------------------------------------" << endl;
        cout << "Total: $" << totalAmount << endl;
    }
};

int main() {
    StationaryShop shop;

    int choice;
    string itemName;
    double price;
    string customerName;
    const int MAX_ITEMS = 100;
    string items[MAX_ITEMS];
    int quantities[MAX_ITEMS];
    int itemCount;

    do {
        cout << "\nStationary Shop Menu:" << endl;
        cout << "\t1. Add item" << endl;
        cout << "\t2. Display items" << endl;
        cout << "\t3. Modify price" << endl;
        cout << "\t4. Generate receipt" << endl;
        cout << "\t5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter item name: ";
                cin >> itemName;
                cout << "Enter price: ";
                cin >> price;
                shop.addItem(itemName, price);
                break;
            case 2:
                shop.displayItems();
                break;
            case 3:
                cout << "Enter item name: ";
                cin >> itemName;
                cout << "Enter new price: ";
                cin >> price;
                shop.modifyPrice(itemName, price);
                break;
            case 4:
                cout << "Enter customer name: ";
                cin >> customerName;
                cout << "Enter number of items bought: ";
                cin >> itemCount;
                for (int i = 0; i < itemCount; ++i) {
                    cout << "Enter item " << i + 1 << " name: ";
                    cin >> items[i];
                    cout << "Enter quantity: ";
                    cin >> quantities[i];
                }
                shop.generateReceipt(customerName, items, quantities, itemCount);
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

