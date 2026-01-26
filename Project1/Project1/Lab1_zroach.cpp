/**
*  @file    Source.cpp
*  @author  Zachary Roach
*  @date    2026-1-25
* @ brief   A simple C++ program that greats the user by its name.
* 

*/

#include<iostream>
using namespace std;

int main() {
	string firstName, lastName;
	cout << "enter your first name" << endl;
	cin >> firstName;
	cout << "enter your last name" << endl;
	cin >> lastName;
	cout << "Welcome to c++ Programming," << firstName << " " << lastName << "!" << endl;
	return 0;
}