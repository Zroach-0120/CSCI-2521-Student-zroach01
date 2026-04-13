#include "SavingsAccount.h"
#include <iostream>

using namespace std;

/**
 * @brief Constructor
 */
SavingsAccount::SavingsAccount(const string& accNum,
    double initialBalance,
    const Customer& customer,
    double interestRate)
    : Account(accNum, initialBalance, customer)
{
    dailyInterestRate = interestRate;
}

/**
 * @brief End-of-day processing with interest
 */
void SavingsAccount::closeOfBusiness()
{
    Account::closeOfBusiness();

    if (balance > 0)
    {
        balance += balance * dailyInterestRate;
    }

    printSummary(balance, 0.0, 0.0, balance);
}

/**
 * @brief Prints account info including interest rate
 */
void SavingsAccount::printAccountInfo() const
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Current Balance: $" << balance << endl;
    cout << "Daily Interest Rate: " << dailyInterestRate << endl;
    owner.printCustomerInfo();
}