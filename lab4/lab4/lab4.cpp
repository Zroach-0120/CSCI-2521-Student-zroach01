/**
*  @file    lab4.cpp
*  @author  Zachary Roach
*  @date    2/15/26
* @ brief   A simple C++ program that greats the user by its name.
*

*/


#include <iostream>
using namespace std;

int main()
{
    int maxDigit;

    // Input and validation loop
    do
    {
        cout << "Please enter the maximum digit for the multiplication table." << endl;
        cout << "The digit must be greater than 4 and less than 10" << endl;
        cout << "Max Digit: ";
        cin >> maxDigit;

        if (maxDigit <= 4 || maxDigit >= 10)
        {
            cout << "Error: The max diget must be greater than 4 and less than 10. Please try again." << endl;
        }

    } while (maxDigit <= 4 || maxDigit >= 10);

    // multiplication table
    for (int i = 1; i <= maxDigit; i++)
    {
        for (int j = 1; j <= maxDigit; j++)
        {
            cout << i * j << "\t";
        }
        cout << endl;
    }

    return 0;
}
