/*
 * Creator: Amna(23k-0066)
 * Desc: Implement a restaurant ordering system that holds information about the restaurant’s menus, menu items, 
 orders, and payments. Identify the relationship between the five entities mentioned. 
 Keep in mind the following information as well:
a) Menu Items hold two things: food name and food price.
b) Menu is a class that holds an array of menu items. You can have different functionstoadd and remove items, 
   or display the entire menu.
c) Restaurant ordering system has one menu.
d) Any staff member can place an order to the system on behalf of a customer. Theorder class consists of one or 
    more menu items and a payment.
e) Payment is a class that holds the amount of money that a customer needs to pay.This is generated when the order 
   is placed.
*/


#include <iostream>
#include <string>
using namespace std;

class MenuItem {
    string foodName;
    double foodPrice;

public:
    MenuItem() {
    }
    MenuItem(string name, double price) : foodName(name), foodPrice(price) {}

    string getFoodName() const {
        return foodName;
    }

    double getFoodPrice() const {
        return foodPrice;
    }
};


class Menu {
    MenuItem items[10];
    int itemCount;

public:
    Menu() {
        itemCount = 0; // Initializing itemCount inside the constructor body
    }

    void addItem(MenuItem item) {
        if (itemCount < 10) {
            items[itemCount++] = item;
        } else {
            cout << "Menu is full!" << endl;
        }
    }

    void removeItem(int index) {
        if (index >= 0 && index < itemCount) {
            for (int i = index; i < itemCount - 1; ++i) {
                items[i] = items[i + 1];
            }
            --itemCount;
        } else {
            cout << "Invalid index!" << endl;
        }
    }

    void displayMenu() const {
        cout << "Menu Items:" << endl;
        for (int i = 0; i < itemCount; ++i) {
            cout << i+1 << ". " << items[i].getFoodName() << " - $" << items[i].getFoodPrice() << endl;
        }
    }
};

class Payment {
    double amount;

public:
    Payment(double _amount) : amount(_amount) {}

    double getAmount() const {
        return amount;
    }
};

class Order {
    MenuItem items[10];
    int itemCount;
    Payment payment;

public:
    Order(MenuItem _items[], int _itemCount, Payment _payment) : itemCount(_itemCount), payment(_payment) {
        for (int i = 0; i < itemCount; ++i) {
            items[i] = _items[i];
        }
    }

    void displayOrder() const {
        cout << "Order Details:" << endl;
        for (int i = 0; i < itemCount; ++i) {
            cout << i+1 << ". " << items[i].getFoodName() << " - $" << items[i].getFoodPrice() << endl;
        }
        cout << "Total Payment: $" << payment.getAmount() << endl;
    }
};

class RestaurantOrderingSystem {
    Menu menu;

public:
    void addMenuItem(MenuItem item) {
        menu.addItem(item);
    }

    void removeMenuItem(int index) {
        menu.removeItem(index);
    }

    void displayMenu() const {
        menu.displayMenu();
    }

    Order placeOrder(MenuItem items[], int itemCount, Payment payment) {
        return Order(items, itemCount, payment);
    }
};

int main() {
    MenuItem item1("Burger", 5.99);
    MenuItem item2("Pizza", 8.49);
    MenuItem item3("Salad", 4.99);
    Payment payment(20.47);
  
    RestaurantOrderingSystem system;
  
    system.addMenuItem(item1);
    system.addMenuItem(item2);
    system.addMenuItem(item3);

    cout << "------- Restaurant Menu -------" << endl;
    system.displayMenu();

    //Placing order
    MenuItem orderItems[] = {item1, item3};
    int itemCount = sizeof(orderItems) / sizeof(orderItems[0]);
    Order order = system.placeOrder(orderItems, itemCount, payment);

    // Displaying order details
    cout << endl << "------- Order Details -------" << endl;
    order.displayOrder();

    return 0;
}
