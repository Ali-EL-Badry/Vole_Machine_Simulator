#include "CU.h"

#include <cmath>
#include <iostream>

int CU::hexToDec(const char& number){
    if(number - '0' < 10)
        return  number - '0';
    return  number - 'A' + 10;
}

string CU::decToBinary(int number){
    string result;
    for(int i = 0 ; i < 4; i++){
        result = to_string(number % 2) + result;
        number /= 2;
    }
    return result;
}


string CU::hexToBinary(const string& number){
    string result;
    for(int i = 0 ; i < number.length() ;i++){
        int temp = hexToDec(number[i]);
        result += decToBinary(temp);
    }
    return result;
}

int CU::twosComplementToDec(const string& number){
    string binaryNumber = hexToBinary(number);
    int value = 0, length = binaryNumber.length();

    for (int i = 0; i < length; i++)
        value = value * 2 + (binaryNumber[i] - '0');

    value -= (binaryNumber[0]-'0') * int(pow(2, length));

    return value;
}

void CU::loadAtAdress(Memory& memory, Register& reg, const char &addressRegister ,const string& addressMemory){
    int regAddress = hexToDec(addressRegister);
    int memmoryAddressRow = hexToDec(addressMemory[0]);
    int memmoryAddressColmn = hexToDec(addressMemory[1]);

    string bitPattern = memory.get_index(memmoryAddressRow,memmoryAddressColmn);

    if(!bitPattern.empty())
        reg.set_rgstr(regAddress,bitPattern);
}

void CU::loadwith(Register& reg, const char& address, string& value){
    int regAddress = hexToDec(address);

    reg.set_rgstr(regAddress, value);
}

void CU::storeLocation(Memory& memory, Register& reg, const char& addressRegister, const string& addressMemory){
    int regAddress = hexToDec(addressRegister);
    int memmoryAddressRow =  hexToDec(addressMemory[0]);
    int memmoryAddressColmn =  hexToDec(addressMemory[1]);


    string bitPattern = reg.get_rgstr(regAddress);
    if(!bitPattern.empty())
        memory.set_nstrctions(memmoryAddressRow, memmoryAddressColmn, bitPattern);
}

void CU::storeScreen(Register& reg, const char& addressRegister,vector<string>&screen){
    int regAddress = hexToDec(addressRegister);
    string bitPattern = reg.get_rgstr(regAddress);
    int value = 0;
    for (char ch : bitPattern)
        value = value * 16 + hexToDec(ch);

    screen.push_back(bitPattern.empty() ? to_string(hexToDec('0')) : to_string(value));

}

void CU::moveBits(Register& reg, const char& firstRegisterAddress, const char& secondRegisterAddress){
    int _1stRegAddress_ = hexToDec(firstRegisterAddress);
    int _2ndRegAddress_ = hexToDec(secondRegisterAddress);

    string bitPattern = reg.get_rgstr(_1stRegAddress_);

    if(!bitPattern.empty())
        reg.set_rgstr(_2ndRegAddress_, bitPattern);
}

void CU::jumpToEqualLocation(Register& reg, const string& Address, string& currentPC, int& row, int& column){
    int registerAddress = hexToDec(Address[0]);
    int memoryRow = hexToDec(Address[1]);
    int memoryColumn = hexToDec(Address[2]);

    string registerContent = reg.get_rgstr(registerAddress);

    if(registerContent == reg.get_rgstr(0)){
        string newMemoryAddress = Address.substr(1,2);
         if(memoryColumn==0){
             row=memoryRow-1;column=15;
         }else{

             row = memoryRow; column = memoryColumn-1;
         }


    }
}

void CU::jumpToSmallerLocation(Register& reg, const string& Address, string& currentPC, int& row, int& column){
    int registerAddress = hexToDec(Address[0]);
    int memoryRow = hexToDec(Address[1]);
    int memoryColumn = hexToDec(Address[2]);

    string registerContent = reg.get_rgstr(registerAddress);
    string registerContent0 = reg.get_rgstr(0);

    int _1stRegisterValue_ = twosComplementToDec(registerContent);
    int _2ndRegisterValue_ = twosComplementToDec(registerContent0);

    if(_1stRegisterValue_ > _2ndRegisterValue_){
        string newMemoryAddress = Address.substr(1,2);
        if(memoryColumn==0){
            row=memoryRow-1;column=15;
        }else{

            row = memoryRow; column = memoryColumn-1;
        }

    }
}



