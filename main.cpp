// CSC113_Account.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "account.h"

int main()
{   
    const int limit = 5;
    banking::account users[limit];
    int input;
    std::cout << "\nHello and welcome to the City College Bank!";
    do
    {
        std::cout << "\nPlease make a selection below"
            << "\n1: Display the balance (account ID should be provided)"
            << "\n2: Deposit money (Credit)"
            << "\n3: Withdraw money (Debit)"
            << "\n4: Display all customers information in ascending order based on the balance"
            << "\n5: Display all customers information in ascending order based on the id"
            << "\n6: Display all customers information in ascending order based on the name"
            << "\n0: Exit\n"
            << "\nYour selection: ";

        std::cin >> input;
        int reference;
        double balance;
        switch (input)
        {
        case 1:
            reference = users[0].startUp(users, limit);

            std::cout << "Your account #" << users[reference].accountNum << " has a balance of $"
            << users[reference].balance <<"\n\n";
            break;
        case 2:
            reference = users[0].startUp(users, limit);
            balance = users[reference].credit();
            std::cout << "\nYour new balance is " << std::fixed <<std::setprecision(2) << balance << "\n";
            break;
        case 3:
            reference = users[0].startUp(users, limit);
            balance = users[reference].debit();
            std::cout << "\nYour new balance is " << std::fixed << std::setprecision(2) << balance << "\n";
            break;

        case 4:
            
            break;
        case 5:
            users[0].printAscID(users, limit);
            break;
        case 6:
            break;
        case 0:
            break;
        default:
            std::cout << "\nPlease enter a number from 0 - 6\n";
        }
    } while (input != 0);
        
}