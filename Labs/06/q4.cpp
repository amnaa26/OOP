/*
 * Programmer: Amna(23k-0066)
 * Desc: Create a program to calculate a cricket player's batting average and strike rate.
		 Input: Total runs scored and total balls faced.
		 Output: Batting average and strike rate.
		 Formula: Batting average = Total runs scored / Number of times dismissed, Strike rate = (Total runs scored / Total balls faced) * 100.
		 Implement inline functions for these calculations.
*/

#include <iostream>
using namespace std;

inline double calculateBattingAverage(int score, int out){
	if(out == 0) return 0
	else return score/out;
}

inline double calculateStrikeRate(int score, int balls){
	return score/balls * 100;
}

int main(){
	int runs, balls, out;
	cout << "Enter total number of scores: ";
	cin >> runs;
	cout << "Enter total number of balls: ";
	cin >> balls;
	cout << "Enter total number of out: ";
	cin >> out;
	
	double battingAverage = calculateBattingAverage(runs, out);
	double strikeRate = calculateStrikeRate(runs, balls);
	
	cout <<"\n\nBatting Average: " << battingAverage << endl;
	cout <<"Strike Rate: " << strikeRate << endl;
}
