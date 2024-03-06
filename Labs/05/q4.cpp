/*
 * Creator: Amna(23k-0066)
 * Desc: Create a BankAccount class. Which contains following details and functionalties:
		 Attributes: The BankAccount class has three private member variables: accountNumber, accountHolderName, and balance.
		 Create Constructor: The class has a constructor that takes parameters to initialize the account details (accountNumber, accountHolderName, and balance).
		 Create following Member Functions:
				• deposit(double amount): Adds the specified amount to the account balance.
				• withdraw(double amount): Subtracts the specified amount from the account balance, if sufficient funds are available.
				• display(): Displays the account details including the account number, account holder name, and balance.

		 In the main() function, create an array accounts of BankAccount objects. The array contains three elements, each representing a different bank account.
		 Initialize Each BankAccount object with specific account details such as account number, holder name, and initial balance.
		 Perform following operations:
				• Iterate through each account in the accounts array.
				• For each account, display the account details using the display() function.
				• Perform Two Transactions:
				• Deposits 500.0 rupees into the account.
				• Withdraws 200.0 rupees from the account.
				• After each transaction, display the updated account details, including the new balance.
*/

#include <iostream>
using namespace std;

class BankAccount{
	string accountNumber;
	string accountHolderName;
	double balance;

public:
	BankAccount(string accountNumber, string accountHolderName, double balance){
	this -> accountNumber = accountNumber;
	this -> accountHolderName = accountHolderName;
	this -> balance = balance;
  }

	void deposit(double amount){
		double temp = balance;
		balance += amount;
		if(balance > temp) cout << "Deposit successful! Current Balance is: " << balance << endl;
		else cout << "Deposit unsuccessful!" << endl;
  }

	void withdraw(double amount){
		if(amount > balance) cout << "Withdraw unsuccessful! Unsufficient amount of balance! Current balance is: " << balance << endl;
		else{
			balance -= amount;
			cout << "Withdraw successful! Current balance is: " << balance << endl;
		}
	}

	void display(){
		cout << "Account Number: " << accountNumber << "\nAccount Holder Name: " << accountHolderName << "\nBalance: " << balance << endl;
	}
};

int main(){
	int i;
    BankAccount myBank[3] = {
        BankAccount("12378", "Ahmed", 123456),
        BankAccount("43567", "Sara", 456789),
        BankAccount("26789", "Ghareeb", 0)
    };

    cout << "-------Displaying Accounts Details--------" << endl;
    for (i = 0; i < 3; ++i) {
        cout << "Account " << i + 1 << endl;
        myBank[i].display();
    }

    double withdrawAmount, depositAmount;
    cout << "Enter deposit money for Account 2: ";
    cin >> depositAmount;
    myBank[1].deposit(depositAmount);

    cout << "Enter withdrawal money for Account 3: ";
    cin >> withdrawAmount;
    myBank[2].withdraw(withdrawAmount);
}


