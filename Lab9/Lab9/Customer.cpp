#include "Customer.h"
#include <iostream>

using namespace std;

/**
 * @brief Default constructor
 */
Customer::Customer()
{
    customerID = "Unknown";
    email = "none@example.com";
}

/**
 * @brief Parameterized constructor
 */
Customer::Customer(const string& id, const string& emailAddr)
{
    customerID = id;
    email = emailAddr;
}

/**
 * @brief Gets customer ID
 */
string Customer::getCustomerID() const { return customerID; }

/**
 * @brief Gets email
 */
string Customer::getEmail() const { return email; }

/**
 * @brief Prints customer info
 */
void Customer::printCustomerInfo() const
{
    cout << "Customer ID: " << customerID << endl;
    cout << "Email: " << email << endl;
}