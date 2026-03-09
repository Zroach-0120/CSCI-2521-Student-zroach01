#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

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
    string upc;
    char choice;

    do {
        cout << "Enter a 12 digit UPC code: ";
        cin >> upc;

        if (upc.length() != 12 || !all_of(upc.begin(), upc.end(), ::isdigit)) {
            cout << "Invalid input. Please enter exactly 12 numeric digits.\n";
            continue;
        }

        int calculatedCheckDigit = calculateCheckDigit(upc);
        int givenCheckDigit = upc[11] - '0';

        if (calculatedCheckDigit == givenCheckDigit) {
            cout << "The UPC code is valid.\n";
        }
        else {
            cout << "The UPC code is INVALID. Expected check digit: " << calculatedCheckDigit << " but found: " << givenCheckDigit << "\n";
        }

        cout << "Do you want to test another UPC? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Goodbye!\n";
    return 0;
}
