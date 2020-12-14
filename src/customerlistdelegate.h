/***************************************************************
* Name        : CustomerListDelegate
* Author      : Dylan Kennedy
* Created     : 12/01/2020
***************************************************************/
#pragma once
#ifndef APPOINTMENTLISTDELEGATE_H
#define APPOINTMENTLISTDELEGATE_H
#include <customerlistmodel.h>
#include <QPainter>
#include <QAbstractItemDelegate>

class CustomerListDelegate :public QAbstractItemDelegate{

    public:
        CustomerListDelegate(QObject* parent = 0);
        void paint ( QPainter* painter, const QStyleOptionViewItem & option, const QModelIndex & index ) const;
        QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
        ~CustomerListDelegate();
};

#endif
