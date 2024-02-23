#include "LimitOrder.h"
#include <iostream>
#include "MatchingEngine.h"


LimitOrder::LimitOrder(std::string on, Person* p, double pr, unsigned int q, bool b)
    : Order(on,p,q,b)
    , price(pr)
{}

void LimitOrder::print() {
    std::cout<<"Limit, ";
    printInfo();
    std::cout<<"$"<<price<<"\n\n";
}

void LimitOrder::add(MatchingEngine& meng) 
{
    OrderBook& orders = buy ? meng.buyOrders : meng.sellOrders;
    orders.insert(this);
}