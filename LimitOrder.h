#pragma once
#include "Order.h"

class MarketOrder;
class LimitOrder : public Order {
    private:
    LimitOrder* prev;
    LimitOrder* next;

    public:
    double price;
    LimitOrder(std::string on, Person* p, double pr, unsigned int q, bool b);
    LimitOrder(MarketOrder* lo, double pr);
    ~LimitOrder()
    {
        std::cout<<"Deleting "<<orderName<<"\n";
    };
    void print();
    void action(MatchingEngine& meng);
};