#include "CPU.h"


//done
void CPU::clear() {
    IR.clear();
    PC.clear();
    registers.clear();
    screen.clear();

}


//done ~
bool CPU ::fetch(int& row,int& column,const vector<vector<string>>&memo) {

    string ir,pc,rows,columns;

     if(row>9){
         rows='A'+row-10;
     }else{
         rows=to_string(row);
     }
     if(column>9){
         columns='A'+column-10;
     }else{
         columns=to_string(column);
     }

     if(!(row>=16||column>=16)) { PC = rows+columns; }
     else {return false;}


    if(!(row>=16||column>=16)) { ir += memo[row][column]; }
    else {return false;}

    if(column+1<16){

        column++;
        ir+=memo[row][column];

    }else{

        row++;
        if(row<16)
        {
            column=0;
            ir+=memo[row][column];
        }else{
            return false;
        }

    }

    IR=ir;
    return true;
}

//done
bool CPU ::valid(std::string ir) {

    string part;
    if(ir.size()!=4)
        return false;

    if(ir[0]=='1'||ir[0]=='2'||ir[0]=='3'||ir[0]=='B'||ir[0]=='5'||ir[0]=='6'||ir[0]=='D'||ir[0]=='9'||ir[0]=='8'||ir[0]=='7'){


      part=ir.substr(1,3);
        if(!regex_match( part, regex("[0-9A-F]{3}") ) ){
            return false;
        }

    }else if(ir[0]=='C'){

        if(ir!="C000")
            return false;

    }else if(ir[0]=='4'){

        if(ir[1]!='0')
            return false;
        part=ir.substr(2);
        if(!regex_match( part, regex("[0-9A-F]{2}") ) ){
            return false;
        }

    }else if(ir[0]=='A'){
        if(ir[2]!='0')
            return false;
        //part=ir[1]+ir[3];
        string part1;string part2;
        part1=ir[1]; part2=ir[3];
        part=part1+part2;
        if(!regex_match( part, regex("[0-9A-F]{2}") ) ){
            return false;
        }

    }else
        return false;


    return true;
}

//done
int CPU  ::decode(bool option) {




    if(IR[0]=='1'||IR[0]=='2'||IR[0]=='3'||IR[0]=='4'||IR[0]=='B'||IR[0]=='D'){
        return 1;
    }
    else if( IR[0]=='5'||IR[0]=='6'||IR[0]=='7'||IR[0]=='8'||IR[0]=='9'||IR[0]=='A'){
        return 2;
    }else {
        int returnValue = 3;
        return returnValue;
    }




}

//done
bool CPU::excute(int& row,int& column,int Case, Memory &memo) {

    if(Case==3){//halt
        return 1;
    }

    vector<char>translation{IR[1],IR[2],IR[3]};
    string  s;

    if(Case==1){
        //cu


        string part1,part2;
        part1=translation[1];part2=translation[2];
        s=part1+part2;
        string part3; part3=translation[0];

        if(IR[0]=='1'){

            CU:: loadAtAdress( memo, registers,translation[0] ,s);

        }else if( IR[0]=='2'){

            CU :: loadwith(registers, translation[0], s);

        }else if(IR[0]=='3'){

            if(translation[1]=='0' && translation[2]=='0')
               CU:: storeScreen(registers, translation[0],screen);
            else
                CU:: storeLocation(memo, registers, translation[0],s);

        }else if(IR[0]=='4'){
            CU:: moveBits(registers, translation[1], translation[2]);
        }else if(IR[0]=='B'){

           s=part3+part1+part2;
           CU:: jumpToEqualLocation(registers , s, PC ,row,column);

        }else{

            s=part3+part1+part2;
            CU::jumpToSmallerLocation(registers,s,PC,row,column);
        }

    }
    else{
   string part3,part1,part2;part3=translation[0];
        part1=translation[1];part2=translation[2];

        s=part3+part1+part2;
        if(IR[0]=='5'){
           Alu:: addTwosComplement(registers, s);
        }else if(IR[0]=='6'){
            Alu :: addFloatingPoint(registers, s);
        }else if(IR[0]=='7'){
            Alu::bitwiseOrRegisters(registers,s);
        }else if(IR[0]=='8'){
            Alu::bitwiseAndRegisters(registers,s);
        }else if(IR[0]=='9'){
            Alu::bitwiseXorRegisters(registers,s);
        }else{
            Alu::rotateContentRegister(registers,s);
        }

    }


    return 0;
}

//done
string CPU :: getter_PC(){
    return PC;
}

//done
string  CPU:: getter_IR(){
    return IR;
}

//done
vector<string> CPU ::get_screen() {
    return screen;
}

void CPU::setter_PC(string value){
    this->PC = value;
}

Register CPU::getter_reg(){
    return this->registers;
};
