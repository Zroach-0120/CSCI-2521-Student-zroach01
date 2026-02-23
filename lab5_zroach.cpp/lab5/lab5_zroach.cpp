/**
*  @file    lab5.cpp
*  @author  Zachary Roach
*  @date    2/21/26
* @ brief   A modular program to generate a multiplication table using functions
*

*/




#include <iostream>
using namespace std;

/**
 * @brief This function prints an error message if the user enters invalid input.
 * @param None
 * @return None
 */
void printInputValidationError()
{
    cout << "Error: The max digit must be greater than 4 and less than 10. Please try again." << endl;
}

/**
 * @brief This function checks if the input is within the valid range.
 * @param input The number entered by the user
 * @return true if input is greater than 4 and less than 10, otherwise false.
 */
bool isMaxDigitInputValid(int input)
{
    if (input > 4 && input < 10)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * @brief This function asks the user for the max digit and keeps asking until it is valid.
 * @param None.
 * @return The valid max digit entered by the user.
 */
int getMaxDigitInput()
{
    int maxDigit;

    cout << "Please enter the maximum digit for the multplication table." << endl;
    cout << "The digit must be greater than 4 and less than 10." << endl;

    while (true)
    {
        cout << "Max Digit: ";
        cin >> maxDigit;

        if (isMaxDigitInputValid(maxDigit))
        {
            break; // input is valid, stop looping
        }
        else
        {
            printInputValidationError();
        }
    }

    return maxDigit;
}

/**
 * @brief This function prints the multiplication table.
 * @param maxDigit The largest digit to use in the table.
 * @return None.
 */
void printMultiplicationTable(int maxDigit)
{
    for (int i = 1; i <= maxDigit; i++)
    {
        for (int j = 1; j <= maxDigit; j++)
        {
            cout << (i * j) << "\t";
        }
        cout << endl;
    }
}

/**
 * @brief Main function of the program.
 * @param None.
 * @return 0 if the program runs successfully.
 */
int main()
{
    int maxDigit = getMaxDigitInput();
    printMultiplicationTable(maxDigit);

    return 0;
}
