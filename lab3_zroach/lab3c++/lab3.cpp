/**
*  @file    lab3.cpp
*  @author  Zachary Roach
*  @date    2-7-2026
* @ brief
*

*/



#include <iostream>
using namespace std;

int main()
{
    const double PI = 3.14159;
    int choice;
    double length, width, radius, area;

    // Display menu
    cout << "Menu" << endl;
    cout << "1. Calculate the area of a Rectangle" << endl;
    cout << "2. Calculate the Area of a Circle" << endl;
    cout << "3. Quit" << endl;
    cout << "Please make a menu selection: ";
    cin >> choice;

    // Option 1: Rectangle
    if (choice == 1)
    {
        cout << "Please enter the length of the rectangle: ";
        cin >> length;
        cout << "Please enter the width of the rectangle: ";
        cin >> width;

        area = length * width;
        cout << "The area of the rectangle is: " << area << endl;
    }
    // Opton 2: Circle
    else if (choice == 2)
    {
        cout << "Please enter the radius of the circle: ";
        cin >> radius;

        area = PI * radius * radius;
        cout << "The area of the circle is: " << area << endl;
    }
    // Option 3: Quit
    else if (choice == 3)
    {
        cout << "Exiting program..." << endl;
        return 0;
    }
    // Invalid input
    else
    {
        cout << "Invalid menu option." << endl;
    }

    return 0;
}
