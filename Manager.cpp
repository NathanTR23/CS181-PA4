#include <string>
#include <cstdlib>

using namespace std;

#include "Manager.h"

// Manager constructor initializes name, wage, hours, and bonus for the manager when created
Manager::Manager (string theName, double theWage, double theHours, double theBonus) : Employee(theName, theWage, theHours)
{
    name = theName;
    wage = theWage;
    hours = theHours;
    bonus = theBonus;
}

// Redefined function that calculates a manager's pay by including their bonus
double Manager::calcPay() const
{
    return ((wage * hours) + bonus);
}
