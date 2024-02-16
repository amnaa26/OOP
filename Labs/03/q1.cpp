#include <iostream>
using namespace std;

class BoardMarker{
	//data members
	string brand;
	string shade;
	bool refillable;
	bool ink_status;
	
	//method
	public:
	void setBrand(string brand_name){
		brand = brand_name;
	}
	string getBrand(){
		return brand;
	}
	
	void setShade(string shade_colour){
		shade = shade_colour;
	}
	string getShade(){
		return shade;
	}
	
	void setRefillable(bool refill){
		refillable = refill;
	}
	bool getRefillable(){
		return refillable;
	}
	
	void setInk(bool ink){
		ink_status = ink;
	}
	bool getInk(){
		return ink_status;
	}
	
};


int main(){
	BoardMarker marker;
	
	string brandname;
	cout<< "Enter the brand name of marker: ";
	getline(cin, brandname);
	string shade;
	cout << "\nEnter the shade of marker: ";
	getline(cin, shade);
	bool refill;
	cout << "\nIs the marker refillable?";
	cin >> refill;
	bool inkStatus;
	cout << "\nIs ink has run out?";
	cin >> inkStatus;
	
	marker.setBrand(brandname);
	marker.setShade(shade);
	marker.setRefillable(refill);
	marker.setInk(inkStatus);
	
	cout <<endl;
	cout << marker.getBrand() << endl;
	cout << marker.getShade() << endl;
	cout << marker.getRefillable() << endl;
	cout << marker.getInk() << endl;
}
