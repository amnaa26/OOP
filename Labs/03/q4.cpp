/*
 * Programmer : Amna(23k-0066)
 * Decs: Forge a class labelled "Smartphone" possessing the following attributes:
			• Brand
			• Model
			• Display Resolution
			• RAM
			• ROM
			• Storage
			
		 Develop getter and setter methods for these attributes. Additionally, define specific actions smartphones can perform, such as:
			• Making phone calls
			• Sending messages
			• Connecting to Wi-Fi
			• Browsing the internet
			
		 Create distinct smartphone objects, set their attributes using setter functions, and exhibit their attributes after retrieving them using getter functions.
*/


#include <iostream>
#include <string>

using namespace std;

class Smartphone {
private:
    string brand;
    string model;
    string displayResolution;
    int ram;
    int rom;
    int storage;

public:
    Smartphone() {}

    // Getter and setter methods
    void setBrand(const string& b) {
        brand = b;
    }

    string getBrand() const {
        return brand;
    }

    void setModel(const string& m) {
        model = m;
    }

    string getModel() const {
        return model;
    }

    void setDisplayResolution(const string& res) {
        displayResolution = res;
    }

    string getDisplayResolution() const {
        return displayResolution;
    }

    void setRAM(int r) {
        ram = r;
    }

    int getRAM() const {
        return ram;
    }

    void setROM(int r) {
        rom = r;
    }

    int getROM() const {
        return rom;
    }

    void setStorage(int s) {
        storage = s;
    }

    int getStorage() const {
        return storage;
    }

    // Specific actions
    void makePhoneCall(const string& number) {
        cout << "Making a phone call to " << number << " using " << brand << " " << model << endl;
    }

    void sendMessage(const string& recipient, const string& message) {
        cout << "Sending message to " << recipient << ": " << message << endl;
    }

    void connectToWiFi(const string& networkName) {
        cout << "Connecting to Wi-Fi network: " << networkName << endl;
    }

    void browseInternet() {
        cout << "Browsing the internet using " << brand << " " << model << endl;
    }
};

int main() {
    Smartphone phone1;
    phone1.setBrand("Samsung");
    phone1.setModel("Galaxy S21");
    phone1.setDisplayResolution("2400 x 1080");
    phone1.setRAM(8);
    phone1.setROM(128);
    phone1.setStorage(256);

    Smartphone phone2;
    phone2.setBrand("Apple");
    phone2.setModel("iPhone 13");
    phone2.setDisplayResolution("2532 x 1170");
    phone2.setRAM(6);
    phone2.setROM(256);
    phone2.setStorage(256);

    cout << "Smartphone 1 attributes:" << endl;
    cout << "Brand: " << phone1.getBrand() << endl;
    cout << "Model: " << phone1.getModel() << endl;
    cout << "Display Resolution: " << phone1.getDisplayResolution() << endl;
    cout << "RAM: " << phone1.getRAM() << "GB" << endl;
    cout << "ROM: " << phone1.getROM() << "GB" << endl;
    cout << "Storage: " << phone1.getStorage() << "GB" << endl;

    cout << endl;

    cout << "Smartphone 2 attributes:" << endl;
    cout << "Brand: " << phone2.getBrand() << endl;
    cout << "Model: " << phone2.getModel() << endl;
    cout << "Display Resolution: " << phone2.getDisplayResolution() << endl;
    cout << "RAM: " << phone2.getRAM() << "GB" << endl;
    cout << "ROM: " << phone2.getROM() << "GB" << endl;
    cout << "Storage: " << phone2.getStorage() << "GB" << endl;

    cout << endl;

    // Specific actions
    cout << "Smartphone 1 specific actions:" << endl;
    phone1.makePhoneCall("123456789");
    phone1.sendMessage("John", "Hello, how are you?");
    phone1.connectToWiFi("MyHomeWiFi");
    phone1.browseInternet();

    cout << endl;

    cout << "Smartphone 2 specific actions:" << endl;
    phone2.makePhoneCall("987654321");
    phone2.sendMessage("Alice", "Hi there!");
    phone2.connectToWiFi("PublicWiFi");
    phone2.browseInternet();

    return 0;
}


