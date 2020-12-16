/**************************************************************
* Name        : Appointment Manager
* Author      : Dylan Kennedy
* Created     : 12/01/2020
* Course      : CIS 161 – C++
* Version     : 1.0
* OS          : Manjaro 20.0.1
* Copyright   : This is my own original work based on
*               specifications issued by our instructor
* Description : A program used for handling customer data for a
*               mechanic.
* Input:  None
* Output: Show the customer data using
*         Data structures graphically.
*
* Academic Honesty: I attest that this is my original work.
* I have not used unauthorized source code, either modified or
* unmodified. I have not given other fellow student(s) access to
* my program.
***************************************************************/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
