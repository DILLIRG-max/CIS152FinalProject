#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <ctime>

class Customer{

  private:
    std::string m_FirstName;
    std::string m_LastName;
    std::string m_Appointment;
    int m_Prefered;
    time_t m_ArrivalTime;

  public:
    Customer(std::string f, std::string l, std::string a);
    Customer(std::string f, std::string l, std::string a, int p);
    std::string getFirstName();
    std::string getLastName();
    std::string getAppointment();
    int getPrefered();
    int precedence();
    void setPrefered(int value);
    std::string getArrivalTime();
    ~Customer(){};
};

#endif
