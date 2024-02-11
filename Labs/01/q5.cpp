/*
Programmer: Amna(23K-0066)
Q5: Design Event Management System in C++ to facilitate the organization of events. The program should empower the user to seamlessly manage event details, including the 
    event name, date, venue, and organizer. Incorporate key features such as the ability to add events, display comprehensive details of all events, and perform event 
    searches based on specific dates. To enhance flexibility and scalability, leverage dynamic memory allocation for storing event details.
	1. Prompt the user to input the total number of events they wish to manage.
	2. Dynamically allocate memory to store event details for the specified number of events.
	3. For each event, prompt the user to input:
		• Event Name
		• Date
		• Venue
		• Organizer
	4. Display all events that match the provided date, including their complete details.
	5. Allow the user to search for events based on a specific date.
	
*/


#include <iostream>
#include <cstring>
using namespace std;

struct Event {
    char eventName[100];
    char date[20];
    char venue[100];
    char organizer[100];
};

int main() {
    int totalEvents;

    // Taking total number of events from user
    cout << "Enter the total number of events you wish to manage: ";
    cin >> totalEvents;
    

    // Dynamically allocating memory
    Event* events = new Event[totalEvents];
    

    // Taking details of each event from user 
    for (int i = 0; i < totalEvents; ++i) {
        cout << "\nEnter details for Event " << i + 1 << ":\n";

        cout << "Event Name: ";
        cin.ignore();  // Ignore newline character left in the buffer
        cin.getline(events[i].eventName, sizeof(events[i].eventName));

        cout << "Date: ";
        cin.getline(events[i].date, sizeof(events[i].date));

        cout << "Venue: ";
        cin.getline(events[i].venue, sizeof(events[i].venue));

        cout << "Organizer: ";
        cin.getline(events[i].organizer, sizeof(events[i].organizer));
    }

    // Displaying the events having on the same date as the user entered
    char searchDate[20];
    cout << "\nEnter date to display matching events: ";
    cin >> searchDate;

    cout << "\nEvents on " << searchDate << ":\n";
    for (int i = 0; i < totalEvents; ++i) {
        if (strcmp(events[i].date, searchDate) == 0) {
            cout << "\nEvent Name: " << events[i].eventName << endl;
            cout << "Date: " << events[i].date << endl;
            cout << "Venue: " << events[i].venue << endl;
            cout << "Organizer: " << events[i].organizer << endl;
        }
    }

    
    // Deallocate memory
    delete[] events;

    return 0;
}
