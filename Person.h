#pragma once
#include <unordered_map>
#include "TestObject.h"

class Person : public TestObject {
    private:
    double money;
    std::unordered_map<std::string,int> investments;
    bool has(std::string CompanyName);

    public:
    std::string name;
    Person(std::string n) : name(n), money(1000) {};
    void printInfo();
    void print();
    void debug();
    bool canBuy(unsigned int shares, double value);
    bool canSell(std::string CompanyName, unsigned int shares);
    void buy(std::string CompanyName, unsigned int shares, double value);
    void sell(std::string CompanyName, unsigned int shares, double value);
};