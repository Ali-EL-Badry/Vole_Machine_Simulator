#include "Register.h"

// Set one value in the register
void  Register:: set_rgstr(int location,string &value)
{
    rgstr[location]=value;
}

// Clear the register
void Register:: clear()
{
    for (int i = 0; i < 16; ++i) {
        rgstr[i]="";
    }
}

// Get one value in the register
string& Register:: get_rgstr(int location)
{
    return rgstr[location];
}

// return all the registers
vector<string> Register :: print_rgstr()
{
    return rgstr;
}

