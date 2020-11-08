#include "Customer.h"
#include <queue>
#include <fstream>
#include <iostream>
#include <boost/serialization/list.hpp>
#include <boost/serialization/priority_queue.hpp>
using namespace std;

// Display error if usere entered an unknown command.
void commandNotFound(std::string command){
  printf("appointmentmanager: unrecognized option '%s' \nType \
        'appointmentmanager -h for a list of available options.'\n", command.c_str());
}

// Save appointments to file.
void save(list<Customer> overflow, priority_queue<Customer> customers, std::string dataFile){

  // ofstream ofs(dataFile, ios::binary);
  // {
  //   boost::archive::binary_oarchive oa(ofs);
  //   oa << overflow;
  // }

  printf("Saving to %s\n", dataFile.c_str());

}

// Load appointments from file.
void load(list <Customer> &overflow, priority_queue<Customer> &customers, std::string dataFile){
  // {
  //   ifstream ifs(dataFile);
  //   boost::archive::binary_iarchive ia(ifs);
  //   ia >> overflow;
  // }

  printf("Loading %s\n", dataFile.c_str());
}


// Server customer from queue.
void serveCustomer(priority_queue<Customer> &customers, list<Customer> overflow){
  printf("Serving Customer\n");
}

// Print current customers in queue.
void printQueue(priority_queue<Customer> customers){
  printf("Printing queue\n");
}

// Display help menu.
void printHelp(){
    printf("Welcome to Tires R US Appointment Manager\n \
            \nUsage: appointmentmanager [OPTIONS]...\n \
            \nOption       Long option       Purpose\n \
            \n-h           --help            Print this menu\n \
            \n-o           --print_overflow  Print over flow list\n \
            \n-p           --print_current   Print customers in queue\n \
            \n-a           --add_customer    Add customer to list\n  \
            \n-s           --serve           Serve first customer in queue\n \
            \n-w           --write           Write current Appointments to file\n \
            \n-r           --read            Read Appointments from file\n\n");
}

// Add customer to overflow.
void addCustomer(list<Customer> &customers){
  printf("Adding customer\n");
}

// Print overflow customers.
void printOverflow(list<Customer> customerList){
  printf("Printing overflow\n");
}

// Display menu.
int main(int argc, char *argv[]){
  list<Customer> overflow;
  priority_queue<Customer> customers;

  // No arguments given.
  if(argc == 1){
    printf("No arguments given exiting program...\n");

  // Program takes at most 3 arguments.
  }else if(argc <= 3){
    std::string command = argv[1];

    // User wants help.
    if(command == "--help" || command == "-h")
      printHelp();

    // User wants to print overflow
    else if(command== "--print_overflow" || command ==  "-o")
      printOverflow(overflow);

    // User wants to print current queue.
    else if(command == "--print_current" || command=="-p")
      printQueue(customers);

    // User wants to add a customer.
    else if(command == "--add_customer" || command == "-a")
      addCustomer(overflow);

    // User wants to save file.
    else if(command== "--write" || command=="-w" && argc == 3){
      std::string file = argv[2];
      save(overflow, customers, file);
    }

    // User wants to read from file.
    else if(command== "--read" || command == "-r" && argc == 3){
      std::string file = argv[2];
      load(overflow, customers, file);
    }
    // Comand not unrecognized.
    else
      commandNotFound(command);

  // To many arguments given.
  }else printf("Too many arguments given exiting...\n");

  Customer customer1("David", "Hoover", "Return Me");
  Customer customer2("David", "Hoover", "Return me");
  return 0;
}
