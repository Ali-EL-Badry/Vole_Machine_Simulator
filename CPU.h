#ifndef CPU_H
#define CPU_H
#include "Register.h"
#include "Alu.h"
#include "CU.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<limits>
#include <regex>
using namespace std;


// the required elements from the cpu --> IR, PC ,clear cpu
class CPU{
private:

    vector <string> screen;
    string IR ;
    string  PC ;
    Register registers;
    Alu alu;
    CU cu ;

public:

    bool valid(string IR );

    // show the PC ,IR after we finish
    bool fetch(int &row,int &column,const vector<vector<string>>&memo );


    //explain the decode or the meaning of the instruction means what by the cout
    int decode(bool option);

    //execute then show memo, registers
    bool excute(int& row,int& column,int Case,Memory &memo);//we have access to the registers

    // Clear all the value
    void clear();

    //get the value of pc
    string getter_PC();

    // set the value of pc
    void setter_PC(string value);

    // get the value of IR
    string getter_IR();

    // get the value of screen
    vector<string> get_screen();

    // get the value of register
    Register getter_reg();
};



#endif //CPU_H
