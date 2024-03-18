/*
 * Programmer: Amna(23k-0066)
 * Desc: Develop a hair salon program to track appointments, earnings, and average cost per appointment using static members and functions.
		 - Define a class for appointments with private data for appointment details and static data to track total appointments and earnings.
		 - Constructor: Update static data based on appointment details.
		 - Public Member Functions: Allow access to appointment details.
		 - Static Function: Calculate and return the average cost of all appointments using static data.
		 - Main Function: Create appointment instances, call the static function to calculate average cost, and verify program functionality.
*/

#include <iostream>
#include <string>
using namespace std;

class HairSalon{
	string name;
	int time;
	double cost;
	
public:
	static int appointment;
	static double total;
	
	HairSalon(string customer_name, int time, double cost){
		name = customer_name;
		this -> time = time;
		this -> cost = cost;
		
		HairSalon::total += cost;
		HairSalon::appointment++ ; 
	}
	
	double getCost(){
		return cost;
	}
	
	int getTime(){
		return time;
	}
	
	string getName(){
		return name;
	}
	
	static double AverageCost(){
		return total/appointment;
	}
};

	double HairSalon::total = 0.f;
	int HairSalon::appointment = 0;


int main(){
	HairSalon first("Alice", 7, 270);
	cout << "--------Appointments Details--------" << endl;
	cout << "\nName: " << first.getName() << "\nTime: " << first.getTime() << " PM" << "\nCost: $ " << first.getCost() << endl;
	
	HairSalon second("Talha", 2, 2500);
	cout << "\nName: " << second.getName() << "\nTime: " << second.getTime() << " PM" << "\nCost: $ " << second.getCost() << endl;
	
	HairSalon third("Fariha", 3, 3650);
	cout << "\nName: " << third.getName() << "\nTime: " << third.getTime() << " PM" << "\nCost: $ " << third.getCost() << endl;
	
	HairSalon fourth("John", 9, 1540);
	cout << "\nName: " << fourth.getName() << "\nTime: " << fourth.getTime() << " PM" << "\nCost: $ " << fourth.getCost() << endl;
	
	double averageCost = HairSalon :: AverageCost();
	cout << "\nAverage Cost Per Appointment: $ " << averageCost << endl;
}


