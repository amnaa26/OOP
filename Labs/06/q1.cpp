/*
 * Programmer: Amna(23k-0066)
 * Desc: Create a BankAccount class managing individual accounts. Each object includes an accountId, balance, and transactionHistory (a pointer to an array). Key functions include a constructor to initialize accounts, a copy constructor, a destructor to manage memory, a display function, and an updateTransactionHistory function to modify transaction records.
		 In the main function:

		-Create a BankAccount object with initial details and history.
		-Copy the original account.
		-Display both accounts.
		-Update the original account's transaction history.
		-Display changes in the original account's history.
*/

#include <iostream>
using namespace std;

class BankAccount{
	int accountId;
	double balance;
	int* transactionHistory;
	int numTransactions;
	
public:
	//Parametrized constructor
	BankAccount(int accountId, double balance, int*transactions, int numTransactions){
		this -> accountId = accountId;
		this -> balance = balance;
		this -> numTransactions = numTransactions;
		int i;
		transactionHistory = new int [numTransactions];
		for(i = 0; i < numTransactions; ++i){
			transactionHistory[i] = transactions[i];
		}
	}
	
	//Copy constructor
	BankAccount(const BankAccount& copy){
		accountId = copy.accountId;
		balance = copy.balance;
		numTransactions = copy.numTransactions;
		transactionHistory = new int [numTransactions];
		int i;
		for(i = 0; i < numTransactions; ++i){
			transactionHistory[i] =copy.transactionHistory[i];
		}
	}
	
	//Destructor
	~BankAccount(){
		delete[] transactionHistory;
	}
	
	void display(){
		int i;
		cout << "Account ID: " << accountId << endl;
		cout << "Balance: " << balance << endl;
		cout << "Number of transactions: " << numTransactions << endl;
		for(i = 0; i < numTransactions; ++i){
			cout << "Transaction [" << i + 1 << "]: " << transactionHistory[i] << endl;
		}
	}
	
	void updateTransactionHistory(int* transaction, int num){
		delete[] transactionHistory;
		transactionHistory = new int [num];
		int i;
		for(i = 0; i < num; ++i){
			transactionHistory[i] = transaction[i];
		}	
	}
};


int main(){
	int transactions[4] = {2, 3, 4, 5};
	BankAccount object(1, 23000.f, transactions, 4);
	BankAccount copy(object);
	
	cout << "Printing the original account details: " << endl;
	object.display();
	cout << "\nPrinting the copied account details: " << endl;
	copy.display();
	
	transactions[3] = 7;
	object.updateTransactionHistory(transactions, 4);
	cout << "\nPrinting the changed original account details: " << endl;
	object.display();
	cout << "\nPrinting the changed copied account details: " << endl;
	copy.display();
	
}
