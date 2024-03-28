#include <iostream>
#include <string>
using namespace std;

class SecurityTool {
public:
    double Cost;
    string SecurityLevel;
    int NumberOfDevices;

    SecurityTool(string securityLevel, double cost, int numberOfDevices) {
        NumberOfDevices = numberOfDevices;

        while (securityLevel != "High" && securityLevel != "Medium" && securityLevel != "Low") {
            cout << "\nInvalid security level!\nEnter again: ";
            cin >> securityLevel;
        }
        SecurityLevel = securityLevel;

        while (cost <= 0) {
            cout << "Invalid cost entered!\nEnter again: ";
            cin >> cost;
        }
        Cost = cost;
    }

    virtual void performScan() {
        cout << "\nPerforming a generic security scan...";
    }

    string getSecurityLevel() { return SecurityLevel; }
    double getCost() { return Cost; }
    int getNumOfDevices() { return NumberOfDevices; }
};

class FireWallTool : public SecurityTool {
public:
    int ports[24];
    string protocols[6];

    FireWallTool(string securityLevel, double cost, int numberOfDevices, string studentID)
        : SecurityTool(securityLevel, cost, min(numberOfDevices, 10)) {

        int startPort = (stoi(studentID) % 10) + 1;
        for (int i = 0; i < 23; ++i) {
            ports[i] = startPort + i;
        }

        protocols[0] = "HTTPS";
        protocols[1] = "FTP";
        protocols[2] = "UDP";
        protocols[3] = "ICMP";
        protocols[4] = "SSH";
        protocols[5] = "SNMP";
    }

    void generateList() {
        cout << "\nAllowed Ports:" << endl;
        for (int i = 0; i < 23; ++i) {
            cout << ports[i] << " ";
        }

        cout << "\n\nAllowed Protocols: " << endl;
        for (int i = 0; i < 6; ++i) {
            cout << protocols[i] << " ";
        }

        cout << endl;
    }

    void performScan() override {
        if (SecurityLevel == "High") {
            cout << "\nScanning with high security level...." << endl;
            generateList();
        }
        else if (SecurityLevel == "Medium") {
            cout << "\nScanning with medium security level...." << endl;
            generateList();
            cout << "Additional Ports: " << ports[22] + 1 << " " << ports[22] + 2 << endl;
        }
        else if (SecurityLevel == "Low") {
            cout << "\nScanning with low security level...." << endl;
            generateList();
            cout << "Additional Ports: " << ports[22] + 1 << " " << ports[22] + 2 << " " 
                 << ports[22] + 3 << " " << ports[22] + 4 << " " << ports[22] + 5 << endl;
            cout << "Additional Protocols: \nTCP DNS" << endl;
        }
    }
};

int main() {
    cout << "Creator: Amna(23k-0066)" << endl;
    cout << "Program: Security System" << endl;
    cout << "Starting the program...." << endl << endl;
    double cost;
    int num;
    string studentID, level;
    
    cout << "Enter student ID: ";
    getline(cin, studentID);
    
    cout << "\nEnter security level (High/Medium/Low): ";
    cin >> level;
    cin.ignore();
    
    cout << "\nEnter cost: ";
    cin >> cost;
    cin.ignore();
    
    cout << "\nEnter number of devices: ";
    cin >> num;
    cin.ignore();

    FireWallTool firewall(level, cost, num, studentID);

    cout << "\nSecurity Level: " << firewall.getSecurityLevel() << endl;
    cout << "Cost: " << firewall.getCost() << endl;
    cout << "Number of Devices: " << firewall.getNumOfDevices() << endl;

    firewall.performScan();

    return 0;
}
