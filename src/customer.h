#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <QDateTime>
#include <QString>
/***************************************************************
* Name        : Customer
* Author      : Dylan Kennedy
* Created     : 12/01/2020
***************************************************************/
class Customer
{
    private:
        QString m_Name;
        QString m_Appointment;
        int m_Priority;
        QDateTime m_ArivalTime;
        int m_Threshold;


    public:
        Customer(const QString& name, const QString& appointment, const int& priority);
        QString getName();
        QString getAppointment();
        int getPriority();
        void setThreshold(int value);
        QDateTime getArrivalTime();
        QString getBackgroundColor();
        ~Customer();

};

#endif
