# Number System Toolkit

A menu-driven C++ application for performing basic number system conversions and checking important properties of numbers.

## 📌 Project Overview

**Number System Toolkit** is a C++17 console application developed as **Cornerstone Project 1**.

The project provides a simple and interactive way to:

* Convert Decimal numbers to Binary
* Convert Binary numbers to Decimal
* Check whether a number is Prime
* Check whether a number is a Palindrome
* Validate user input
* Perform operations through a menu-driven interface

The project demonstrates the practical use of **loops, functions, conditional statements, strings, and input validation** in C++.

---

## 🎯 Objective

The main objective of this project is to develop a simple number-processing toolkit that helps users perform common number system operations while demonstrating fundamental C++ programming concepts.

---

## 📝 Problem Definition

Students often need to perform number conversions and check numerical properties while learning programming and number systems.

This project provides these operations in a single application with a simple menu-driven interface, reducing the need to perform each calculation manually.

---

## ✨ Features

### 1. Decimal → Binary

Converts a decimal integer into its binary representation using repeated division by 2.

**Example:**

```text
Decimal: 25
Binary : 11001
```

### 2. Binary → Decimal

Converts a valid binary number into its decimal equivalent using positional weights.

**Example:**

```text
Binary : 11001
Decimal: 25
```

### 3. Prime Number Check

Determines whether a number is a prime number.

The program checks possible divisors up to the square root of the number for improved efficiency.

### 4. Palindrome Number Check

Checks whether a number reads the same forwards and backwards.

**Example:**

```text
Number   : 121
Reversed : 121
Status   : PALINDROME!
```

### 5. Input Validation

The program validates:

* Menu choices
* Decimal integer input
* Binary input
* Invalid characters in binary numbers

Invalid input is rejected and the user is prompted again.

---

## 🛠️ Technologies Used

| Technology    | Purpose                 |
| ------------- | ----------------------- |
| C++           | Programming language    |
| C++17         | Language standard       |
| `<iostream>`  | Console input/output    |
| `<string>`    | String handling         |
| `<limits>`    | Input validation        |
| `<algorithm>` | String processing       |
| `<iomanip>`   | Formatted output        |
| CLion         | Development environment |

The project is designed for **C++17 or later** and is compatible with CLion.

---

## 📂 Project Structure

```text
Number-System-Toolkit/
│
├── main.cpp
├── README.md
└── flowcharts/
    ├── decimal-to-binary.png
    ├── binary-to-decimal.png
    ├── prime-check.png
    └── palindrome-check.png
```

---

## ⚙️ Main Modules

The program is divided into separate functions so that each operation has a specific responsibility.

| Function                | Purpose                             |
| ----------------------- | ----------------------------------- |
| `displayBanner()`       | Displays the application title      |
| `displayMenu()`         | Displays available operations       |
| `getMenuChoice()`       | Gets and validates menu selection   |
| `getValidDecimal()`     | Gets a valid decimal integer        |
| `getValidBinary()`      | Gets a valid binary number          |
| `isValidBinaryString()` | Validates binary input              |
| `decimalToBinary()`     | Converts decimal to binary          |
| `binaryToDecimal()`     | Converts binary to decimal          |
| `isPrime()`             | Checks whether a number is prime    |
| `isPalindromeNumber()`  | Checks numerical palindrome         |
| `isPalindromeString()`  | Checks binary string palindrome     |
| `waitForEnter()`        | Pauses before returning to the menu |

These functions are explicitly defined in the project implementation.

---

## 🧮 Algorithms

### Decimal to Binary

1. Read the decimal number.
2. Divide the number by `2`.
3. Store the remainder.
4. Continue dividing until the number becomes `0`.
5. Reverse the collected remainders.
6. Display the binary result.

The implementation uses repeated division by 2 and prepends each remainder to the binary string.

### Binary to Decimal

1. Read the binary number.
2. Start from the rightmost digit.
3. Assign powers of 2 beginning with `2⁰`.
4. Add the corresponding power when the bit is `1`.
5. Continue until all bits are processed.
6. Display the decimal result.

The implementation uses positional weighting/Horner-style processing.

### Prime Number Check

1. If the number is less than or equal to `1`, it is not prime.
2. Check whether the number is `2`.
3. Reject even numbers greater than `2`.
4. Check odd divisors up to `√n`.
5. If a divisor is found, the number is not prime.
6. Otherwise, it is prime.

### Palindrome Check

1. Store the original number.
2. Extract the last digit using `% 10`.
3. Build the reversed number.
4. Remove the last digit using `/ 10`.
5. Compare the original and reversed numbers.
6. If both are equal, the number is a palindrome.

---

## 🖥️ Menu

```text
------------------------------
          MAIN MENU
------------------------------
[1] Convert Decimal to Binary
[2] Convert Binary to Decimal
[3] Check Prime Number
[4] Check Palindrome Number
[5] Exit
------------------------------
```

The program repeatedly displays the menu until the user selects **Exit**.

---

## ▶️ How to Run

### Requirements

* C++ compiler supporting C++17 or later
* CLion, VS Code, Code::Blocks, or another C++ IDE

### Compile

```bash
g++ -std=c++17 main.cpp -o number-toolkit
```

### Run

**Windows:**

```bash
number-toolkit.exe
```

**Linux/macOS:**

```bash
./number-toolkit
```

---

## 📊 Sample Operations

### Decimal to Binary

```text
Enter your choice (1-5): 1

Enter a decimal number: 25

Decimal  : 25
Binary   : 11001
```

### Binary to Decimal

```text
Enter your choice (1-5): 2

Enter a binary number: 11001

Binary   : 11001
Decimal  : 25
```

### Prime Check

```text
Enter your choice (1-5): 3

Enter a number to check: 17

Number   : 17
Status   : PRIME NUMBER
```

### Palindrome Check

```text
Enter your choice (1-5): 4

Enter a number to check: 121

Number   : 121
Reversed : 121
Status   : PALINDROME!
```

---

## 🔐 Input Validation

The application prevents invalid input from causing unexpected behavior.

For binary numbers, only:

```text
0
1
+
-
```

are accepted in the appropriate positions. Invalid binary characters cause the program to request the input again.

---

## 📚 Concepts Demonstrated

This project demonstrates:

* Number system conversion
* Decimal and binary representation
* Functions
* Function prototypes
* `while` loops
* `for` loops
* `do-while` loops
* Conditional statements
* String manipulation
* Input validation
* Mathematical operations
* Menu-driven programming
* Modular programming

---

## 📈 Future Enhancements

Possible future improvements include:

* Binary ↔ Octal conversion
* Binary ↔ Hexadecimal conversion
* Decimal ↔ Hexadecimal conversion
* Armstrong number checking
* Perfect number checking
* Factorial calculation
* Fibonacci series generation
* Support for larger number types
* Graphical user interface
* History of previous calculations

---

## 📁 Documentation

The project documentation can include:

* Objective and problem definition
* Algorithms
* Module explanations
* Flowcharts
* Sample outputs
* Enhancements

These are the documentation areas specified in the project requirements.

---

## 👨‍💻 Project Information

**Project:** Number System Toolkit
**Type:** Cornerstone Project 1
**Language:** C++
**Standard:** C++17
**Platform:** Console Application

---

## 📜 License

This project is developed for academic and educational purposes.
