/*
 	* Creator: Amna(23k-0066)
	*Desc: Virtual Pet Adoption System
*/

#include <iostream>
#include <vector>
#include <algorithm> // for std:: find
#include <ctime> // for srand
#include <cstdlib> // for rand

using namespace std;

const string health[4] = { "Very Healthy", "Healthy", "Sick", "Very Sick" };

class Pet {
public:
    string healthStatus;
    string name;
    int hungerLevel, happinessLevel;
    vector<string> specialSkills;

    void displayPetDetails() const {
        cout << "Name: " << name << endl;
        cout << "Health-Status: " << healthStatus << endl;
        cout << "Hunger: " << hungerLevel << endl;
        cout << "Happiness: " << happinessLevel << endl;
        cout << "Skills:" << endl;
        for (const string& skill : specialSkills) cout << skill << ", ";
    }

    void updateHunger(int hunger) {
        hungerLevel = hunger;
        if (hunger >= 50)
            happinessLevel += rand()%10 + 1; // generate random int between 1-10
        else
            happinessLevel -= rand()%10 + 1;
    }

    void updateHappiness(int happiness) {
        happinessLevel = happiness;
    }

    void updateHealth(string health) {
        healthStatus = health;
    }
};

class Adopter {
public:
    string adopterName, adopterMobileNum;
    vector<Pet> adoptedPetRecords;

    Adopter(string name, string num) : adopterName(name), adopterMobileNum(num) {}

    void adoptPet(Pet &pet) {
        adoptedPetRecords.push_back(pet);
    }

    void returnPet(string name) {
        auto it = remove_if(adoptedPetRecords.begin(), adoptedPetRecords.end(), [&name](const Pet& pet) {
            return pet.name == name;
        });
        if (it != adoptedPetRecords.end()) {
            adoptedPetRecords.erase(it, adoptedPetRecords.end());
            cout << "Pet returned successfully." << endl;
        } else {
            cout << "Pet not found in adopted pets." << endl;
        }
    }

    void displayAdoptedPets() const {
        if (adoptedPetRecords.empty()) {
            cout << "No pets adopted yet." << endl;
            return;
        }
        cout << "Adopted Pets by " << adopterName << ":" << endl;
        for (const Pet& pet : adoptedPetRecords) {
            pet.displayPetDetails();
            cout << endl;
        }
    }
};

void menu(const string& name) {
    cout << "Welcome " << name << "!" << endl
         << "Virtual Pet Adoption System" << endl
         << "\t1. Add pet" << endl
         << "\t2. Show all pets" << endl
         << "\t3. Adopt pet" << endl
         << "\t4. Show adopted pets" << endl
         << "\t5. Interact with pet" << endl
         << "\t6. Return pet" << endl
         << "\t7. Exit" << endl;
}

Pet addPet() {
    Pet pet;
    cout << "Enter pet name: ";
    getline(cin, pet.name);
    cout << "Select skills (enter 0 to exit)\n";
    while (true) {
        string skill;
        cout << "Enter skill: ";
        getline(cin, skill);
        if (skill == "0") break;
        pet.specialSkills.push_back(skill);
    }
    pet.healthStatus = "Healthy";
    pet.happinessLevel = 60;
    pet.hungerLevel = 60;
    return pet;
}

void showAllPets(const vector<Pet>& list) {
    for (const Pet& pet : list) {
        pet.displayPetDetails();
        cout << endl;
    }
}

void adoptPet(Adopter &adopter, vector<Pet> &list) {
    string name;
    cout << "Enter pet name: ";
    getline(cin, name);
    auto it = find_if(list.begin(), list.end(), [&name](const Pet& pet) { return pet.name == name; });
    if (it != list.end()) {
        adopter.adoptPet(*it);
        list.erase(it);
        cout << "Pet adopted" << endl;
    } else {
        cout << "Pet not found" << endl;
    }
}

void returnPet(Adopter &adopter) {
    string name;
    cout << "Enter pet name: ";
    getline(cin, name);
    adopter.returnPet(name);
}

void interact(Pet& pet) {
    int choice;
    cout << "Select pet interaction:\n";
    cout << "1. Make pet happy/unhappy\n";
    cout << "2. Feed pet/Make pet hungry\n";
    cout << "Enter your choice: ";
    cin >> choice;

    if (choice == 1) {
        int happiness;
        cout << "Enter happiness value: ";
        cin >> happiness;
        pet.updateHappiness(happiness);
    } else if (choice == 2) {
        int hunger;
        cout << "Enter hunger value: ";
        cin >> hunger;
        pet.updateHunger(hunger);
    } else {
        cout << "Invalid choice" << endl;
    }
}


void interactWithPet(Adopter &adopter) {
    string name;
    cout << "Enter pet name to interact with: ";
    getline(cin, name);

    auto it = find_if(adopter.adoptedPetRecords.begin(), adopter.adoptedPetRecords.end(), [&name](const Pet& pet) {
        return pet.name == name;
    });

    if (it != adopter.adoptedPetRecords.end()) {
        interact(*it);
    } else {
        cout << "Pet not found" << endl;
    }
}

int main() {
	cout << "Creator: Amna(23k-0066)" << endl << "Program: Virtual Pet Adoption System" << endl << "-----Starting the Program-----" << endl;
    srand(time(0));
    vector<Pet> petsList;

    char name[100];
    cout << "Enter name: ";
    cin.getline(name, sizeof(name));

    char num[100];
    cout << "Enter phone number: ";
    cin.getline(num, sizeof(num));

    Adopter adopter(name, num);

    bool flag = true;
    while (flag) {
        menu(adopter.adopterName);
        int choice;
        cin >> choice;

        cin.ignore();
        switch (choice) {
        case 1: // add pet to pets list
            petsList.push_back(addPet());
            break;
        case 2: // show all pets in the list
            showAllPets(petsList);
            break;
        case 3: // add pet to adopted list and remove from pets list
            adoptPet(adopter, petsList);
            break;
        case 4:
            adopter.displayAdoptedPets(); // show all pets in adopted pets list
            break;
        case 5:
            interactWithPet(adopter); // interact with adopted pets
            break;
        case 6:
            returnPet(adopter); // remove pet from adopted list and add back to pets list
            break;
        case 7:
            flag = false;
            break;
        default:
            cout << "Incorrect option" << endl;
        }
    }

    return 0;
}

