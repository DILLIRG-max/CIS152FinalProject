/***************************************************************
* Name        : CustomerListModel
* Author      : Dylan Kennedy
* Created     : 10/18/2020
***************************************************************/
#pragma once
#ifndef CUSTOMERLIST_H
#define CUSTOMERLIST_H
#include <QAbstractListModel>
#include <QList>
#include "customer.h"

class CustomerListModel : public QAbstractListModel{

    Q_OBJECT
    private:
        QList<Customer> m_Data;
        static bool compare(Customer& a, Customer& b);
    public:
        explicit CustomerListModel(QObject* parent = 0);
        enum customerRoles{nameRole= Qt::UserRole + 220, appointmentRole, priorityRole, arrivalRole, colorRole};
        int rowCount(const QModelIndex& index) const;
        QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;
        void addCustomer(const QString& name, const QString& appointment, const int& priority);
        QString removeCustomer(const int index);
        void sortCustmers();
        ~CustomerListModel(){};


};

#endif // CUSTOMERLIST_H
