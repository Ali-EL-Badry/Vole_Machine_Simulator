#ifndef REGISTER_H
#define REGISTER_H
#include <vector>
#include <string>
using namespace std;


class Register{
private:
    vector<string> rgstr;
public:
    // set the intial value of register
    Register():rgstr(16){};

    // set one value in the regiser
    void set_rgstr(int location,string &value);

    // Clear the register
    void clear();

    // get one register value
    string& get_rgstr(int location);

    // return all the registers
    vector<string> print_rgstr();
};



#endif //REGISTER_H
