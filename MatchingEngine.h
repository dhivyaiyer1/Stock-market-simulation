#pragma once
#include "OrderBook.h"

class Order;
class MarketOrder;
class LimitOrder;

class MatchingEngine {
    private:
    std::string companyName;

    public:
    OrderBook buyOrders;
    OrderBook sellOrders;
    void matchLimitOrders();
    void trade(Order* o1, LimitOrder* o2);
    
    
    MatchingEngine(std::string name);
    void print();
    double buyPrice();
    double sellPrice();
    void cancel(LimitOrder* lo);
    void cancel(MarketOrder* mo);
};