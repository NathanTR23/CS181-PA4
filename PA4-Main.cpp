/*
# Author:               Nathan Ryan
# BannerID:             001389707
# Course:               CS 181
# Assignment:           PA4
# Date Assigned:        Monday, March 18, 2024
# Date/Time Due:        Saturday, March 30, 2024 -- 11:55 pm

# Description:          This program will exercise Object
                        Oriented concepts with C++.

# Certification of Authenticity:
    I certify that this assignment is entirely my own work.

    This program uses a manager class derived from an employee class to calculate the highest paid manager and
average pay of a number of managers based on user input. The user is prompted to enter the number of managers,
then the name, hourly pay, hours worked, and bonus for each manager.

*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Manager.h"

using namespace std;

int main()
{
    int managers;
    string managerName, managerFirstName, managerLastName;
    double hourlyWage;
    int hoursWorked;
    double bonusAmount;
    double maxPay = 0;
    string maxPayName;
    double totalPay = 0;
    int i, j;

    // Get number of managers from user
    cout << "Enter number of managers: ";
    cin >> managers;
    cout << endl;

    // This line declares an array of pointers to manager objects with a size of the number of managers
    Manager* ptrArray[managers];

    // Loop for each manager
    for (i = 0; i < managers; i++)
    {
        // User prompted to enter information for each manager
        cout << "Enter manager " << i << " name: ";
        cin >> managerFirstName >> managerLastName;  // Name is read by 2 separate variables to account for the space between first and last name
        cout << "Enter manager " << i << " hourly wage: ";
        cin >> hourlyWage;
        cout << "Enter manager " << i << " hours worked: ";
        cin >> hoursWorked;
        cout << "Enter manager " << i << " bonus: ";
        cin >> bonusAmount;
        cout << endl;

        // The manager name is combined into one variable for simplicity
        managerName = managerFirstName + " " + managerLastName;

        // Manager object created in the array for the specific manager with their data
        ptrArray[i] = new Manager(managerName, hourlyWage, hoursWorked, bonusAmount);
    }

    // Iterating over the array of manager objects
    for (j = 0; j < managers; j++)
    {
        // This if statement determines which manager was paid the highest by setting
        // the maxPay and maxPayName variables to the manager with the highest pay
        if (ptrArray[j]->calcPay() > maxPay)
        {
            maxPay = ptrArray[j]->calcPay();
            maxPayName = ptrArray[j]->getName();
        }

        // The total pay from all the managers is calculated
        totalPay = totalPay + ptrArray[j]->calcPay();
    }

    // Setting all dollar outputs to 2 decimal places
    cout << fixed << setprecision(2);
    // Highest paid manager and their pay is outputted
    cout << "Highest paid manager is " << maxPayName << " who is paid $" << maxPay;
    // The average pay of all managers is outputted
    cout << "\nAverage pay is $" << (totalPay / managers);
    cout << endl;

    return 0;
}
