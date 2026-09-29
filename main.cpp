/**
 * ============================================================================
 * NUMBER SYSTEM TOOLKIT
 * Cornerstone Project 1
 * ============================================================================
 *
 * Features:
 *   1. Decimal to Binary Conversion
 *   2. Binary to Decimal Conversion
 *   3. Prime Number Check
 *   4. Palindrome Number Check
 *   5. Input Validation for all operations
 *
 * Requirements Met:
 *   - Converting numbers (Decimal <-> Binary)
 *   - Checking prime and palindrome numbers
 *   - Use of loops and functions
 *   - Input validation
 *   - Menu-driven program
 *
 * Compiler: C++17 or later (CLion compatible)
 * Author:   Student
 * ============================================================================
 */

#include <iostream>
#include <string>
using namespace std;

// Decimal to Binary
string decimalToBinary(int n) {
    if (n == 0)
        return "0";

    string binary = "";

    while (n > 0) {
        binary = char('0' + n % 2) + binary;
        n = n / 2;
    }

    return binary;
}

// Binary to Decimal
int binaryToDecimal(string binary) {
    int decimal = 0;

    for (char bit : binary) {
        decimal = decimal * 2 + (bit - '0');
    }

    return decimal;
}

// Prime Check
bool isPrime(int n) {
    if (n < 2)
        return false;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }

    return true;
}

// Palindrome Check
bool isPalindrome(int n) {
    int original = n;
    int reverse = 0;

    while (n > 0) {
        reverse = reverse * 10 + n % 10;
        n = n / 10;
    }

    return original == reverse;
}

int main() {

    int choice;

    do {
        cout << "\n===== NUMBER SYSTEM TOOLKIT =====\n";
        cout << "1. Decimal to Binary\n";
        cout << "2. Binary to Decimal\n";
        cout << "3. Check Prime\n";
        cout << "4. Check Palindrome\n";
        cout << "5. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            int n;
            cout << "Enter decimal number: ";
            cin >> n;

            cout << "Binary = " << decimalToBinary(n) << endl;
            break;
        }

        case 2: {
            string binary;
            cout << "Enter binary number: ";
            cin >> binary;

            cout << "Decimal = "
                 << binaryToDecimal(binary) << endl;
            break;
        }

        case 3: {
            int n;
            cout << "Enter number: ";
            cin >> n;

            if (isPrime(n))
                cout << "Prime Number\n";
            else
                cout << "Not a Prime Number\n";

            break;
        }

        case 4: {
            int n;
            cout << "Enter number: ";
            cin >> n;

            if (isPalindrome(n))
                cout << "Palindrome\n";
            else
                cout << "Not a Palindrome\n";

            break;
        }

        case 5:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}