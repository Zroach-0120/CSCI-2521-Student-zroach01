/**
 * @file exercise1source.cpp
 * @author zachary roach
 * @date 3/7/2026
 * @brief This program validates a UPC-A code by checking its format and calculating the check digit
 */



#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to validate UPC format
bool isValidUPC(const string& upc) {
    return upc.length() == 12 && all_of(upc.begin(), upc.end(), ::isdigit);
}

// Function to calculate the check digit of a UPC-A code
int calculateCheckDigit(const string& upc)
{
    int oddSum = 0, evenSum = 0;

    // Iterate through the first 11 digits
    for (int i = 0; i < 11; i++) {
        if (i % 2 == 0) {
            oddSum += upc[i] - '0';  // Convert char to int and add to odd sum
        }
        else {
            evenSum += upc[i] - '0'; // Convert char to int and add to even sum
        }
    }

    // Apply the UPC-A check digit formula
    int total = (oddSum * 3) + evenSum;
    int modulo = total % 10;
    int checkDigit = (modulo == 0) ? 0 : (10 - modulo);

    return checkDigit;
}

int main()
{
    string upc, firstDigit, lastDigit, manufacturer, product;
    char choice;

    do {
        cout << "Enter a 12-digit UPC code: ";
        cin >> upc;

        if (!isValidUPC(upc)) {
            cout << "Invalid input. Please enter exactly 12 numeric digits.\n";
            continue;
        }

        cout << "Enter the very first number of the UPC: ";
        cin >> firstDigit;
        cout << "Enter the very last number of the UPC: ";
        cin >> lastDigit;
        cout << "Enter your Manufacturer number (the first set of 5 digits): ";
        cin >> manufacturer;
        cout << "Enter your Product number (the second set of 5 digits): ";
        cin >> product;

        int calculatedCheckDigit = calculateCheckDigit(upc);
        int givenCheckDigit = upc[11] - '0';

        if (calculatedCheckDigit == givenCheckDigit) {
            cout << "UPC code " << upc << " is valid.\n";
        }
        else {
            cout << "Invalid UPC code. Expected check digit: " << calculatedCheckDigit << " but found: " << givenCheckDigit << "\n";
        }

        cout << "Do you have another number to test? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Type any key and then hit <ENTER> to quit the proram.\n";
    return 0;
}
