#pragma once
#include <string>
#include <iostream>

class Person;
class MatchingEngine;

class Order {
    protected:
    void printInfo();

    public:
    std::string orderName;
    bool buy;
    int quantity;
    Person* person;
    Order(std::string orderName,Person* p, int q, bool b);
    virtual void print();
    virtual void add(MatchingEngine& meng) = 0;
    bool execute(std::string CompanyName, unsigned int shares, double value);
};