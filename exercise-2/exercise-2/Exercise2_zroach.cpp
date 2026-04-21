/**
 * @file Exercise2_zroach.cpp
 * @author zachary roach
 * @date 4/20/2026
 * @brief This program takes a sentence from the user and translates it into morse code.
 */

#include <iostream>
#include <string>
#include <map>
using namespace std;

string toLowerCase(string str);
string toUpperCase(string str);

// this holds all the morse code letters
class MorseTable {
private:
    map<char, string> table;

public:
    MorseTable() {
        table['A'] = ".-";
        table['B'] = "-...";
        table['C'] = "-.-.";
        table['D'] = "-..";
        table['E'] = ".";
        table['F'] = "..-.";
        table['G'] = "--.";
        table['H'] = "....";
        table['I'] = "..";
        table['J'] = ".---";
        table['K'] = "-.-";
        table['L'] = ".-..";
        table['M'] = "--";
        table['N'] = "-.";
        table['O'] = "---";
        table['P'] = ".--.";
        table['Q'] = "--.-";
        table['R'] = ".-.";
        table['S'] = "...";
        table['T'] = "-";
        table['U'] = "..-";
        table['V'] = "...-";
        table['W'] = ".--";
        table['X'] = "-..-";
        table['Y'] = "-.--";
        table['Z'] = "--..";
    }

    // looks up a character and returns the morse code for it
    string lookup(char c) {
        if (table.count(c) > 0) {
            return table[c];
        }
        return "";
    }
};

// this class handles getting input from the user and printing the translation
class Translator {
private:
    MorseTable morseTable;

    void translate(string sentence) {
        // convert to uppercase so it works for lowercase letters too
        string upper = toUpperCase(sentence);

        for (int i = 0; i < (int)upper.length(); i++) {
            string code = morseTable.lookup(upper[i]);
            // skip anything thats not a letter
            if (code != "") {
                cout << code << " ";
            }
        }
        cout << endl;
    }

    string getInput() {
        string input = "";
        cout << "Enter a sentence (max 50 characters): ";
        getline(cin, input);

        // makre sure it isnt too long
        if ((int)input.length() > 50) {
            input = input.substr(0, 50);
            cout << "Input was too long, truncated to 50 characters." << endl;
        }

        return input;
    }

public:
    void run() {
        string choice = "y";

        while (choice == "y" || choice == "Y") {
            string sentence = getInput();
            cout << "Morse Code: ";
            translate(sentence);

            cout << "Would you like to translate another sentence? (y/n): ";
            getline(cin, choice);
        }

        cout << "Goodbye!" << endl;
    }
};

int main() {
    Translator translator;
    translator.run();
    return 0;
}

string toLowerCase(string str)
{
    string result = "";
    for (int i = 0; i < (int)str.length(); i++)
    {
        result += tolower(str[i]);
    }
    return result;
}

string toUpperCase(string str)
{
    string result = "";
    for (int i = 0; i < (int)str.length(); i++)
    {
        result += toupper(str[i]);
    }
    return result;
}