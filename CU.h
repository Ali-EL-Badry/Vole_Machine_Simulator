#ifndef CU_H
#define CU_H

#include <string>
#include "Register.h"
#include "Memory.h"
using namespace std;

class CU {

private:
    /**
     * @brief  Convert hexadecimal number to decimal number
     * 
     * @param  number The hexadecimal number
     * 
     * @return The decimal number after being converted
     */
    static int hexToDec(const char& number);

    /**
     * @brief  Convert decimal number to binary number
     *
     * @param  number The decimal number
     *
     * @return The binary number after being converted
     */
    static string decToBinary(int number);

     /**
      * @brief  Convert hexadecimal number to binary number
      *
      * @param  number The hexadecimal number
      *
      * @return The binary number after being converted
      */
    static string hexToBinary(const string& number);
     /**
      * @brief  Convert Hexadecimal twos complement number to Decimal number
      *
      * @param  number The Hexadecimal twos complement number
      *
      * @return The decimal number after being converted
      */
    static int twosComplementToDec(const string& number);

public:
    /**
     * @brief load the register R with the bit pattern found in the memory cell whose address is XY.
     * 
     * @param addressRegister The address of the register.
     * @param addressMemory The address of the memory.
     * @param memory  The memory which contain the value to be loaded.
     * @param reg The register where the content of the memory will be stored.
     */
    static void loadAtAdress(Memory& memory, Register& reg, const char &addressRegister ,const string& addressMemory);

    /**
     * @brief load the register R with the bit pattern found in the memory cell whose address is XY.
     * 
     * @param reg The register where the value will be loaded.
     * @param address The address of the register.
     * @param value The value to be loaded.
     */
    static void loadwith(Register& reg, const char &address, string &value);

    /**
     * @brief Store the content of register R in the memory cell whose address is XY.
     * 
     * @param memory The memory where the content of register will be stored.
     * @param reg The register which contain the value.
     * @param addressRegister The address of the register.
     * @param addressMemory The address of the memory.
     */
    static void storeLocation(Memory& memory, Register& reg, const char &addressRegister ,const string& addressMemory);

    /**
     * @brief  Stores the content of the register R in the address 00 which is the screen.
     *
     * @param reg The register where the content will be stored to the screen.
     * @param addressRegister The address of the register containing the address of the memory location.
     */
    static void storeScreen(Register &reg , const char &addressRegister,vector<string>&screen);
    
    /**
     * @brief  Move the bits of the register R to register S.
     *
     * @param reg The register where the two register belong to.
     * @param firstRegisterAddress The address of the first register.
     * @param secondRegisterAddress The address of the second register
     * 
     */
    static void moveBits(Register &reg, const char &firstRegisterAddress, const char &secondRegisterAddress );

    /**
     * @brief  Jump to the memory location whose address is XY if value of register in address R equals to register in address 0.
     *
     * @param reg The register to check that value of register in address R equals to register in address 0.
     * @param Address The address of the register R.
     * @param currentPC The place where the Program counter is.
     * @param row the index of the row in the memory cells
     * @param column the index of the colmn in the memory cells
     */
    static void jumpToEqualLocation(Register &reg, const string &Address, string& currentPC, int &row , int &column);

    /**
     * @brief  Jump to the memory location whose address is XY if value of register in address R greater than register in address 0.
     *
     * @param reg The register to check that value of register in address R greater than register in address 0.
     * @param Address The address of the register R.
     * @param currentPC The place where the Program counter is.
     * @param row the index of the row in the memory cells
     * @param column the index of the colmn in the memory cells
     */
    static void jumpToSmallerLocation(Register &reg, const string &Address, string& currentPC, int &row , int &column);
};

#endif
