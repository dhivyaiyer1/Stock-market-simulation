#pragma once
#include "OrderBook.h"

class Order;
class MarketOrder;
class LimitOrder;
class CancelOrder;

class MatchingEngine {
    private:
    OrderBook buyOrders;
    OrderBook sellOrders;
    void matchLimitOrders();
    void trade(Order* sell, Order* buy);
    
    public:
    std::string name;
    MatchingEngine(std::string name);
    void print();
    double buyPrice();
    double sellPrice();
    void add(Order* order);
};