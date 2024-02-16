/*
 * Programmer : Amna(23k-0066)
 * Decs: Craft a class denominated "Calendar." This Calendar class should possess 12 arrays, each representing a month of the year, along with a 
 		 variable storing information about the current year. Users can allocate tasks for each day, with one entry allowed per day.
		 Incorporate the following methods within this class:
			• Addition of a task: This function accepts task details, date, and month as parameters and adds the task to the specified day.
			• Removal of a task: Accepts the date and month as parameters to eliminate the task.
			• Display tasks: This method traverses through all months and prints the allocated tasks.

		 Instantiate a calendar object, input 5-6 tasks manually, demonstrate task removal, and display the updated task list.
*/

#include <iostream>
#include <string>

using namespace std;

class Calendar {
private:
    int year;
    string tasks[12][30];

    void showTasks(int month) {
        cout << "Month " << month << ":" << endl;
        for (int i = 0; i < 30; ++i) {
            if (!tasks[month - 1][i].empty()) {
                cout << "\tDay " << i + 1 << ": " << tasks[month - 1][i] << endl;
            }
        }
    }

public:
    Calendar(int yr) : year(yr) {}

    void addTask(int date, int month, const string& task) {
        if (month >= 1 && month <= 12 && date >= 1 && date <= 30) {
            tasks[month - 1][date - 1] = task;
        }
    }

    void removeTask(int date, int month) {
        if (month >= 1 && month <= 12 && date >= 1 && date <= 30) {
            tasks[month - 1][date - 1] = "";
        }
    }

    void displayAllTasks() {
        cout << "Tasks for the year " << year << ":" << endl;
        for (int month = 1; month <= 12; ++month) {
            showTasks(month);
        }
    }
};

int main() {
    Calendar calendar(2024);

    calendar.addTask(6, 7, "Meetup with friends");
    calendar.addTask(15, 2, "Important tasks");
    calendar.addTask(10, 3, "Study for the finals");
    calendar.addTask(11, 3, "Exercise");
    calendar.removeTask(11, 3);
    calendar.addTask(11, 3, "Family day out");

    calendar.displayAllTasks();

    return 0;
}

