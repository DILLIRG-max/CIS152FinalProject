/***************************************************************
* Name        : CustomerListModel
* Author      : Dylan Kennedy
* Created     : 10/18/2020
***************************************************************/
#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "customerlistdelegate.h"
#include <QTimer>
#include <QDialog>
#include "customerlistmodel.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    private:
        Ui::MainWindow *ui;
        CustomerListModel* m_Model;
        CustomerListDelegate* m_Delegate;
    private slots:
        void addAppointment();
        void serveCustomer();
        void checkName();
    public:
        MainWindow(QWidget *parent = nullptr);
        ~MainWindow();


};
#endif
