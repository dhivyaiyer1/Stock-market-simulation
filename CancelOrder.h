#pragma once
#include "LimitOrder.h"

class CancelOrder : public Order
{
    private:
    LimitOrder* order;

    public:
    CancelOrder(std::string on,LimitOrder* order);
    void print();
    void action(MatchingEngine& meng);
};