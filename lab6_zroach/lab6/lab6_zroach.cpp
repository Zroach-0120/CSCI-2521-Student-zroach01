/**
 * @file Lab6_zroach.cpp
 * @author zachary roach
 * @date 3/1/2026
 * @brief Compare static arrays and vectors for processing student scores.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * @brief Calculates the average of an integer array.
 * @param arr The array of integers.
 * @param size The number of elements in the array.
 * @return The average as a float.
 */
float calculateAverage(const int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];
    return static_cast<float>(sum) / size;
}

/**
 * @brief Finds the maximum value in an integer array.
 * @param arr The array of integers.
 * @param size The number of elements in the array.
 * @return The highest value.
 */
int findMax(const int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

/**
 * @brief Finds the minimum value in an integer array.
 * @param arr The array of integers.
 * @param size The number of elements in the array.
 * @return The lowest value.
 */
int findMin(const int arr[], int size)
{
    int min = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] < min)
            min = arr[i];
    return min;
}

/**
 * @brief Calculates the average of a vector of integers.
 * @param vec The vector of integers.
 * @return The average as a float.
 */
float calculateAverage(const vector<int>& vec)
{
    int sum = 0;
    for (int value : vec)
        sum += value;
    return static_cast<float>(sum) / vec.size();
}

/**
 * @brief Finds the maximum value in a vector.
 * @param vec The vector of integers.
 * @return The highest value.
 */
int findMax(const vector<int>& vec)
{
    return *max_element(vec.begin(), vec.end());
}

/**
 * @brief Finds the minimum value in a vector.
 * @param vec The vector of integers.
 * @return The lowest value.
 */
int findMin(const vector<int>& vec)
{
    return *min_element(vec.begin(), vec.end());
}

/**
 * @brief Calculates statistics using a fixed-sze static array.
 * @param None.
 * @return None (void).
 */
void arraySolution()
{
    const int SIZE = 10;
    int scores[SIZE];

    cout << "\n--- Array Solution ---\n";

    for (int i = 0; i < SIZE; i++)
    {
        int input;
        do
        {
            cout << "Enter score #" << i + 1 << " (0-100): ";
            cin >> input;
        } while (input < 0 || input > 100);

        scores[i] = input;
    }

    cout << "\nAverage: " << calculateAverage(scores, SIZE) << endl;
    cout << "Highest: " << findMax(scores, SIZE) << endl;
    cout << "Lowest: " << findMin(scores, SIZE) << endl;
}

/**
 * @brief Calculates statistics using a dynamic vector.
 * @param None.
 * @return None (void).
 */
void vectorSolution()
{
    vector<int> scores;
    int input;

    cout << "\n--- Vector Solution ---\n";
    cout << "Enter scores (0-100). Enter -1 to finish.\n";

    while (true)
    {
        cout << "Enter score: ";
        cin >> input;

        if (input == -1)
            break;

        if (input >= 0 && input <= 100)
            scores.push_back(input);
    }

    if (scores.empty())
    {
        cout << "No scores entered.\n";
        return;
    }

    cout << "\nAverage: " << calculateAverage(scores) << endl;
    cout << "Highest: " << findMax(scores) << endl;
    cout << "Lowest: " << findMin(scores) << endl;

    sort(scores.begin(), scores.end());

    cout << "Sorted Scores: ";
    for (int score : scores)
        cout << score << " ";
    cout << endl;
}

/**
 * @brief Entry point of the program.
 * @param None.
 * @return 0 to indicate success.
 */
int main()
{
    arraySolution();
    vectorSolution();
    return 0;
}