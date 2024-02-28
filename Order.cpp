#include "Order.h"
#include <iostream>

Order::Order(std::string on, Person* p,int q, bool b) 
    : orderName(on)
    , person(p)
    , quantity(q)
    , buy(b)
{}

void Order::printInfo() {
    if (buy) {
        std::cout<<"Buy";
    }
    else {
        std::cout<<"Sell";
    }
    std::cout<<", name: "<<orderName;
    std::cout<<", "<<person->name<<", ";
    std::cout<<quantity<<" shares";
}

void Order::print()
{
    printInfo();
    std::cout<<"\n\n";
}

bool Order::execute(std::string CompanyName, unsigned int shares, double value)
{
    if (buy && person->canBuy(shares, value))
    {
        person->buy(CompanyName, shares, value);
    }
    else if (!buy && person->canSell(CompanyName, shares, value))
    {
        person->sell(CompanyName, shares, value);
    }
    else
    {
        std::cout<<orderName<<" can't "<<(buy ? "buy" : "sell")<<"\n";
        return false;
    }
    quantity -= shares;
    return true;
}