#pragma once
#ifndef APPOINTMENTEXCEPTION_H
#define APPOINTMENTEXCEPTION_H
#include <exception>
struct ModelEmptyException: public std::exception{
    const char* what() const throw(){
        return "There are no Customers!";
    }
};

struct NoEntrySelected: public std::exception{
    const char* what() const throw(){
        return "No customer selected!";
    }
};

#endif // APPOINTMENTEXCEPTION_H
