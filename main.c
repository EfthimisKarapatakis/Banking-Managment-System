#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define BALANCE_FILE "balance.txt"

struct Account {
char name[MAX];
char password[MAX];
float balance;
};

// Function to clear input buffer
void clear_input_buffer() {
int ch;
while ((ch = getchar()) != '\n' && ch != EOF);
}

void view_balance(float balance) {
printf("Your bank account balance is $%.2f\n", balance);
}

void login(float *balance) {
char username[50];
char password[50];
while(1) {
    printf("Enter your name: ");
    scanf("%s", username);
    printf("\n");
    printf("Enter your password: ");
    scanf("%s", password);
    printf("\n");

    // Use strcmp() for string comparison
    if (strcmp(username, "username") == 0) {
        if (strcmp(password, "password") == 0) {
            FILE *file = fopen(BALANCE_FILE, "r");
            if (file) {
                fscanf(file, "%f", balance);
                fclose(file);
            }
            printf("You logged in successfully!\n");
            break;
        } else {
            printf("Invalid password\n");
        }
    } else {
        printf("Invalid username\n");
    }
}
}

void update_balance(float balance) {
FILE *file = fopen(BALANCE_FILE, "w");
fprintf(file, "%.2f", balance);
fclose(file);
}

void deposit(float *balance) {
float deposit_amount;
printf("Enter the amount you want to deposit: $");
if (scanf("%f", &deposit_amount) != 1) {
    printf("Invalid input! Please enter a valid number.\n");
    clear_input_buffer();
} else {
    *balance += deposit_amount; // Update the balance
    update_balance(*balance);    // Update the file
    printf("Deposit successful! ");
    view_balance(*balance);
}
}

void withdraw(float *balance) {
float withdraw_amount;
printf("Enter the amount you want to withdraw: $");
if (scanf("%f", &withdraw_amount) != 1) {
    printf("Invalid input! Please enter a valid number.\n");
    clear_input_buffer();
} else if (withdraw_amount > *balance) {
    printf("Insufficient funds! Your current balance is $%.2f\n", *balance);
} else {
    *balance -= withdraw_amount; // Update the balance
    update_balance(*balance);     // Update the file
    printf("Withdrawal successful! ");
    view_balance(*balance);
}
}

int main() {
int first_choice;
int second_choice;
float balance = 0;

start1:
printf("Banking Management System\n");
printf("---------------------------------\n");
printf("1. Login to an existing account.\n");
printf("2. Exit\n");
printf(":");
if (scanf("%d", &first_choice) != 1) {
    printf("Invalid input! Please enter a number.\n\n");
    clear_input_buffer();
    goto start1;
}

if (first_choice == 1) {
    login(&balance);
} else if (first_choice == 2) {
    printf("Have a nice day.\n\n");
    return 0;
} else {
    printf("Invalid input.\n");
    goto start1;
}

start2:
printf("\n\nWhat would you like to do next: \n");
printf("1. View account balance.\n");
printf("2. Deposit money.\n");
printf("3. Withdraw money.\n");
printf("4. Exit\n");
printf(":");
if (scanf("%d", &second_choice) != 1) {
    printf("Invalid input! Please enter a number.\n");
    clear_input_buffer();
    goto start2;
}

if (second_choice == 1) {
    view_balance(balance);
} else if (second_choice == 2) {
    deposit(&balance);
} else if (second_choice == 3) {
    withdraw(&balance);
} else if (second_choice == 4) {
    goto start1;
} else {
    printf("Invalid input.\n");
    goto start2;
}

goto start2;
}
