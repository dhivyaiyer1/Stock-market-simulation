#pragma once
#include "Order.h"

class MarketOrder;
class LimitOrder : public Order {
    
    public:
    LimitOrder* prev;
    LimitOrder* next;
    double price;
    LimitOrder(std::string on, Person* p, double pr, unsigned int q, bool b);
    LimitOrder(MarketOrder* lo, double pr);
    void print();
    void action(MatchingEngine& meng);
    void debug();
};