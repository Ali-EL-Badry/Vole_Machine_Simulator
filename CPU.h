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
    // 1 -> cu // 2->alu // 3->c000
    int decode(bool option);//done // 0 --> step by step
    // 1--> whole program


    //execute then show memo, registers
    bool excute(int& row,int& column,int Case,Memory &memo);//we have access to the registers
    //if zero continue , else stop


    void clear();//done

    string getter_PC();//done

    void setter_PC(string value);

    string getter_IR();//done

    vector<string> get_screen();//done

    Register getter_reg();
};



#endif //CPU_H
