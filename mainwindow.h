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
    void set_Register();
    void set_memory();

    void on_bttnInsert_clicked();

    void on_pushButton_clicked();

    void set_screen();

    void set_pc();

    void set_IR();

    string decToHex(int number);

    int hexToDec(const char& number);

    void on_bttnDecode_clicked();


    void on_bttnRun_clicked();

private:
    Ui::MainWindow *ui;
    Memory memory;
    CPU cpu;
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
