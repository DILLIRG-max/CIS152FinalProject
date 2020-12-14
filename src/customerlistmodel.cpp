#include "customerlistmodel.h"
#include "appointmentException.h"
/*********************************************************************
* Name: CustomerListModel
* Description: Destructor
* Input: QObject parent
* Output: None
*******************************************************************/
CustomerListModel::CustomerListModel(QObject *parent):QAbstractListModel(parent){

}
/*********************************************************************
* Name: rowCount
* Description: Return rowcount of or size.
* Input: QModelIndex index
* Output: Size of container
*******************************************************************/
int CustomerListModel::rowCount(const QModelIndex &index) const{
    Q_UNUSED(index)
    return m_Data.size();
}

/*********************************************************************
* Name: data
* Description: Return value given a role
* Input: QModelIndex index int role
* Output: Qvariant text
*******************************************************************/
QVariant CustomerListModel::data(const QModelIndex& index, int role) const{
    if(index.row() < 0 || index.row() >= m_Data.count())
        return QVariant();

    QVariant text;
    Customer c = m_Data[index.row()];

    if(role == nameRole)
        text = c.getName();

    else if(role == appointmentRole)
        text = c.getAppointment();

    else if(role == priorityRole)
        text = c.getPriority();

    else if(role == arrivalRole)
        text = c.getArrivalTime();
    else if(role == colorRole)
        text = c.getBackgroundColor();

    return text;
}

/*********************************************************************
* Name: addCustomer
* Description: AddCustomer to list
* Input: QString name, QString Appointment, int priority
* Output: Size of container
*******************************************************************/
void CustomerListModel::addCustomer(const QString& name, const QString& appointment, const int& priority){
    beginResetModel();
    m_Data.append(Customer(name, appointment, priority));
    endResetModel();
}
/*********************************************************************
* Name: removeCustomer
* Description: Remove Customer from list
* Input: int index
* Output: QString name
*******************************************************************/
QString CustomerListModel::removeCustomer(const int index){
     QString name;
    if(index>=0 && index<m_Data.count()){
        beginResetModel();
        Customer c = m_Data[index];
        name = c.getName();
        m_Data.removeAt(index);
        endResetModel();

    }else if(index < 0 && m_Data.count() > 0){
        throw NoEntrySelected();
        return "";

    }else{
        throw ModelEmptyException();
        return "";
    }

    return name;
}

/*********************************************************************
* Name: sortCustomers
* Description: Sort Customers Based on their priority
* Input: None
* Output: None
*******************************************************************/
void CustomerListModel::sortCustmers(){
    beginResetModel();
    std::sort(m_Data.begin(), m_Data.end(), compare);
    endResetModel();
}
/*********************************************************************
* Name: compare
* Description: Compare function used for sorting.
* Input: Customer a, Customer b
* Output: Bool
*******************************************************************/
bool CustomerListModel::compare(Customer& a, Customer& b){
    return a.getPriority() > b.getPriority();
}
