#include "Register.h"
void  Register:: set_rgstr(int location,string &value)
{

    rgstr[location]=value;
}

void Register:: clear()
{
    for (int i = 0; i < 16; ++i) {
        rgstr[i]="";
    }
}

string& Register:: get_rgstr(int location)
{

    return rgstr[location];
}

vector<string> Register :: print_rgstr()
{
    return rgstr;
}

