#include <QtTest>
#include <QThread>
#include "../src/customer.h"
#include "../src/customerlistmodel.h"
#include "../src/appointmentException.h"

class AppointmentManagerTest : public QObject{
    Q_OBJECT
private:
    QString m_Name = "Dylan";
    QString m_Appointment = "Repair Tire";
    QString m_ShortWaitTime = "white";
    QString m_LongWaitTime = "pink";
    int m_Priority = 5;
    Customer* m_Customer = nullptr;
    CustomerListModel* m_Model = nullptr;


public:
    AppointmentManagerTest();
    ~AppointmentManagerTest();

private slots:
    void customerHoldsData();
    void customerNoBackgroundChange();
    void customerBackgroundChange();
    void modelAddCustomer();
    void modelEmptyException();
    void modelNoEntryException();
};

AppointmentManagerTest::AppointmentManagerTest(){
    m_Customer = new Customer(m_Name, m_Appointment, m_Priority);
    m_Model = new CustomerListModel;
}

AppointmentManagerTest::~AppointmentManagerTest(){
    delete m_Customer;
    delete m_Model;
}

void AppointmentManagerTest::customerHoldsData(){

    QVERIFY(m_Customer->getName() == m_Name);
    QVERIFY(m_Customer->getAppointment() == m_Appointment);
    QVERIFY(m_Customer->getPriority() == m_Priority);

}

void AppointmentManagerTest::customerNoBackgroundChange(){
    QThread::sleep(6);
    QVERIFY(m_Customer->getBackgroundColor() == m_ShortWaitTime);
}

void AppointmentManagerTest::customerBackgroundChange(){
    m_Customer->setThreshold(5);
    QThread::sleep(6);
    QVERIFY(m_Customer->getBackgroundColor() == m_LongWaitTime);
}

void AppointmentManagerTest::modelAddCustomer(){
    m_Model->addCustomer(m_Name, m_Appointment, m_Priority);
    QVERIFY(m_Customer->getName() == m_Model->removeCustomer(0));
}

void AppointmentManagerTest::modelEmptyException(){
    QVERIFY_EXCEPTION_THROWN(m_Model->removeCustomer(0), ModelEmptyException);
}

void AppointmentManagerTest::modelNoEntryException(){
    m_Model->addCustomer(m_Name, m_Appointment, m_Priority);
    QVERIFY_EXCEPTION_THROWN(m_Model->removeCustomer(1), NoEntrySelected);
}

QTEST_APPLESS_MAIN(AppointmentManagerTest)

#include "tst_appointmentmanagertest.moc"
