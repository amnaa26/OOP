/*
Programmer: Amna(23K-0066)
Question: Your assignment is to construct a basic product management system for an online store.
	  1. Develop a function that enables the addition of a new product to the system. The function should accept parameters such as product name, price, quantity, and any other relevant details.
	  2. Implement a function that takes a product ID as input and displays detailed information about the product, including its name, price, quantity in stock, and any other relevant details.
	  3. Design a function that allows the update of product information. It should accept a product ID and the new details (e.g., updated price, quantity, etc.) and modify the existing product’s information accordingly.
*/

#include <iostream>
#include <string>
using namespace std;

const int MAX_PRODUCTS = 100;


struct Product {
    int id;
    string name;
    double price;
    int quantity;
    string details; 
};

// array of structure
Product products[MAX_PRODUCTS];

// variable to keep track of the next available product ID
int nextProductId = 1;

// function of adding a new product
void addProduct() {
    if (nextProductId <= MAX_PRODUCTS) {
        Product product;
        product.id = nextProductId;
        cout << "Product ID: " << product.id << endl;
        cout << "Enter product name: ";
        getline(cin, product.name);
        cout << "Enter product price: $";
        cin >> product.price;
        cout << "Enter quantity in stock: ";
        cin >> product.quantity;
        cout << "Enter product details: ";
        cin.ignore(); // Clear input buffer
        getline(cin, product.details);
        products[nextProductId - 1] = product;
        cout << "Product added successfully!" << endl;
        nextProductId++;
    } else {
        cout << "Maximum number of products reached." << endl;
    }
}

// function of displaying product wrt product ID
void displayProduct(int productId) {
    if (productId >= 1 && productId <= nextProductId) {
        Product product = products[productId - 1];
        cout << "Product ID: " << product.id << endl;
        cout << "Name: " << product.name << endl;
        cout << "Price: $" << product.price << endl;
        cout << "Quantity in stock: " << product.quantity << endl;
        cout << "Details: " << product.details << endl;
    } else {
        cout << "Product with ID " << productId << " not found." << endl;
    }
}

// function to update product info
void updateProduct(int productId) {
    if (productId >= 1 && productId <= nextProductId) {
        Product& product = products[productId - 1];
        cout << "Enter new product name: ";
        getline(cin, product.name);
        cout << "Enter new product price: $";
        cin >> product.price;
        cout << "Enter new quantity in stock: ";
        cin >> product.quantity;
        cout << "Enter new product details: ";
        cin.ignore(); 
        getline(cin, product.details);
        cout << "Product information updated successfully!" << endl;
    } else {
        cout << "Product with ID " << productId << " not found." << endl;
    }
}

int main() {
    int choice;
    
    while (true) {
        cout << "\nMenu:\n1. Add new product\n2. Display product information\n3. Update product information\n4. Exit\n\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); 
        
        switch (choice) {
            case 1:
                addProduct();
                break;
            case 2:
                int productId;
                cout << "Enter product ID: ";
                cin >> productId;
                cin.ignore(); 
                displayProduct(productId);
                break;
            case 3:
                cout << "Enter product ID: ";
                cin >> productId;
                cin.ignore();
                updateProduct(productId);
                break;
            case 4:
                cout << "Exiting." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    
    return 0;
}


