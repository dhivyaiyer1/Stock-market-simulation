#include "Company.h"
#include "MarketOrder.h"
#include <iostream>
#include "OrderBook.h"
#include "LimitOrder.h"

MarketOrder::MarketOrder(std::string on, Person* p, int q, bool b)
    : Order(on,p,q,b)
{}

void MarketOrder::print() {
    std::cout<<"Market ";
    printInfo();
    std::cout<<"\n\n";
}

void MarketOrder::add(MatchingEngine& meng)
{
    OrderBook& orders = !buy ? meng.buyOrders : meng.sellOrders;
    while (quantity>0) {
        LimitOrder* lo = orders.peek();
        meng.trade(this,lo);
        if (lo->quantity==0) {
            orders.poll();
            delete lo;
        }
    }
    delete this;
}