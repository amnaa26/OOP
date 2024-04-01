#include <iostream>
#include <string>
using namespace std;

class DarazPersonData{
private:
    string firstName, lastName, address, city, state, zip, phone;
public:
    //Mutators
    void setLastName(const string& ln) { lastName = ln; }
    void setFirstName(const string& fn) { firstName = fn; }
    void setAddress(const string& addr) { address = addr; }
    void setCity(const string& c) { city = c; }
    void setState(const string& s) { state = s; }
    void setZip(const string& z) { zip = z; }
    void setPhone(const string& ph) { phone = ph; }

    //Accessors
    string getLastName() const { return lastName; }
    string getFirstName() const { return firstName; }
    string getAddress() const { return address; }
    string getCity() const { return city; }
    string getState() const { return state; }
    string getZip() const { return zip; }
    string getPhone() const { return phone; }
};

class DarazCustomerData : public DarazPersonData{
public:
    int customerNumber;
    int loyaltyPoints;

    int getCustomerNumber() const { return customerNumber; }
    void setCustomerNumber(int num) { 
        if (num > 0) {
            customerNumber = num;
        } else {
            cout << "Invalid customer number!" << endl;
        }
    }

    int getLoyaltyPoints() const { return loyaltyPoints; }
    void setLoyaltyPoints(int points) { 
        if (points >= 0) {
            loyaltyPoints = points;
        } else {
            cout << "Invalid loyalty points!" << endl;
        }
    }
};

class DarazLoyaltyProgram {
public:
  static void addLoyaltyPoints(DarazCustomerData &customer, int points, string product) {
        if (points > 0) {
            customer.setLoyaltyPoints(customer.getLoyaltyPoints() + points);
            cout << points << " loyalty points added successfully for purchasing " << product << "!" << endl;
        } else {
            cout << "Invalid loyalty points!" << endl;
        }
    }

    static void redeemLoyaltyPoints(DarazCustomerData &customer, int pointsToRedeem, string product) {
        if (pointsToRedeem > 0 && pointsToRedeem <= customer.getLoyaltyPoints()) {
            customer.setLoyaltyPoints(customer.getLoyaltyPoints() - pointsToRedeem);
            cout << pointsToRedeem << " loyalty points redeemed successfully for " << product << "!" << endl;
        } else {
            cout << "Invalid loyalty points to redeem!" << endl;
        }
    }

    static void displayTotalLoyaltyPoints(const DarazCustomerData &customer) {
        cout << "Total loyalty points for Customer " << customer.getCustomerNumber() << ": " << customer.getLoyaltyPoints() << endl;
    }
};

int main() {
    cout << "\nCreator: Amna (23k-0066)" << endl << "Task: Daraz Loyalty Program System" << endl;
    cout << "Starting the program....\n\n" ;
    DarazCustomerData customer;
    customer.setCustomerNumber(101);
    customer.setFirstName("John");
    customer.setLastName("Doe");
    customer.setAddress("123 Main St");
    customer.setCity("New York");
    customer.setState("NY");
    customer.setZip("10001");
    customer.setPhone("123-456-7890");
    customer.setCustomerNumber(101);
    cout << "Customer Number: " << customer.getCustomerNumber() << endl;
    cout << "First Name: " << customer.getFirstName() << endl;
    cout << "Last Name: " << customer.getLastName() << endl;
    cout << "Address: " << customer.getAddress() << endl;
    cout << "City: " << customer.getCity() << endl;
    cout << "State: " << customer.getState() << endl;
    cout << "Zip: " << customer.getZip() << endl;
    cout << "Phone: " << customer.getPhone() << endl;

    customer.setLoyaltyPoints(0);
    cout << "Loyalty Points: " << customer.getLoyaltyPoints() << endl;
    cout << endl;
    DarazLoyaltyProgram::addLoyaltyPoints(customer, 50, "Laptop");
    DarazLoyaltyProgram::displayTotalLoyaltyPoints(customer);
    cout << endl;
    DarazLoyaltyProgram::redeemLoyaltyPoints(customer, 30, "Smartphone");
    //cout << "\nDisplaying total loyalty points after redemption" << endl;
    DarazLoyaltyProgram::displayTotalLoyaltyPoints(customer);

} 

