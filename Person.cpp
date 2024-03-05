#include "Person.h"

bool Person::has(std::string CompanyName)
{
    return investments.find(CompanyName) != investments.end();
}

void Person::printInfo() {
    std::cout<<name<<"\n";
    std::cout<<"$"<<money<<"\n";
    for (const auto& [key, value] : investments)
    {
        std::cout<<key<<": "<<value<<"\n";
    }
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

bool Person::canSell(std::string CompanyName, unsigned int shares)
{
    return has(CompanyName) && investments[CompanyName] >= shares;
}

void Person::buy(std::string CompanyName, unsigned int shares, double value)
{
    if (has(CompanyName))
    {
        investments[CompanyName] += shares;
    }
    else
    {
        investments[CompanyName] = shares;
    }
    money -= shares*value;
}

void Person::sell(std::string CompanyName, unsigned int shares, double value)
{
    investments[CompanyName] -= shares;
    money += shares*value;
}

void Person::debug()
{
    std::cout<<name<<"\n";
    std::cout<<"$"<<money<<"\n";
    for (const auto& [key, value] : investments)
    {
        std::cout<<key<<": "<<value<<"\n";
    }
}