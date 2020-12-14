#include "customerlistdelegate.h"

/*********************************************************************
* Name: CustomerListDelegate
* Description: Constructor
* Input: QObject* parent
* Output: None
*******************************************************************/
CustomerListDelegate::CustomerListDelegate(QObject* parent): QAbstractItemDelegate(parent){

}

/*********************************************************************
* Name: paint
* Description: Determine style options for given object
* Input: QPainter* painter, QStyleOptionViewItem &option, QModelIndex
* Output: None
*******************************************************************/
void CustomerListDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const{

    QRect r = option.rect;
    int space = 10;

    QPen fontPen(QColor::fromRgb(51,51,51), 1, Qt::SolidLine);

    //If list item currently selected
    if(option.state & QStyle::State_Selected){
        painter->setBrush(Qt::cyan);
        painter->drawRect(r);

    //List Item not selected chose background color based on role.
    }else{
        QString color = index.data(CustomerListModel::customerRoles::colorRole).toString();
        painter->setBrush(QColor(color));
        painter->drawRect(r);
    }

    // Draw Text
    painter->setPen(fontPen);

    //Get customerName and appointment info
    QString customerName = index.data(CustomerListModel::customerRoles::nameRole).toString();
    QString appointmentInfo = index.data(CustomerListModel::customerRoles::appointmentRole).toString();
    appointmentInfo = appointmentInfo + " Priority: " + index.data(CustomerListModel::customerRoles::priorityRole).toString();
    appointmentInfo = appointmentInfo + " " + index.data(CustomerListModel::customerRoles::arrivalRole).toString();

    //Customer Name
    r = option.rect.adjusted(space, 0, -10, -30);
    painter->setFont( QFont( "Lucida Grande", 18, QFont::Normal ) );
    painter->drawText(r.left(), r.top(), r.width(), r.height(), Qt::AlignBottom|Qt::AlignLeft, customerName, &r);

    //Appointment Info
    r = option.rect.adjusted(space, 30, -10, 0);
    painter->setFont( QFont( "Lucida Grande", 9, QFont::Normal ) );
    painter->drawText(r.left(), r.top(), r.width(), r.height(), Qt::AlignLeft, appointmentInfo, &r);

}
/*********************************************************************
* Name: sizeHint
* Description: return size of ListIytem
* Input: QStyleOptionView& option QModelIndex& index
* Output: QSize
*******************************************************************/
QSize CustomerListDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const{
    Q_UNUSED(option);
    Q_UNUSED(index);
    return QSize(500, 60);
}

/*********************************************************************
* Name: ~CustomerListDelegate
* Description: Destructor
* Input: None
* Output: None
*******************************************************************/
CustomerListDelegate::~CustomerListDelegate(){

}
