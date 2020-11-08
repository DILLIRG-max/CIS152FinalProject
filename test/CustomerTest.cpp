#define BOOST_TEST_MODULE appointment_module
#include "../src/Customer.h"
#include <boost/test/unit_test.hpp>
BOOST_AUTO_TEST_SUITE(appointment_suite)

BOOST_AUTO_TEST_CASE(construtor_test){
  std::string firstname = "David";
  std::string lastname = "Smith";
  std::string appointment = "Repair Tire";
  Customer customer(firstname, lastname, appointment);
  BOOST_CHECK_EQUAL(customer.getFirstName(), firstname);
  BOOST_CHECK_EQUAL(customer.getLastName(), lastname);
  BOOST_CHECK_EQUAL(customer.getAppointment(), appointment);

}

BOOST_AUTO_TEST_CASE(test_precedence_time){
  Customer customer1("David", "Smith", "Repair Tire");
  Customer customer2("Cindy", "Smith", "Repair Tire");
  BOOST_CHECK_LT(customer1.precedence(), customer2.precedence());
}

BOOST_AUTO_TEST_CASE(test_precedence_preferrred){
  Customer customer1("David", "Smith", "Repair Tire");
  Customer customer2("Cindy", "Smith", "Repair Tire", 1);
  BOOST_CHECK_LT(customer1.precedence(), customer2.precedence());
}

BOOST_AUTO_TEST_CASE(test_serialization){
  std::string dataFile = "customer.save";
  Customer customer1("David", "Smith", "Repair Tire");
  Customer customer2;

  // Save

  {
    std::ofstream ofs(dataFile, std::ios::binary);
    boost::archive::binary_oarchive oa(ofs);
    oa << customer1;
  }
  // Load
  {
    std::ifstream ifs(dataFile);
    boost::archive::binary_iarchive ia(ifs);
    ia >> customer2;
  }

  BOOST_CHECK_EQUAL(customer1.getFirstName(), customer2.getFirstName());
  BOOST_CHECK_EQUAL(customer1.getLastName(), customer2.getLastName());
  BOOST_CHECK_EQUAL(customer1.getPrefered(), customer2.getPrefered());
  BOOST_CHECK_EQUAL(customer1.getArrivalTime(), customer2.getArrivalTime());
  BOOST_CHECK_EQUAL(customer1.getAppointment(), customer2.getAppointment());


}


BOOST_AUTO_TEST_SUITE_END();
