#pragma once
#include "OrderBook.h"

class Order;
class LimitOrder;

class MatchingEngine : public TestObject{
    private:
    void matchLimitOrders();
    void trade(LimitOrder* sell, LimitOrder* buy);
    
    public:
    std::string name;
    OrderBook buyOrders;
    OrderBook sellOrders;
    MatchingEngine(std::string name);
    void print();
    double buyPrice();
    double sellPrice();
    void add(Order* order);
    void debug();
};