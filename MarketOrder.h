#pragma once
#include "Order.h"

class Company;

class MarketOrder : public Order {
    public:
    MarketOrder(std::string on, Person* p, int q, bool b);
    void print();
    void add(MatchingEngine& meng);
};