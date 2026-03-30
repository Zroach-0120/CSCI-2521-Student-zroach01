/**
 * @file Lab8_zroach01.cpp
 * @author Your Name
 * @date 2026-03-28
 * @brief Demonstrates stack vs heap memory and the use of pointers and references.
 */




#include <iostream>
using namespace std;

int main()
{
    // Stack Allocation
    int stackInt = 10;  // stack variable

    // Heap Allocation
    int* heapInt = new int;  // alocate memory on heap
    *heapInt = 20;           // asign value

    // Pointer Creation
    int* ptrToStack = &stackInt;

    // Reference Creation
    int& refToStack = stackInt;

    // Output Stack Variable
    cout << "Stack Variable (stackInt):" << endl;
    cout << "  Value: " << stackInt << endl;
    cout << "  Address: " << &stackInt << endl;
    cout << endl;

    // Output Heap Variable
    cout << "Heap Variable (heapInt):" << endl;
    cout << "  Value: " << *heapInt << endl;
    cout << "  Address: " << heapInt << endl;
    cout << endl;

    // Output Pointer to Stack
    cout << "Pointer to Stack (ptrToStack):" << endl;
    cout << "  Value Pointed To: " << *ptrToStack << endl;
    cout << "  Address Stored: " << ptrToStack << endl;
    cout << endl;

    // Output Reference to Stack
    cout << "Reference to Stack (refToStack):" << endl;
    cout << "  Value Referred To: " << refToStack << endl;
    cout << "  Address: " << &refToStack << endl;
    cout << endl;

    // Cleanup Heap Memory
    delete heapInt;
    heapInt = nullptr;

    return 0;
}