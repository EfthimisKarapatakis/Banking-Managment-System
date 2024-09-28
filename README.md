# Banking Management System

This is a simple banking management system implemented in C. It allows a user to log in, view their balance, deposit money, and withdraw money.

## Features

- **Login**: A user can log in using a predefined username and password.
- **View Balance**: Once logged in, the user can view their current account balance.
- **Deposit**: The user can deposit money into their account.
- **Withdraw**: The user can withdraw money from their account, as long as they have enough funds.
- **Persistent Balance**: The account balance is stored in a `balance.txt` file, and it is updated after each transaction.

## Files

- `bank_management.c`: The main C program for the banking management system.
- `balance.txt`: Stores the account balance. The starting balance is set when the program first reads this file.

## How to Compile and Run

1. **Ensure you have GCC installed**:  
   If you're using Linux or macOS, GCC is usually installed by default. On Windows, you can use MinGW.

2. **Compile the program**:
   ```bash
   gcc -o bank_management bank_management.c
