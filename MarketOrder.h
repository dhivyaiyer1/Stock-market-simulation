#pragma once
#include "Order.h"

class MarketOrder : public Order {
    public:
    MarketOrder(std::string on, Person* p, int q, bool b);
    void print();
    void action(MatchingEngine& meng);
};