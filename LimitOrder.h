#pragma once
#include "Order.h"
#include <string>

class LimitOrder : public Order{
    public:
    double price;
    LimitOrder(std::string on, Person* p, double pr, unsigned int q, bool b);
    ~LimitOrder()
    {
        std::cout<<"Deleting "<<orderName<<"\n";
    };
    void print();
    void add(MatchingEngine& meng);
};