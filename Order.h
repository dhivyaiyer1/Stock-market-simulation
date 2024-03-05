#pragma once
#include "TestObject.h"

class Person;
class MatchingEngine;

class Order : public TestObject {
    protected:
    Order(std::string orderName,Person* p, int q, bool b);

    public:
    void printInfo();
    std::string orderName;
    bool buy;
    int quantity;
    Person* person;
    virtual void print();
    virtual void debug();
    bool execute(std::string CompanyName, unsigned int shares, double value);
    virtual void action(MatchingEngine& meng) = 0;
};