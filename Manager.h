#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"
#include <string>
#include <cstdlib>

using namespace std;

class Manager : public Employee  // Manager class derived from Employee class
{
private:
    double bonus;

public:
    // Create a new manager
    Manager(string theName, double theWage, double theHours, double theBonus);

    // Calculating a manager's pay
    double calcPay() const;

};

#endif // MANAGER_H
