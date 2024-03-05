#pragma once
#include "Order.h"

class LimitOrder;
class CancelOrder : public Order
{
    private:
    LimitOrder* order;

    public:
    CancelOrder(std::string on,LimitOrder* order);
    void print();
    void action(MatchingEngine& meng);
    void debug();
};