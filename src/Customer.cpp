#include "Customer.h"

Customer::Customer(std::string f, std::string l, std::string a){
  m_FirstName = f;
  m_LastName = l;
  m_Appointment = a;
  m_ArrivalTime = time(0);
}

std::string Customer::getFirstName(){
  return this->m_FirstName;
}

std::string Customer::getLastName(){
  return this->m_LastName;
}

std::string Customer::getAppointment(){
  return this->m_Appointment;
}

int Customer::getPrefered(){
  return this->m_Prefered;
}

void Customer::setPrefered(int value){
  m_Prefered = value;
}

std::string Customer::getArrivalTime(){
    return ctime(&m_ArrivalTime);
}

int Customer::precedence(){
  return this->m_ArrivalTime + m_Prefered;
}
