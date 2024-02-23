#include "Person.h"
#include <iostream>

~Person()
{
    for (const auto& [key,pair] : investments)
    {
        delete pair;
    }
}

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

bool Person::canSell(string CompanyName, unsigned int shares, double value)
{
    return investments.contains(CompanyName) && investments[CompanyName]->first >= shares;
}

void Person::buy(string CompanyName, unsigned int shares, double value)
{
    if (investments.contains(CompanyName))
    {
        investments[CompanyName]->first += shares;
        investments[CompanyName]->second = value;
    }
    else
    {
        investments[CompanyName] = new Pair<int,double> (shares,value);
    }
    money -= shares*value;
}

void Person::sell(string CompanyName, unsigned int shares, double value)
{
    investments[CompanyName]->first -= shares;
    investments[CompanyName]->second = value;
    money += shares*value;
}