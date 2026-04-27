/**
 * @file Lab11_zroach.cpp
 * @author Zachary Roach
 * @date 4/26/26
 * @brief Demonstrates using a vector of Ohio cities and
 * retrieving items using .at() with exception handling.
 */

#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

// ===== MAIN =====

/**
 * @brief Prompts the user for an index and safely
 * retrieves a city from the vector.
 * If the index is invalid, displays the first
 * or last city instead.
 *
 * @return int Return 0 when program finishes.
 */
int main()
{
    // Create vector of Ohio cities
    vector<string> cities;

    cities.push_back("Columbus");
    cities.push_back("Cleveland");
    cities.push_back("Cincinnati");
    cities.push_back("Toledo");
    cities.push_back("Akron");
    cities.push_back("Dayton");
    cities.push_back("Youngstown");

    int index;

    cout << "Enter an index to look up a city: ";
    cin >> index;

    try
    {
        // Try to access vector using .at()
        cout << "City at index "
            << index
            << " is: "
            << cities.at(index)
            << endl;
    }
    catch (out_of_range&)
    {
        // If index is too low
        if (index < 0)
        {
            cout << "Invalid index. Here's the first city instead: "
                << cities.front()
                << endl;
        }

        // If index is too high
        else if (index >= cities.size())
        {
            cout << "Invalid index. Here's the last city instead: "
                << cities.back()
                << endl;
        }
    }

    return 0;
}