#pragma once
#include <string>
#include <unordered_map>

using namespace std;

class Person {
    private:
    double money;
    int shares;
    unordered_map<string,int> investments;
    bool has(string CompanyName);

    public:
    string name;
    Person(string n) : name(n), money(1000), shares(0) {};
    void printInfo();
    void print();
    bool canBuy(unsigned int shares, double value);
    bool canSell(string CompanyName, unsigned int shares);
    void buy(string CompanyName, unsigned int shares, double value);
    void sell(string CompanyName, unsigned int shares, double value);
};