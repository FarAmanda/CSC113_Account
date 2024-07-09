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
            //chris- I added this part becuase I thought that we shouldn't immediately create a new account, ask the user if the input was a mistake first
            //has some kinks to work out
            int option = 1;
            std::cout << "number entered does not match any preexisting accounts, enter 1 if it was a mistake, or 2 to create a new account: ";
            std::cin >> option;
            switch(option){
                case 1:
                    this -> startUp(accounts, 5);
                  break;
                case 2:
                this[i].accountNum = accNumber;
                std::cout << "Hello new user, what is your name? ";
                std::cin >> this[i].name;
                //taking this out fixed a previous error that it would call the loop endlessly when you inputed 1 
                //even once
                //std::cout << "Hello " << this[i].name << "! Nice to meet you!\n\n";
                //return i;
                break; 
            }
            //instead I have it here
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
    //there was an issue that whenever we called option 5, it reset the accounts and no old ids would work(all would create a new account)
    //this fixes that issue but causes others unfortunately
    return std::min(a.accountNum, b.accountNum);
}

bool account::sortAscBalance(const account& a, const account& b) {
    //for some reason this lets the ids to stay stored even after we display the accounts
 return std::min(a.balance, b.balance);
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

void account::printAscBalance(account arr[], int size) const {
    // Sort the array of accounts using sortAscID function
    // arr is the starting point and arr+size is the end point
    std::sort(arr, arr + size, account::sortAscBalance);

    // Print sorted accounts
    std::cout << "Accounts sorted by Balance in ascending order:\n";
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



