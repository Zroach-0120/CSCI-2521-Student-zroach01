/**
 * @file Lab10_zroach.cpp
 * @author Zachary Roach    
 * @date 4/19/26
 * @brief Demonstrates a banking system using polymorphism,saving, file output, and class inheritance with Account and SavingsAccount.
 */


#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include "Customer.h"

using namespace std;

// ===== Function Prototypes =====

void printMenu();
int getMenuOption();
bool isAmountValid(double amount);
bool isMenuChoiceValid(int choice);
void printInvalidMenuChoiceMessage();
double getDepositAmount();
double getWithdrawalAmount();
void printInvalidAmountMessage();

// ===== Constants =====

const int DEPOSIT = 1;
const int WITHDRAWAL = 2;
const int CLOSE_OF_BUSINESS = 3;
const int QUIT = 4;

// ===== MAIN =====

int main()
{
    Customer customer("0123456789", "customer@cscc.edu");

    Account* account =
        new SavingsAccount("5423678409", 100.00, 0.005, customer);

    account->printAccountInfo();

    int menuChoice = getMenuOption();

    while (menuChoice != QUIT)
    {
        double amount = 0;

        switch (menuChoice)
        {
        case DEPOSIT:
            amount = getDepositAmount();
            account->deposit(amount);
            break;

        case WITHDRAWAL:
            amount = getWithdrawalAmount();
            account->withdraw(amount);
            break;

        case CLOSE_OF_BUSINESS:
            account->closeOfBusiness();

            
            ((SavingsAccount*)account)->Save();

            break;
        }

        menuChoice = getMenuOption();
    }

    delete account;
    return 0;
}

// ===== FUNCTION DEFINITIONS =====

void printMenu()
{
    cout << "\nCSCC Bank and Trust\n";
    cout << "1. Deposit\n";
    cout << "2. Withdraw\n";
    cout << "3. Close of Business\n";
    cout << "4. Quit\n";
}

int getMenuOption()
{
    int choice;

    do
    {
        printMenu();
        cin >> choice;

        if (!isMenuChoiceValid(choice))
        {
            printInvalidMenuChoiceMessage();
        }

    } while (!isMenuChoiceValid(choice));

    return choice;
}

bool isMenuChoiceValid(int choice)
{
    return choice >= DEPOSIT && choice <= QUIT;
}

bool isAmountValid(double amount)
{
    return amount > 0;
}

void printInvalidMenuChoiceMessage()
{
    cout << "Invalid option. Try again.\n";
}

double getDepositAmount()
{
    double amount;

    do
    {
        cout << "Enter deposit amount: $";
        cin >> amount;

        if (!isAmountValid(amount))
        {
            printInvalidAmountMessage();
        }

    } while (!isAmountValid(amount));

    return amount;
}

double getWithdrawalAmount()
{
    double amount;

    do
    {
        cout << "Enter withdrawal amount: $";
        cin >> amount;

        if (!isAmountValid(amount))
        {
            printInvalidAmountMessage();
        }

    } while (!isAmountValid(amount));

    return amount;
}

void printInvalidAmountMessage()
{
    cout << "Amount must be greater than $0.00\n";
}