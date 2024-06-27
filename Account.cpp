#include "Account.h"
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace banking;

// Returns index
int account::startUp(account accounts[], int size)
{
    int accNumber; //local account number
    do {
        std::cout << "Please enter your five digit account number:\n ";
        std::cin >> accNumber;
    } while (accNumber <= 9999 || accNumber > 99999);

    for (int i = 0; i < size; i++)
    {
        if (this[i].accountNum == 0)
        {
            this[i].accountNum = accNumber;
            std::cout << "Hello new user, what is your name? ";
            std::cin >> this[i].name;
            std::cout << "Hello " << this[i].name << "! Nice to meet you!\n\n";
            return i;

            //corrected this bit of code -Rabbit
            //std::cout << "\nWelcome Amanda! Your new account has been created.\n";
            //return i;
        }
        else if (this[i].accountNum == accNumber)
        {
            std::cout << "Hello " << this[i].name << "! welcome back!\n\n";
            return i;
        }
    };

    std::cout << "Unfortunately City College Bank has reached the max amount of users," 
        << "Please enter one of the existing account numbers below";
    for (int i = 0; i < size; i++)
    {
        std::cout << "Account Number #" << this[i].accountNum << "User " << this[i].name;
    }

    int y; 
    while (true)
    {
        std::cin >> y;
        for (int i = 0; i < size; i++)
        {
            if (this[i].accountNum == y)
                return i;
        }
    }

}
double account::credit()
{
    double deposit;
    std::cout << "\nHow much money would you like to deposit into your account? ";
    std::cin >> deposit;
    this->balance += deposit;
    return this->balance;

};

double account::debit()
{
    double withdrawal;
    if (this->balance == 0)
    {
        std::cout << "Current balance is 0.00, unable to withdraw money.";
    }
    else
    {
        std::cout << "\nHow much money would you like to withdraw?"
            << "\nCurrent balance is: $" << this->balance << "\n";
        do
        {
            std::cout << "\nPlease remain within account balance: ";
            std::cin >> withdrawal;
        } while (withdrawal > this->balance);
        this->balance -= withdrawal;
        return this->balance;
    }
};

bool account::sortAscID(const account& a, const account& b) {
    return a.accountNum < b.accountNum;
}

void account::printAscID(account arr[], int size) {
    // Sort the array of accounts using sortAscID function
    // arr is the starting point and arr+size is the end point
    std::sort(arr, arr + size, account::sortAscID);

    // Print sorted accounts
    std::cout << "Accounts sorted by ID in ascending order:\n";
    for (int i = 0; i < size; ++i) {
        std::cout << "ID: " << arr[i].accountNum
            << ", Name: " << arr[i].name
            << ", Balance: $" << std::fixed << std::setprecision(2) << arr[i].balance << "\n";
    }
}


//void banking::account::printAsc(account arr[], int size)
//{
//
//};
//
//void printDesc(Account arr[]);



