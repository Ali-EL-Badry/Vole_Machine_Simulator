#ifndef MEMORY_H
#define MEMORY_H


#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include<limits>
#include <regex>
using namespace std;


class Memory{
private:
    vector<vector<string>> nstrctions;
public:
    Memory():nstrctions(16, vector<string>(16)){}
    void set_nstrctions(int row,int coloumn ,string &value);
    void clear();
    string& get_index(int row,int coloumn);
    const vector<vector<string>> & get_nstrctions();

};


#endif //MEMORY_H
