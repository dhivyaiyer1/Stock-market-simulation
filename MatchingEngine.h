#pragma once
#include "OrderBook.h"

class Order;
class MarketOrder;
class LimitOrder;
class CancelOrder;

class MatchingEngine {
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
};