#include <iostream>
#include "Account.h"
#include "SavingsAccount.h"
#include "Customer.h"

using namespace std;

// ===== Function Prototypes =====

/**
 * @brief Displays menu options
 */
void printMenu();

/**
 * @brief Gets valid menu option from user
 * @return int menu choice
 */
int getMenuOption();

/**
 * @brief Validates a monetary amount
 * @param amount value entered
 * @return true if valid
 */
bool isAmountValid(double amount);

/**
 * @brief Validates menu choice
 * @param choice menu option
 * @return true if valid
 */
bool isMenuChoiceValid(int choice);

/**
 * @brief Prints invalid menu message
 */
void printInvalidMenuChoiceMessage();

/**
 * @brief Gets deposit amount from user
 * @return valid deposit amount
 */
double getDepositAmount();

/**
 * @brief Gets withdrawal amount from user
 * @return valid withdrawal amount
 */
double getWithdrawalAmount();

/**
 * @brief Prints invalid amount message
 */
void printInvalidAmountMessage();

// ===== Constants =====

const int DEPOSIT = 1;
const int WITHDRAWAL = 2;
const int CLOSE_OF_BUSINESS = 3;
const int QUIT = 4;

// ===== MAIN =====

/**
 * @brief Runs banking simulation using polymorphic Account pointer
 * @return 0 on success
 */
int main()
{
    Customer customer("0123456789", "customer@cscc.edu");

    Account* account =
        new SavingsAccount("5423678409", 100.00, customer, 0.005);

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
            break;
        }

        menuChoice = getMenuOption();
    }

    delete account;
    return 0;
}

// ===== FUNCTION DEFINITIONS (THIS WAS MISSING BEFORE) =====

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