#include "Account.h"
#include <iostream>
#include <numeric>

using namespace std;

/**
 * @brief Default constructor
 */
Account::Account()
{
    accountNumber = "0000000000";
    balance = 0.0;
    owner = Customer();
}

/**
 * @brief Parameterized constructor
 * @param accNum Account number
 * @param initBal Initial balance
 * @param cust Customer object
 */
Account::Account(const string& accNum, double initBal, const Customer& cust)
    : accountNumber(accNum), balance(initBal), owner(cust)
{
}

/**
 * @brief Adds deposit transaction
 * @param amount Deposit amount
 * @return true if valid
 */
bool Account::deposit(double amount)
{
    if (amount > 0)
    {
        deposits.push_back(amount);
        return true;
    }
    return false;
}

/**
 * @brief Adds withdrawal transaction
 * @param amount Withdrawal amount
 * @return true if valid
 */
bool Account::withdraw(double amount)
{
    if (amount > 0)
    {
        withdrawals.push_back(amount);
        return true;
    }
    return false;
}

/**
 * @brief Processes end-of-day transactions
 */
void Account::closeOfBusiness()
{
    double totalDeposits =
        accumulate(deposits.begin(), deposits.end(), 0.0);

    double totalWithdrawals =
        accumulate(withdrawals.begin(), withdrawals.end(), 0.0);

    double previousBalance = balance;

    double newBalance =
        previousBalance + totalDeposits - totalWithdrawals;

    printSummary(previousBalance, totalDeposits, totalWithdrawals, newBalance);

    balance = newBalance;

    deposits.clear();
    withdrawals.clear();
}

/**
 * @brief Prints account summary
 */
void Account::printAccountInfo() const
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Current Balance: $" << balance << endl;
    owner.printCustomerInfo();
}

/**
 * @brief Prints transaction summary
 */
void Account::printSummary(double previousBalance,
    double totalDeposits,
    double totalWithdrawals,
    double newBalance) const
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Previous Balance: $" << previousBalance << endl;
    cout << "Total Deposits: $" << totalDeposits << endl;
    cout << "Total Withdrawals: $" << totalWithdrawals << endl;
    cout << "New Balance after COB: $" << newBalance << endl;
}

/**
 * @brief Gets balance
 * @return balance
 */
double Account::getBalance() const { return balance; }

/**
 * @brief Gets account number
 * @return account number
 */
string Account::getAccountNumber() const { return accountNumber; }

/**
 * @brief Gets customer
 * @return Customer
 */
Customer Account::getCustomer() const { return owner; }

/**
 * @brief Prints pending transactions
 */
void Account::printTransactions() const
{
    cout << "Deposits: ";
    for (double d : deposits) cout << "$" << d << " ";
    cout << endl;

    cout << "Withdrawals: ";
    for (double w : withdrawals) cout << "$" << w << " ";
    cout << endl;
}