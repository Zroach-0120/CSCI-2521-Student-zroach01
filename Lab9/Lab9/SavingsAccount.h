#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

/**
 * @brief Savings account that earns daily interest.
 */
class SavingsAccount : public Account
{
private:
    double dailyInterestRate;

public:
    /**
     * @brief Constructor
     * @param accNum Account number
     * @param initialBalance Starting balance
     * @param customer Account owner
     * @param interestRate Daily interest rate
     */
    SavingsAccount(const string& accNum,
        double initialBalance,
        const Customer& customer,
        double interestRate);

    /**
     * @brief Processes transactions and applies interest
     */
    void closeOfBusiness() override;

    /**
     * @brief Prints account info including interest rate
     */
    void printAccountInfo() const override;
};

#endif