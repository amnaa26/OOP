#include <iostream>
using namespace std;

class Account{
protected:
    int account_number;
    double balance;

public:
    Account(int accNum, double bal) : account_number(accNum), balance(bal) {}
    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void calculateInterest() = 0;
    int getAccountNumber() const { return account_number; }
    double getBalance() const { return balance; }
};


class SavingsAccount : public Account{
private:
    double interestRate;

public:
    SavingsAccount(int accNum, double bal, double rate) : Account(accNum, bal), interestRate(rate) {}
    void deposit(double amount) override{
        balance += amount;
    }

    void withdraw(double amount) override{
        if(balance - amount > 0) balance -= amount;
        else cout << "Insufficient funds!!" << endl;
    }

    void calculateInterest() override{
        balance += balance * interestRate / 100;
    }
};


class CurrentAccount : public Account{
private:
    double overdraftLimit;

public:
    CurrentAccount(int accNum, double bal, double limit) : Account(accNum, bal), overdraftLimit(limit) {}
    void deposit(double amount) override {
        balance += amount;
    }


    void withdraw(double amount) override {
        if (balance - amount >= -overdraftLimit)
            balance -= amount;
        else
            cout << "Withdrawal exceeds overdraft limit!" << endl;
    }
    

    void calculateInterest() override {
        // Current accounts typically don't earn interest
        std::cout << "No interest is calculated for current accounts." << std::endl;
    }
};


int main() {
    cout << "\nCreator: Amna(23k-0066)" << endl << endl;
    SavingsAccount savings(12345, 1000, 5.0);
    CurrentAccount current(54321, 2000, 1000);

    savings.deposit(500);
    savings.withdraw(200);
    savings.calculateInterest();

    current.deposit(1000);
    current.withdraw(3000);

    cout << "Savings Account Balance: " << savings.getBalance() << endl;
    cout << "Current Account Balance: " << current.getBalance() << endl;

}