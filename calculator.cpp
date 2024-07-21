#include <iostream>
using namespace std;

int main() {
    int num1, num2, result;
    char op;


    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second number: ";
    cin >> num2;

    if (op == '+') {
        result = num1 + num2;
    } else if (op == '-') {
        result = num1 - num2;
    } else if (op == '*') {
        result = num1 * num2;
    } else if (op == '/') {
        if (num2 != 0) {
            result = num1 / num2;
        } else {
            cout << "Division by zero is not allowed." << endl;
            return 1;
        }
    } else {
        cout << "Invalid operator. Please use one of +, -, *, /" << endl;
        return 1;
    }

    cout << "Result: " << result << endl;

    return 0;
}
