#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "appointmentException.h"

/*********************************************************************
* Name: MainWindow
* Description: Construct MainWindow
* Input: QWidgetParent
* Output: None
*******************************************************************/
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);


    //Custom Model and Delegate
    m_Model = new CustomerListModel();
    m_Delegate = new CustomerListDelegate(ui->appointmentLv);
    ui->appointmentLv->setModel(m_Model);

    // Add Options to Combo box.
    ui->resonForVistCb->addItem("Tire Rotation");
    ui->resonForVistCb->addItem("Tune Up");
    ui->resonForVistCb->addItem("Change Battery");
    ui->resonForVistCb->addItem("Alignment");
    ui->resonForVistCb->addItem("Brake Repair");

    // Validate customer name
    ui->customerNameTb->setMaxLength(50);
    ui->customerNameTb->setValidator(new QRegExpValidator(QRegExp("^([a-zA-Z]{2,}\\s[a-zA-Z]{1,}'?-?[a-zA-Z]{2,}\\s?([a-zA-Z]{1,})?)")));


    // Using custom item delegate to create multi line list widgets.
    ui->appointmentLv->setItemDelegate(m_Delegate);

    //Signals.
    connect(ui->submitBtn, &QPushButton::clicked, this, &MainWindow::addAppointment);
    connect(ui->serveBtn, &QPushButton::clicked, this, &MainWindow::serveCustomer);
    connect(ui->customerNameTb, &QLineEdit::textEdited, this, &MainWindow::checkName);
}

/*********************************************************************
* Name: addAppointment
* Description: Customer to model.
* Input: None
* Output: None
*******************************************************************/
void MainWindow::addAppointment(){
    ui->statusbar->clearMessage();
    QString name = ui->customerNameTb->text();
    QString appointment = ui->resonForVistCb->currentText();
    int priority = ui->prioritySb->value();
    m_Model->addCustomer(name, appointment, priority);
    m_Model->sortCustmers();
    ui->statusbar->showMessage("Added " + name + " to customers");
}


/*********************************************************************
* Name: serverCustomer
* Description: Remove customer from model.
* Input: None
* Output: None
*******************************************************************/
void MainWindow::serveCustomer(){
    ui->statusbar->clearMessage();
    try{
        int index = ui->appointmentLv->currentIndex().row();
        QString message = "Served " + m_Model->removeCustomer(index);
        ui->customersServedLw->addItem(message);
        ui->statusbar->showMessage(message);

    }catch (ModelEmptyException e) {
        ui->statusbar->showMessage(e.what());

    }catch(NoEntrySelected e){
        ui->statusbar->showMessage(e.what());
    }

}

/*******************************************************************
* Name: checkName
* Description: Check that name is filled out.
* Input: None
* Output: None
*******************************************************************/
void MainWindow::checkName(){

    // Acceptable input enable submit button and indicate via background.
    if(ui->customerNameTb->hasAcceptableInput()){
        ui->submitBtn->setEnabled(true);
        ui->customerNameTb->setStyleSheet("background-color:white");
    }

    // Unacceptable input disable submit button and indicate via background
    else{
        ui->submitBtn->setEnabled(false);
        ui->customerNameTb->setStyleSheet("background-color:pink");
    }

}

/*********************************************************************
* Name: ~MainWindow
* Description: Destructor
* Input: None
* Output: None
*******************************************************************/
MainWindow::~MainWindow(){
    delete ui;
    delete m_Delegate;
    delete m_Model;
}
