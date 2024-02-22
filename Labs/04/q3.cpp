/*
 * Programmer: Amna(23k - 0066)
 * Date: 15/02/2024
 * Desc: Develop a class called WeekDays containing private data members - a string array named Days for the days of the week and an integer variable 
         named CurrentDay for the current day. Create the following constructors and member functions for the class: a Default Constructor initializing
         the Days array from Sunday to Saturday, a Parameterized Constructor accepting an integer value for CurrentDay, performing a modulus operation 
		 to adjust if the value exceeds 6, and initializing the Days array accordingly. Additional member functions include getCurrentDay, getNextDay,
         getPreviousDay, and getNthDayFromToday.
*/

#include <iostream>
#include <string>
using namespace std;

class WeekDays {
private:
    string Days[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};;
    int CurrentDay;

public:
	//Default Constructor
    WeekDays() {
    	
    	/*We cannot initialize a list of string array in a constructor rather we would have to initalize eah separately 
		 for example: Days[0] = "Sunday"
		 Initializing like this will consume alot of time so I initailized the array while declaring it.
		 */
    	
        CurrentDay = 0; 
    }

    // Parameterized constructor
    WeekDays(int day) {
        CurrentDay = day % 7; // Adjust if value exceeds 6
    }

    string getCurrentDay() {
        return Days[CurrentDay];
    }

    string getNextDay() {
        return Days[(CurrentDay + 1) % 7];
    }

    string getPreviousDay() {
        return Days[(CurrentDay + 6) % 7];
    }

    string getNthDayFromToday(int n) {
        return Days[(CurrentDay + n) % 7];
    }
};

int main() {
    WeekDays week;
    cout << "Current Day: " << week.getCurrentDay() << endl;
    cout << "Next Day: " << week.getNextDay() << endl;
    cout << "Previous Day: " << week.getPreviousDay() << endl;
    int n;
    cout << "Enter the value of n to get nth day from today: ";
    cin >> n;
    cout << "Nth Day from Today: " << week.getNthDayFromToday(n) << endl;

    return 0;
}

