#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

/**
 * @brief Represents a bank customer.
 */
class Customer
{
private:
    string customerID;
    string email;

public:
    /**
     * @brief Default constructor
     */
    Customer();

    /**
     * @brief Parameterized constructor
     * @param id Customer ID
     * @param emailAddr Email address
     */
    Customer(const string& id, const string& emailAddr);

    /**
     * @brief Gets customer ID
     * @return ID
     */
    string getCustomerID() const;

    /**
     * @brief Gets email
     * @return email
     */
    string getEmail() const;

    /**
     * @brief Prints customer info
     */
    void printCustomerInfo() const;
};

#endif