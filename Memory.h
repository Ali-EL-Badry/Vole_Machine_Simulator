#ifndef MEMORY_H
#define MEMORY_H

#include <vector>
#include <string>
using namespace std;


class Memory{
private:
    vector<vector<string>> nstrctions;
public:
    // set the value of memory
    Memory():nstrctions(16, vector<string>(16)){}

    // set the instructions in the memory
    void set_nstrctions(int row,int coloumn ,string &value);

    // Clear all memory
    void clear();

    // Get the value of index
    string& get_index(int row,int coloumn);

    // return all the memory
    const vector<vector<string>> & get_nstrctions();
};


#endif //MEMORY_H
