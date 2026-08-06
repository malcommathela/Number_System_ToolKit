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
#include <limits>
#include <cmath>
#include <algorithm>
#include <cctype>
#include <iomanip>

using namespace std;

// ==================== FUNCTION PROTOTYPES ====================

void displayBanner();
void displayMenu();
void displaySeparator(char ch = '=', int length = 60);
int getMenuChoice();
long long getValidDecimal(const string& prompt);
string getValidBinary(const string& prompt);
bool isValidBinaryString(const string& str);
string decimalToBinary(long long decimal);
long long binaryToDecimal(const string& binary);
bool isPrime(long long num);
bool isPalindromeNumber(long long num);
bool isPalindromeString(const string& str);
void waitForEnter();

// ==================== MAIN FUNCTION ====================

int main() {
    displayBanner();

    int choice;

    do {
        displayMenu();
        choice = getMenuChoice();
        cout << "\n";

        switch (choice) {
            case 1: {
                // --------------------------------------------------------
                // OPTION 1: DECIMAL TO BINARY CONVERSION
                // --------------------------------------------------------
                displaySeparator('-');
                cout << "         DECIMAL TO BINARY CONVERSION" << endl;
                displaySeparator('-');

                long long dec = getValidDecimal("Enter a decimal number: ");
                string bin = decimalToBinary(dec);

                cout << "\n  +-----------------------------+" << endl;
                cout << "  |         RESULT              |" << endl;
                cout << "  +-----------------------------+" << endl;
                cout << "  | Decimal  : " << setw(25) << left << dec << "|" << endl;
                cout << "  | Binary   : " << setw(25) << bin << "|" << endl;

                if (isPalindromeString(bin)) {
                    cout << "  | Note     : Binary is a      |" << endl;
                    cout << "  |            PALINDROME!      |" << endl;
                }
                cout << "  +-----------------------------+" << endl;

                waitForEnter();
                break;
            }

            case 2: {
                // --------------------------------------------------------
                // OPTION 2: BINARY TO DECIMAL CONVERSION
                // --------------------------------------------------------
                displaySeparator('-');
                cout << "         BINARY TO DECIMAL CONVERSION" << endl;
                displaySeparator('-');

                string bin = getValidBinary("Enter a binary number: ");
                long long dec = binaryToDecimal(bin);

                cout << "\n  +-----------------------------+" << endl;
                cout << "  |         RESULT              |" << endl;
                cout << "  +-----------------------------+" << endl;
                cout << "  | Binary   : " << setw(25) << bin << "|" << endl;
                cout << "  | Decimal  : " << setw(25) << dec << "|" << endl;

                if (isPalindromeNumber(dec)) {
                    cout << "  | Note     : Decimal is a     |" << endl;
                    cout << "  |            PALINDROME!      |" << endl;
                }
                cout << "  +-----------------------------+" << endl;

                waitForEnter();
                break;
            }

            case 3: {
                // --------------------------------------------------------
                // OPTION 3: CHECK PRIME NUMBER
                // --------------------------------------------------------
                displaySeparator('-');
                cout << "           PRIME NUMBER CHECK" << endl;
                displaySeparator('-');

                long long num = getValidDecimal("Enter a number to check: ");

                cout << "\n  +-----------------------------+" << endl;
                cout << "  |         RESULT              |" << endl;
                cout << "  +-----------------------------+" << endl;
                cout << "  | Number   : " << setw(25) << num << "|" << endl;

                if (isPrime(num)) {
                    cout << "  | Status   : " << setw(25) << "PRIME NUMBER" << "|" << endl;
                } else {
                    cout << "  | Status   : " << setw(25) << "NOT PRIME" << "|" << endl;
                    if (num <= 1) {
                        cout << "  | Reason   : Must be > 1      |" << endl;
                    } else {
                        cout << "  | Reason   : Has other factors|" << endl;
                    }
                }
                cout << "  +-----------------------------+" << endl;

                waitForEnter();
                break;
            }

            case 4: {
                // --------------------------------------------------------
                // OPTION 4: CHECK PALINDROME NUMBER
                // --------------------------------------------------------
                displaySeparator('-');
                cout << "        PALINDROME NUMBER CHECK" << endl;
                displaySeparator('-');

                long long num = getValidDecimal("Enter a number to check: ");

                // Compute reversed number for display
                long long temp = num;
                if (temp < 0) temp = -temp;
                long long reversed = 0;
                while (temp > 0) {
                    reversed = reversed * 10 + (temp % 10);
                    temp /= 10;
                }
                if (num < 0) reversed = -reversed;

                cout << "\n  +-----------------------------+" << endl;
                cout << "  |         RESULT              |" << endl;
                cout << "  +-----------------------------+" << endl;
                cout << "  | Number   : " << setw(25) << num << "|" << endl;
                cout << "  | Reversed : " << setw(25) << reversed << "|" << endl;

                if (isPalindromeNumber(num)) {
                    cout << "  | Status   : " << setw(25) << "PALINDROME!" << "|" << endl;
                } else {
                    cout << "  | Status   : " << setw(25) << "NOT PALINDROME" << "|" << endl;
                }
                cout << "  +-----------------------------+" << endl;

                waitForEnter();
                break;
            }

            case 5: {
                // --------------------------------------------------------
                // OPTION 5: EXIT
                // --------------------------------------------------------
                displaySeparator('=');
                cout << "  Thank you for using Number System Toolkit!" << endl;
                cout << "                Goodbye!" << endl;
                displaySeparator('=');
                break;
            }

            default: {
                cout << "\n  [!] Invalid choice! Please select 1-5.\n";
                waitForEnter();
                break;
            }
        }

    } while (choice != 5);

    return 0;
}

// ==================== FUNCTION DEFINITIONS ====================

/**
 * Displays the application banner at startup.
 */
void displayBanner() {
    cout << "\n";
    displaySeparator('=');
    cout << "         NUMBER SYSTEM TOOLKIT" << endl;
    cout << "         Cornerstone Project 1" << endl;
    displaySeparator('=');
    cout << "\n";
}

/**
 * Displays the main menu options.
 */
void displayMenu() {
    cout << "\n";
    displaySeparator('-');
    cout << "              MAIN MENU" << endl;
    displaySeparator('-');
    cout << "  [1] Convert Decimal to Binary" << endl;
    cout << "  [2] Convert Binary to Decimal" << endl;
    cout << "  [3] Check Prime Number" << endl;
    cout << "  [4] Check Palindrome Number" << endl;
    cout << "  [5] Exit" << endl;
    displaySeparator('-');
}

/**
 * Prints a separator line.
 */
void displaySeparator(char ch, int length) {
    for (int i = 0; i < length; ++i) {
        cout << ch;
    }
    cout << endl;
}

/**
 * Pauses execution until user presses Enter.
 */
void waitForEnter() {
    cout << "\n  Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl;
}

/**
 * Gets and validates menu choice (1-5).
 * Uses a loop to ensure valid integer input.
 */
int getMenuChoice() {
    int choice;
    cout << "\n  Enter your choice (1-5): ";

    while (!(cin >> choice)) {
        cin.clear();  // clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  [!] Invalid input! Enter a number (1-5): ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return choice;
}

/**
 * Gets and validates a decimal integer input.
 * Loops until user enters a valid integer.
 */
long long getValidDecimal(const string& prompt) {
    long long num;
    cout << "\n  " << prompt;

    while (!(cin >> num)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "  [!] Invalid input! Please enter a valid integer: ";
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return num;
}

/**
 * Validates whether a string is a valid binary number.
 * Allows optional leading + or - sign.
 */
bool isValidBinaryString(const string& str) {
    if (str.empty()) return false;

    size_t start = 0;
    if (str[0] == '-' || str[0] == '+') {
        if (str.length() == 1) return false;
        start = 1;
    }

    for (size_t i = start; i < str.length(); ++i) {
        if (str[i] != '0' && str[i] != '1') {
            return false;
        }
    }
    return true;
}

/**
 * Gets and validates a binary string input.
 * Uses a loop with getline for full string handling.
 */
string getValidBinary(const string& prompt) {
    string bin;
    cout << "\n  " << prompt;

    while (true) {
        getline(cin, bin);

        // Remove whitespace characters
        bin.erase(remove_if(bin.begin(), bin.end(),
            [](unsigned char c) { return isspace(c); }), bin.end());

        if (isValidBinaryString(bin)) {
            break;
        }

        cout << "  [!] Invalid binary! Use only 0s and 1s: ";
    }

    return bin;
}

/**
 * Converts a decimal number to its binary string representation.
 * Algorithm: Repeated division by 2, collecting remainders.
 */
string decimalToBinary(long long decimal) {
    if (decimal == 0) return "0";

    bool negative = false;
    if (decimal < 0) {
        negative = true;
        decimal = -decimal;
    }

    string binary = "";
    long long num = decimal;

    // Loop: divide by 2 until number becomes 0
    while (num > 0) {
        int remainder = num % 2;
        binary = char('0' + remainder) + binary;  // prepend remainder
        num /= 2;
    }

    if (negative) {
        binary = "-" + binary;
    }

    return binary;
}

/**
 * Converts a binary string to its decimal value.
 * Algorithm: Horner's method / positional weight from right to left.
 */
long long binaryToDecimal(const string& binary) {
    bool negative = false;
    size_t start = 0;

    if (binary[0] == '-') {
        negative = true;
        start = 1;
    } else if (binary[0] == '+') {
        start = 1;
    }

    long long decimal = 0;
    long long power = 1;

    // Loop from rightmost bit to leftmost
    for (int i = static_cast<int>(binary.length()) - 1; i >= static_cast<int>(start); --i) {
        if (binary[i] == '1') {
            decimal += power;
        }
        power *= 2;
    }

    return negative ? -decimal : decimal;
}

/**
 * Checks if a number is prime.
 * Algorithm: Trial division up to square root.
 * Uses loop with step 2 for efficiency (skips even numbers).
 */
bool isPrime(long long num) {
    // Numbers <= 1 are not prime
    if (num <= 1) return false;

    // 2 is the only even prime
    if (num == 2) return true;

    // Even numbers > 2 are not prime
    if (num % 2 == 0) return false;

    // Check odd divisors from 3 to sqrt(num)
    for (long long i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;  // Found a factor
        }
    }

    return true;
}

/**
 * Checks if a number is a palindrome.
 * Algorithm: Reverse the number mathematically and compare.
 */
bool isPalindromeNumber(long long num) {
    if (num < 0) num = -num;  // Handle negatives

    long long original = num;
    long long reversed = 0;

    // Loop: extract digits and build reversed number
    while (num > 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }

    return original == reversed;
}

/**
 * Checks if a string is a palindrome.
 * Algorithm: Two-pointer comparison from both ends.
 */
bool isPalindromeString(const string& str) {
    if (str.empty()) return true;

    size_t left = 0;
    size_t right = str.length() - 1;

    // Loop: compare characters moving inward
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}