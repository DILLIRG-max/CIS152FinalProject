#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <QDateTime>
#include <QString>
#include <QColor>
/***************************************************************
* Name        : Customer
* Author      : Dylan Kennedy
* Created     : 12/01/2020
***************************************************************/
const int THRESHOLD = 6000;
class Customer
{
    private:
        QString m_Name;
        QString m_Appointment;
        int m_Priority;
        QDateTime m_ArivalTime;


    public:
        Customer(const QString& name, const QString& appointment, const int& priority);
        QString getName();
        QString getAppointment();
        int getPriority();
        QDateTime getArrivalTime();
        QString getBackgroundColor();
        ~Customer();

};

#endif
