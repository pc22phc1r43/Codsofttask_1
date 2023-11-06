#include <iostream>
using namespace std;

int main() {
    double num1, num2, result;
    char operation;

    // Input
   cout << "Enter the first number: ";
    cin >> num1;

   cout << "Enter the second number: ";
    cin >> num2;

   cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    // Perform the selected operation
    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
               cout << "Error: Division by zero is not allowed." << endl;
                return 1; // Exit with an error code
            }
            break;
        default:
            cout << "Invalid operation. Please choose +, -, *, or /." <<endl;
            return 1; // Exit with an error code
    }

    // Output the result
    cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result <<endl;

    return 0;
}
