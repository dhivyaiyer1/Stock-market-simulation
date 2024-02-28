#pragma once
#include <string>
#include <iostream>

class Person;

class Order {
    protected:
    void printInfo();
    std::string orderName;
    bool buy;
    int quantity;
    Person* person;
    Order(std::string orderName,Person* p, int q, bool b);
    virtual void print();
    bool execute(std::string CompanyName, unsigned int shares, double value);
};