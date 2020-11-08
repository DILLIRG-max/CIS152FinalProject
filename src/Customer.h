#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <ctime>
#include <fstream>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>

class Customer{

  private:
    std::string m_FirstName;
    std::string m_LastName;
    std::string m_Appointment;
    int m_Prefered;
    time_t m_ArrivalTime;
    friend class boost::serialization::access;
    template <class Archive>

    void serialize(Archive& ar, const unsigned int version){
      ar & m_FirstName;
      ar & m_LastName;
      ar & m_Appointment;
      ar & m_Prefered;
      ar & m_ArrivalTime;
    }

  public:
    Customer(){};
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
