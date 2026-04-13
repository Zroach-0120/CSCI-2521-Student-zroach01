#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include "Customer.h"

using namespace std;

/**
 * @brief Represents a bank account with deposit/withdrawal transaction tracking.
 */
class Account
{
protected:
    string accountNumber;
    double balance;
    Customer owner;

    vector<double> deposits;
    vector<double> withdrawals;

    /**
     * @brief Prints a summary of end-of-day account activity.
     * @param previousBalance Balance before processing transactions
     * @param totalDeposits Total deposits made
     * @param totalWithdrawals Total withdrawals made
     * @param newBalance Final balance after processing
     */
    void printSummary(double previousBalance,
        double totalDeposits,
        double totalWithdrawals,
        double newBalance) const;

public:
    /**
     * @brief Default constructor
     */
    Account();

    /**
     * @brief Parameterized constructor
     * @param accNum Account number
     * @param initialBalance Starting balance
     * @param customer Account owner
     */
    Account(const string& accNum,
        double initialBalance,
        const Customer& customer);

    /**
     * @brief Virtual destructor
     */
    virtual ~Account() {}

    /**
     * @brief Adds a deposit transaction
     * @param amount Deposit amount
     * @return true if successful
     */
    bool deposit(double amount);

    /**
     * @brief Adds a withdrawal transaction
     * @param amount Withdrawal amount
     * @return true if successful
     */
    bool withdraw(double amount);

    /**
     * @brief Processes end-of-day transactions
     */
    virtual void closeOfBusiness();

    /**
     * @brief Gets current balance
     * @return Current balance
     */
    double getBalance() const;

    /**
     * @brief Gets account number
     * @return Account number
     */
    string getAccountNumber() const;

    /**
     * @brief Gets account owner
     * @return Customer object
     */
    Customer getCustomer() const;

    /**
     * @brief Prints account information
     */
    virtual void printAccountInfo() const;

    /**
     * @brief Prints pending transactions
     */
    void printTransactions() const;
};

#endif