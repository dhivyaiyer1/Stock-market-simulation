#pragma once
#include <string>
#include <unordered_map>
#include <utility> 
//#include "Observer.h"

using namespace std;

class Person {
    protected:
    void printInfo();
    unordered_map<string,pair<int,double>*> investments;

    public:
    string name;
    double money;
    int shares;

    Person(string n) : name(n), money(1000), shares(0) {};
    virtual void print();
    bool canBuy(string CompanyName, unsigned int shares, double value);
    bool canSell(string CompanyName, unsigned int shares, double value);
    void buy(string CompanyName, unsigned int shares, double value);
    void sell(string CompanyName, unsigned int shares, double value);
};