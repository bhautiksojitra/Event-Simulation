#include <iostream>
#include "Burst.h"
#include "ListItem.h"
using namespace std;

Burst::Burst(int theValue)
{
    valueOfburst = theValue;
}

// change it
int Burst::compareTo(ListItem *other)
{
    return 0;
}

void Burst::print()
{
    cout << valueOfburst << endl;
}

int Burst::getIntValue()
{
    return valueOfburst;
}

void Burst::setIntValue(int newValue)
{
    valueOfburst = newValue;
}