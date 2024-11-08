#include "Alu.h"
#include <cmath>


int Alu::hexToDec(const char& number){
    if(number - '0' < 10)
        return  number - '0';
    return  number - 'A' + 10;
}

string Alu::decToHex( int number){
    if (number == 0) return "0";
    string result;

    while (number != 0) {
        long long remainder = number % 16;

        if (remainder < 10)
            result = char('0' + remainder) + result;
        else
            result = char('A' + (remainder - 10)) + result;

        number /= 16;
    }

    return result;
}


string Alu::decToBinary(int number){
    string result;
    for(int i = 0 ; i < 4; i++){
        result = to_string(number % 2) + result;
        number /= 2;
    }
    return result;
}


string Alu::hexToBinary(const string& number){
    string result;
    for(int i = 0 ; i < number.length() ;i++){
        int temp = hexToDec(number[i]);
        result += decToBinary(temp);
    }
    return result;
}

int Alu::twosComplementToDec(const string& number){
    string binaryNumber = hexToBinary(number);
    int value = 0, length = binaryNumber.length();

    for (int i = 0; i < length; i++)
        value = value * 2 + (binaryNumber[i] - '0');

    value -= (binaryNumber[0]-'0') * int(pow(2, length));

    return value;
}
int Alu::binToDec(const string &binaryStr) {
    int decimal = 0;
    int base = 1;

    for (int i = binaryStr.length() - 1; i >= 0; --i) {
        int bit = binaryStr[i] - '0';
        decimal += bit * base;
        base *= 2;
    }

    return decimal;
}

double Alu::binToFloat(const string& binaryNumber){
    int sign = binaryNumber[0] - '0';
    string exponent = binaryNumber.substr(1,3);
    string mantissa = binaryNumber.substr(4);

    int exponentValue = binToDec(exponent) - 3;
    double mantissaValue = 1.0;

    for (int i = 0; i < mantissa.size(); ++i){
        if (mantissa[i] == '1')
            mantissaValue += pow(2, - (i + 1));
    }

    double value = mantissaValue * pow(-1,sign) * pow(2, exponentValue);
    return value;
}

string Alu::floatToBin(double& floatValue){
    string result = (floatValue < 0 ? "1" : "0");
    floatValue = abs(floatValue);

    // Change number to binary
    string binaryValue = decToBinary(int(floatValue)) + ".";
    double fractionValue = floatValue - int(floatValue);
    while(fractionValue != 0){
        fractionValue *= 2;

        if(fractionValue >= 1){
            fractionValue -= 1;
            binaryValue += "1";
        }
        else
            binaryValue += "0";
    }

    // Get the value of exponent
    bool check = false;int unbiasedExponent = 0;
    for(int i = 0 ; i < binaryValue.length() ; i++){
        if(binaryValue[i] == '1' && !check){
            check = true;
            continue;
        }

        if(binaryValue[i] == '.')
            break;

        if(check)
            unbiasedExponent++;
    }
    int Exponent = unbiasedExponent + 3;
    result += decToBinary(Exponent);

    // get the mantisa part
    check = false; int counter = 0;
    for(int i = 0 ; i < binaryValue.length() && counter < 4; i++){
        if(binaryValue[i] == '1' && !check){
            check = true;
            continue;
        }

        if(binaryValue[i] == '.')
            continue;

        if(check){
            result += binaryValue[i];
            counter ++;
        }
    }
    for(int i = counter ; i < 4 ; i++)
        result += "0";

    return result;
}


void Alu::addTwosComplement(Register& reg, const string& index){
    int register1 = hexToDec(index[0]);
    int register2 = hexToDec(index[1]);
    int register3 = hexToDec(index[2]);

    string _register2Value_ = reg.get_rgstr(register2);
    string _register3Value_ = reg.get_rgstr(register3);

    int _valueRegister2_ = twosComplementToDec(_register2Value_);
    int _valueRegister3_ = twosComplementToDec(_register3Value_);

    string result = decToHex(_valueRegister2_ + _valueRegister3_);
    if(result.size() != 2)
        result = '0' + result;
    reg.set_rgstr(register1, result);
}


void Alu::addFloatingPoint(Register& reg, const string& index){
    int register1 = hexToDec(index[0]);
    int register2 = hexToDec(index[1]);
    int register3 = hexToDec(index[2]);

    string _register2Value_ = reg.get_rgstr(register2);
    string _register3Value_ = reg.get_rgstr(register3);

    double _valueRegister2_ = binToFloat(hexToBinary(_register2Value_));
    double _valueRegister3_ = binToFloat(hexToBinary(_register3Value_));
    double sum = _valueRegister2_ + _valueRegister3_;

    string result = decToHex(binToDec(floatToBin(sum))) ;
    if(result.size() != 2)
        result = '0' + result;
    reg.set_rgstr(register1, result);
}


void Alu::bitwiseOrRegisters(Register& reg, const string& index){
    int register1 = hexToDec(index[0]);
    int register2 = hexToDec(index[1]);
    int register3 = hexToDec(index[2]);

    string _register2Value_ = reg.get_rgstr(register2);
    string _register3Value_ = reg.get_rgstr(register3);

    int _valueRegister2_ = 0, _valueRegister3_ = 0;

    for (char ch : _register2Value_)
        _valueRegister2_ = _valueRegister2_ * 16 + hexToDec(ch);

    for (char ch : _register3Value_)
        _valueRegister3_ = _valueRegister3_ * 16 + hexToDec(ch);

    string result = decToHex(_valueRegister2_ | _valueRegister3_);

    if(result.size() != 2)
        result = '0' + result;
    reg.set_rgstr(register1, result);
}

void Alu::bitwiseAndRegisters(Register& reg, const string& index){
    int register1 = hexToDec(index[0]);
    int register2 = hexToDec(index[1]);
    int register3 = hexToDec(index[2]);

    string _register2Value_ = reg.get_rgstr(register2);
    string _register3Value_ = reg.get_rgstr(register3);

    int _valueRegister2_ = 0, _valueRegister3_ = 0;

    for (char ch : _register2Value_)
        _valueRegister2_ = _valueRegister2_ * 16 + hexToDec(ch);

    for (char ch : _register3Value_)
        _valueRegister3_ = _valueRegister3_ * 16 + hexToDec(ch);

    string result = decToHex(_valueRegister2_ & _valueRegister3_);
    if(result.size() != 2)
        result = '0' + result;
    reg.set_rgstr(register1, result);
}

void Alu::bitwiseXorRegisters(Register& reg, const string& index){
    int register1 = hexToDec(index[0]);
    int register2 = hexToDec(index[1]);
    int register3 = hexToDec(index[2]);

    string _register2Value_ = reg.get_rgstr(register2);
    string _register3Value_ = reg.get_rgstr(register3);

    int _valueRegister2_ = 0, _valueRegister3_ = 0;

    for (char ch : _register2Value_)
        _valueRegister2_ = _valueRegister2_ * 16 + hexToDec(ch);

    for (char ch : _register3Value_)
        _valueRegister3_ = _valueRegister3_ * 16 + hexToDec(ch);

    string result = decToHex(_valueRegister2_ ^ _valueRegister3_);
    if(result.size() != 2)
        result = '0' + result;
    reg.set_rgstr(register1, result);

}

void Alu::rotateContentRegister(Register& reg, const string& index){
    int rgster = hexToDec(index[0]);
    int x = hexToDec(index[2]);

    string registerValue = reg.get_rgstr(rgster);
    string binaryValue = hexToBinary(registerValue);

    for(int i = 0 ; i < x; i++){
        binaryValue = binaryValue[7] + binaryValue;
        binaryValue.pop_back();
    }
    int DecValue = binToDec(binaryValue);
    string hexValue = decToHex(DecValue);

    reg.set_rgstr(rgster,hexValue);
}