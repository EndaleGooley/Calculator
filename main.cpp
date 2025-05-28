#include <iostream>
#include <fstream>
#include <limits>
#include <cctype>
#include <string>

using namespace std;

// Function prototypes
double add(double, double);
double subtract(double, double);
double multiply(double, double);
double divide(double, double);

int main() {
    double num1, num2, result;
    char op, repeat, retry;
    char inputChoice, outputChoice;
    string inputFileName, outputFileName;

    do {
        // INPUT choice
        cout << "Would you like to input from the [K]eyboard or [F]ile? [Q] to Quit: ";
        cin >> inputChoice;
        inputChoice = tolower(inputChoice);
        if (inputChoice == 'q') {
            cout << "Bye bye!" << endl;
            break;
        }
        if (inputChoice == 'k') {
            // Validate input for num1, operator, num2
            cout << "Enter num1, operator (+ - * /), and num2: ";
            while (!(cin >> num1)) {
                cout << "Invalid number for num1. Please enter a valid number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            // Validate operator
            cin >> op;
            while (op != '+' && op != '-' && op != '*' && op != '/') {
                cout << "Invalid operator. Please enter one of (+, -, *, /): ";
                cin >> op;
            }
            while (!(cin >> num2)) {
                cout << "Invalid number for num2. Please enter a valid number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } 
        else if (inputChoice == 'f') {
            cout << "Enter the input filename: ";
            cin >> inputFileName;
            ifstream inputFile(inputFileName);
            if (!inputFile) {
                cerr << "Error: Cannot open input file.\n";
                cout << "Would you like to retry? (Y/N): ";
                cin >> retry;
                if (tolower(retry) == 'y') continue;
                else break;
            }
            inputFile >> num1 >> op >> num2;
            inputFile.close();
        } 
        else {
            cout << "Invalid input choice. Try again.\n";
            cout << "Would you like to retry? (Y/N): ";
            cin >> retry;
            if (tolower(retry) == 'y') continue;
            else break;
        }
        // Perform the operation
        switch (op) {
            case '+': result = add(num1, num2); break;
            case '-': result = subtract(num1, num2); break;
            case '*': result = multiply(num1, num2); break;
            case '/':
                if (num2 == 0) {
                    cerr << "Error: Cannot divide by zero.\n";
                    cout << "Would you like to retry? (Y/N): ";
                    cin >> retry;
                    if (tolower(retry) == 'y') continue;
                    else break;
                }
                result = divide(num1, num2); break;
            default:
                cerr << "Invalid operator.\n";
                cout << "Would you like to retry? (Y/N): ";
                cin >> retry;
                if (tolower(retry) == 'y') continue;
                else break;
        }
        // OUTPUT choice
        cout << "Would you like to output to the [C]onsole or to a [F]ile? ";
        cin >> outputChoice;
        outputChoice = tolower(outputChoice);
        if (outputChoice == 'c') {
            cout << num1 << " " << op << " " << num2 << " = " << result << endl;
        } 
        else if (outputChoice == 'f') {
            cout << "Enter the output filename: ";
            cin >> outputFileName;
            ofstream outputFile(outputFileName);
            if (!outputFile) {
                cerr << "Error: Cannot open output file.\n";
                cout << "Would you like to retry? (Y/N): ";
                cin >> retry;
                if (tolower(retry) == 'y') continue;
                else break;
            }
            outputFile << num1 << " " << op << " " << num2 << " = " << result << endl;
            outputFile.close();
            cout << "Result written to file.\n";
        } 
        else {
            cout << "Invalid output choice.\n";
            cout << "Would you like to retry? (Y/N): ";
            cin >> retry;
            if (tolower(retry) == 'y') continue;
            else break;
        }
        cout << "Would you like to perform another calculation? (Y/N): ";
        cin >> repeat;
    } while (tolower(repeat) == 'y');

    return 0;
}
// Function definitions
double add(double num1, double num2) {
    return num1 + num2;
}
double subtract(double num1, double num2) {
    return num1 - num2;
}
double multiply(double num1, double num2) {
    return num1 * num2;
}
double divide(double num1, double num2) {
    return num1 / num2;
}
