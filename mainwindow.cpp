#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QBrush>
#include <QColor>
#include <QHeaderView>
#include <QFont>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QInputDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Memory->setStyleSheet(
        "QHeaderView::section {"
        "  background-color : #2a2e30; color: #3498db;"     // Text color for headers
        "}"
        "QTableCornerButton::section {"
        "   background-color: #2a2e30;;"
        "   border: none;"
        "}"
        );
    ui->Register->setStyleSheet(
        "QTableCornerButton::section {"
        "   background-color: #2a2e30;;"
        "   border: none;"
        "}"
        "QHeaderView::section {"
        "  background-color : #2a2e30; color: #3498db;"     // Text color for headers
        "}"
        );
    // Set the main window background color and text color
    this->setStyleSheet("background-color: #2a2e30; color: #3498db;");

    // Set the header background color and text color for tables
    ui->Memory->horizontalHeader()->setStyleSheet("background-color: #2a2e30; color: #3498db;");
    ui->Register->horizontalHeader()->setStyleSheet("background-color: #2a2e30; color: #3498db;");

    // Function to apply alternating row colors
    const QColor colorOdd("#3498db");  // Dark gray for odd rows
    const QColor colorEven("#2a2e30");  // Pink for even rows

    set_Register();
    set_memory();
    set_screen();
    set_pc();
    set_IR();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::set_memory(){
    vector<vector<string>> memo = memory.get_nstrctions();
    for(int i = 0 ; i < 16 ; i++){
        for(int j = 0 ; j < 16 ; j++){
            QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(memo[i][j].empty() ? "00" : memo[i][j]));
            item->setTextAlignment(Qt::AlignCenter);
            ui->Memory->setItem(i, j, item);
        }
    }
}

void MainWindow::set_Register() {
    vector<string> values = cpu.getter_reg().print_rgstr();
    for (int j = 0; j < 16; ++j) {
        QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(values[j].empty() ? "00" : values[j]));
        item->setTextAlignment(Qt::AlignCenter);
        ui->Register->setItem(j, 0, item);
    }
}


void MainWindow::on_bttnInsert_clicked(){
    bool ok;
    QString place1 = QInputDialog::getText(this, "Input Parameter", "Enter your parameter:", QLineEdit::Normal, "", &ok);
    string place = place1.toStdString();
    if(!ok)
        return;
    while ((place == "00" ||  (  place.size() != 2   || !regex_match(place, regex("[0-9A-F]{2}") ) ))) {
        place1 = QInputDialog::getText(this, "Wrong PC", "Enter your PC:", QLineEdit::Normal, "", &ok);
        place = place1.toStdString();
        if(!ok)
            return;
    }
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", "", "Text Files (*.txt);;All Files (*)");
    bool first = true;
    int  row,column;

    if (!fileName.isEmpty()) {
        QFile file(fileName);

        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            string s;
            while (!in.atEnd()) {
                QString word;
                in >> word;
                s = word.toStdString();
                if(!cpu.valid(s)){
                    QMessageBox::warning(this, "Error", "The file contains wrong instructions !!Try again!");
                    memory.clear();
                    return;
                }
                string part1;
                part1=s.substr(0,2);
                string part2;
                part2=s.substr(2,2);

                if (first) {
                    string  r,c;
                    r=place[0]; c=place[1];

                    if(isdigit(place[0])){
                        row=stoi(r);
                    }else{
                        row=place[0]-'A'+10;
                    }

                    if(isdigit(place[1])){
                        column=stoi(c);
                    }else{
                        column=place[1]-'A'+10;
                    }

                    memory.set_nstrctions(row,column,part1);

                    if(column+1<16) {
                        column++;
                    }else if (column+1>=16) {
                        if(row+1>=16) {
                            QMessageBox::warning(this, "Error", "The space is insufficient ! Try again !! ");
                            memory.clear();
                            return;
                        }
                        row++;
                        column = 0;
                    }

                    memory.set_nstrctions(row,column,part2);
                    first= false;
                }else{

                    if(column+1<16) {
                        column++;
                    }else if (column+1>=16) {
                        if(row+1>=16) {
                            QMessageBox::warning(this, "Error", "The space is insufficient ! Try again !! ");
                            memory.clear();
                            return;
                        }
                        row++;
                        column = 0;
                    }

                    memory.set_nstrctions(row,column,part1);

                    if(column+1<16) {
                        column++;
                    }else if (column+1>=16) {
                        if(row+1>=16)
                        {
                            QMessageBox::warning(this, "Error", "The space is insufficient ! Try again !! ");
                            memory.clear();
                            return ;
                        }
                        row++;
                        column = 0;
                    }
                    memory.set_nstrctions(row,column,part2);
                }

            }
            if(s!="C000"){

                if(!(column+2>=16&&row+1>=16)) {

                    if (column + 1 >= 16) {
                        row++;
                        column = 0;
                    } else
                        column++;

                    string part = "C0";
                    memory.set_nstrctions(row, column, part);

                    if (column + 1 >= 16) {
                        row++;
                        column = 0;
                    } else
                        column++;
                    part="00";
                    memory.set_nstrctions(row, column, part);
                }
            }

            file.close();
        } else {
            QMessageBox::warning(this, "Error", "Could not open the file.");
        }
    }
    set_memory();
    cpu.setter_PC(place);
    set_pc();
}


void MainWindow::on_pushButton_clicked(){
    cpu.clear();
    memory.clear();
    set_memory();
    set_Register();
    set_screen();
    set_pc();
    set_IR();
    QMessageBox::information(this, "All Clean", "Everything is completed and cleaned up!");
}


void MainWindow::set_screen(){
    vector<string> screen = cpu.get_screen();
    QString vectorText;

    for (auto val : screen) {
        vectorText.append(QChar(stoi(val)));
    }

    // Set the converted text to the QTextEdit widget
    ui->screen->setText(vectorText.isEmpty() ? "There is nothing here" : vectorText);
}


void MainWindow::set_pc(){
    ui->PC->setText(QString::fromStdString(cpu.getter_PC().empty()? "00" : cpu.getter_PC()));
}

void MainWindow::set_IR(){
    ui->IR->setText(QString::fromStdString(cpu.getter_IR().empty() ? "0000" : cpu.getter_IR()));
}


int MainWindow::hexToDec(const char& number){
    if(number - '0' < 10)
        return  number - '0';
    return  number - 'A' + 10;
}

string MainWindow::decToHex(int number){
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


void MainWindow::on_bttnDecode_clicked(){
    bool isvalid, isHalt= false;int Case;
    int i = hexToDec(cpu.getter_PC()[0]), j = hexToDec(cpu.getter_PC()[1]);

    isvalid=cpu.fetch(i,j,memory.get_nstrctions());
    Case=cpu.decode(0);
    isHalt=cpu.excute(i,j,Case,memory);

    string result;
    set_Register();
    set_memory();
    set_screen();
    set_pc();
    set_IR();

    char value = cpu.getter_IR()[0];
    if(value == '3'){
        if(cpu.getter_IR()[2]=='0'&&cpu.getter_IR()[3]=='0'){
            result = Instructions[value];
        }else
            result = Instructions['o'];
    }
    else{
        result = Instructions[value];
    }

    ui->Decode->setText(QString::fromStdString(result));

    if(isHalt){
        return;
        }

    if(j+1<16){
        j++;
        cpu.setter_PC(decToHex(i) + decToHex(j));

    }else{
        i++;
        if(i<16){
            j=0;
            cpu.setter_PC(decToHex(i) + decToHex(j));            ;
        }
        else
            return;
    }
}



void MainWindow::on_bttnRun_clicked(){
    bool isvalid, isHalt= false;int Case;
    for (int i = 0; i < 16 ; ++i) {
        for (int j = 0; j < 16; ++j) {

            if(!memory.get_index(i,j).empty()){

                isvalid=cpu.fetch(i,j,memory.get_nstrctions());
                Case=cpu.decode(1);
                isHalt=cpu.excute(i,j,Case,memory);



                if(isHalt){
                    set_Register();
                    set_memory();
                    set_screen();
                    set_pc();
                    set_IR();
                    return;
                }
            }

        }

    }

}

