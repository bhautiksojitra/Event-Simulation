#pragma once
#include "ListItem.h"

class Burst : public ListItem
{
private:
    int valueOfburst;

public:
    Burst(int);
    int compareTo(ListItem *);
    int getIntValue();
    void setIntValue(int);
    
};