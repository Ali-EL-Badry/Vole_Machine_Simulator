#include "Memory.h"

void Memory::set_nstrctions(int row,int coloumn ,string &value)
{
    nstrctions[row][coloumn]=value;
}

void Memory:: clear()
{

    for (size_t i = 0; i < 16; ++i) {
        for (size_t j = 0; j < 16; ++j) {
            nstrctions[i][j] = "";
        }
    }
}

string& Memory::get_index(int row ,int coloumn)
{

    return nstrctions[row][coloumn];
}



const vector<vector<string>> & Memory::get_nstrctions(){

    return nstrctions;
}
