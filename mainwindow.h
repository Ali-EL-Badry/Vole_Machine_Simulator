#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QItemDelegate>
#include <QLineEdit>
#include <QRegularExpression>
#include <QRegularExpressionValidator>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QBrush>
#include <QColor>
#include "Register.h"
#include "Memory.h"
#include "CPU.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    // to print the value of register
    void set_Register();

    // to print the value of memory
    void set_memory();

    // to insert the file to program
    void on_bttnInsert_clicked();

    // to clear the screen
    void on_pushButton_clicked();

    // to print the value of screen
    void set_screen();

    // to print the value of Pc
    void set_pc();

    // to print the value of IR
    void set_IR();

    // to change from dec to hex
    string decToHex(int number);

    // to change the value from hex to decimal
    int hexToDec(const char& number);

    // to run on cycle
    void on_bttnDecode_clicked();

    // to run all the program
    void on_bttnRun_clicked();

private:
    Ui::MainWindow *ui;
    Memory memory;
    CPU cpu;
    // Decode
    map<char,string>Instructions{
        {'1'," LOAD the register R with the bit pattern found in the memory cell whose address is XY."}

        ,{'2'," LOAD the register R with the bit pattern XY."},

        {'3'," STORE the bit pattern found in register R in the memory cell whose address is XY."},

        {'o',"STORE to location 00,which is a memory mapping for the screen.Writing to 00 is writing to screen."}

        ,{'4'," MOVE the bit pattern found in register R to register S."},

        {'5'," ADD the bit patterns in registers S and T as though they were two’s complement representations and leave the result in register R."}

        ,{'6'," ADD the bit patterns in registers S and T as though they represented values in floating-point notation and leave the floating - point result in register R. "},

        {'7'," Bitwise OR the content of the registers S and T and put the result in register R . "},

        {'8'," Bitwise AND the content of the registers S and T and put the result in register R . "},

        {'9'," Bitwise XOR the content of the registers S and T and put the result in register R . "},

        {'A'," Rotate the content of the register R cyclically right X steps . "},

        {'B'," JUMP to the instruction located in the memory cell at address XY if the bit pattern in register R is equal to the bit pattern in register number 0.Otherwise,continue with the normal sequence of execution."},

        {'D'," JUMP to the instruction located in the memory cell at address XY if the bit pattern in register R is greater than the bit pattern in register number 0.Otherwise,continue with the normal sequence of execution. "},

        {'C',"HALT execution."}
    };
};



#endif // MAINWINDOW_H
