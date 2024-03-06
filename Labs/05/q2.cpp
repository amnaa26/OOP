/*
 * Creator: Amna(23k-0066)
 * Desc: Create a class called LoanHelper, which helps the user calculate their loan payments. The class should have a variable that stores interest rate for the loan as a user defined constant value. Aside from the that, it also stores the amount for the loan taken and amount of months
		 that the user will repay the loan in. The loan repayment should be calculated on a monthly basis, and the interest rate should be applied over the monthly return amount. The output should be something like:
		 “You have to pay 999 every month for 12 months to repay your loan”
		 Note: first divide loan amount by number of months, then apply the interest rate on it. Interest rate should be a value between 0-0.5%
*/

#include <iostream>
using namespace std;

class LoanHelper {
    const float INTEREST_RATE; 
    float loanAmount; 
    int repaymentMonths; 

public:
    LoanHelper(float interestRate, float amount, int months) : INTEREST_RATE(interestRate) {
        loanAmount = amount;
        repaymentMonths = months;
    }

    
    float calculateMonthlyPayment() {
        float monthlyPayment = loanAmount / repaymentMonths; 
        float monthlyInterest = monthlyPayment * INTEREST_RATE; 
        monthlyPayment += monthlyInterest; 
        return monthlyPayment;
    }

    
    void displayRepaymentDetails() {
        float monthlyPayment = calculateMonthlyPayment();
        cout << "You have to pay " << monthlyPayment << " every month for " << repaymentMonths << " months to repay your loan." << endl;
    }
};

int main() {
    
    float interestRate = 0.005; // 0.5% interest rate
    float loanAmount = 1000.0; 
    int repaymentMonths = 12; 
    LoanHelper loanHelper(interestRate, loanAmount, repaymentMonths);

    
    loanHelper.displayRepaymentDetails();

    return 0;
}

