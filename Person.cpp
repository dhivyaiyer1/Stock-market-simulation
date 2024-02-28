#include "Person.h"
#include <iostream>

void Person::printInfo() {
    std::cout<<name<<"\n";
    std::cout<<"$"<<money<<"\n";
    std::cout<<"Shares: "<<shares<<"\n";
}

void Person::print()
{
    printInfo();
    std::cout<<"\n";
}

bool Person::canBuy(unsigned int shares, double value)
{
    return money >= shares*value;
}

bool Person::canSell(string CompanyName, unsigned int shares)
{
    return investments.contains(CompanyName) && investments[CompanyName]->first >= shares;
}

void Person::buy(string CompanyName, unsigned int shares, double value)
{
    if (investments.contains(CompanyName))
    {
        investments[CompanyName]->first += shares;
    }
    else
    {
        investments[CompanyName] = shares;
    }
    money -= shares*value;
}

void Person::sell(string CompanyName, unsigned int shares, double value)
{
    investments[CompanyName]->first -= shares;
    money += shares*value;
}