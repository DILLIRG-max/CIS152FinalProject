#include "customer.h"

/*********************************************************
 * Name: Customer
 * Description: Constructor
 * Output: None
 * Input: Qstring name, QString appointment, int priority
 *********************************************************/
Customer::Customer(const QString& name, const QString& appointment, const int& priority){

    m_Name = name;
    m_Appointment = appointment;
    m_Priority = priority;
    m_ArivalTime = QDateTime::currentDateTime();

}

/********************************************
* Name: getName
* Description: Return customer's fullname
* Input: None
* Output: QString name.
********************************************/
QString Customer::getName(){
    return this->m_Name;
}

/********************************************
* Name: getAppointment
* Description: Return customer's appointment
* Input: None
* Output: QString appointment.
********************************************/
QString Customer::getAppointment(){
    return this->m_Appointment;
}

/********************************************
* Name: getPriority
* Description: Return customer's priority
* Input: None
* Output: int priority.
********************************************/
int Customer::getPriority(){
    return this->m_Priority;
}

/********************************************
* Name: getArrivalTime
* Description: Return customer's arrivalTime
* Input: None
* Output: QDateTime time.
********************************************/
QDateTime Customer::getArrivalTime(){
    return this->m_ArivalTime;
}


/********************************************
* Name: getBackgroundColor
* Description: Change background color if customer has been
* waing loger than threshold.
* Input: None
* Output: QString color.
********************************************/
QString Customer::getBackgroundColor(){

    qint64 diff = m_ArivalTime.msecsTo(QDateTime::currentDateTime());

    if(diff > THRESHOLD){
        return "pink";
     }

    return "white";
}

/*********************************************************************
* Name: ~Customer
* Description: Destructor
* Input: None
* Output: None
*******************************************************************/
Customer::~Customer(){

}
