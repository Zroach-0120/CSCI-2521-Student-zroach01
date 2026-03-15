/**
*  @file Source.cpp
*  @author Zachary Roach
*  @date 3-14-2026
*  @brief This program simulates a basic banking system that lets a user
*  make deposits, make withdrawals, and run close of business on an account.
*/

#include <iostream>
#include "Account.h"

using namespace std;

void printMenu();
int getMenuOption();
bool isAmountValid(double amount);
bool isMenuChoiceValid(int choice);
void printInvalidMenuChoiceMessage();

const int DEPOSIT = 1;
const int WITHDRAWAL = 2;
const int CLOSE_OF_BUSINESS = 3;
const int QUIT = 4;

/**
*  @brief Runs the main banking menu and allows the user to interact
*  with the account object.
*  @return 0 when the program finishes successfully.
*/
int main()
{
    // just use dummy data for now for the customer and the account
    // we care about interacting with account object for this lab
    Customer customer("0123456789", "customer@cscc.edu");
    Account account("5423678409", 100.00, customer);
    account.printAccountInfo();

    int menuChoice = getMenuOption();

    while (menuChoice != QUIT)
    {
        double amount = 0.0;

        switch (menuChoice)
        {
        case DEPOSIT:
            cout << "Enter deposit amount: $";
            cin >> amount;

            if (isAmountValid(amount))
            {
                account.deposit(amount);
                cout << "Deposit added." << endl;
                account.printTransactions();
            }
            else
            {
                cout << "Invalid amount. Deposit must be greater than 0." << endl;
            }
            break;

        case WITHDRAWAL:
            cout << "Enter withdrawal amount: $";
            cin >> amount;

            if (isAmountValid(amount))
            {
                account.withdraw(amount);
                cout << "Withdrawal added." << endl;
                account.printTransactions();
            }
            else
            {
                cout << "Invalid amount. Withdrawal must be greater than 0." << endl;
            }
            break;

        case CLOSE_OF_BUSINESS:
            account.closeOfBusiness();
            account.printAccountInfo();
            break;
        }

        menuChoice = getMenuOption();
    }

    return 0;
}

void printMenu()
{
    cout << "\nCSCC Bank and Trust" << endl;
    cout << "Select an option:" << endl;
    cout << DEPOSIT << ". Make a deposit" << endl;
    cout << WITHDRAWAL << ". Make a withdrawal" << endl;
    cout << CLOSE_OF_BUSINESS << ". Close of Business" << endl;
    cout << QUIT << ". Quit" << endl;
}

int getMenuOption()
{
    int choice = 0;

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
    cout << "Invalid option selected. Please try again." << endl;
}