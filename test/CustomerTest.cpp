#include "../src/Customer.h"
#include <gtest/gtest.h>

TEST(CustomerGettersConstructor, HoldsValues){
  std::string f = "David";
  std::string l = "Smith";
  std::string a = "Repair Tire";

  Customer customer1(f, l, a);
  ASSERT_EQ(customer1.getFirstName(), f);
  ASSERT_EQ(customer1.getLastName(), l);
  ASSERT_EQ(customer1.getAppointment(), a);

}

TEST(CustomerPrecedence, PrecednceTime){
    Customer customer1("David", "Smith", "Repair Tire");
    Customer customer2("Cindy", "Smith", "Repair Tire");
    ASSERT_TRUE(customer1.precedence() < customer2.precedence());
}

TEST(CustomerPrecedence, PrecedencePreferred){
  Customer customer1("David", "Smith", "Repair Tire");
  Customer customer2("Cindy", "Smith", "Repair Tire");
  customer2.setPrefered(1);
  ASSERT_TRUE(customer1.precedence() < customer2.precedence());
}

int main(int argc, char **argv){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
