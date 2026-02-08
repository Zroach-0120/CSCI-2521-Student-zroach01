/**
*  @file    Source.cpp
*  @author  Zachary Roach
*  @date    1-31-2026
* @ brief   
*

*/

#include<iostream>
using namespace std;

int main() {
    double length;
    double width;
    double perimeter;

    cout << "This application will calclate the perimeter of a rectangle." << endl;

    cout << "Please enter the length of the rectangle: ";
    cin >> length;

    cout << "Please enter the width of the rectangle: ";
    cin >> width;

    perimeter = 2 * (length + width);

    cout << "The perimeter of the rectangle is: " << perimeter << endl;

    return 0;
}