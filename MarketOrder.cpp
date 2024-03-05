#include "MarketOrder.h"
#include "MatchingEngine.h"
#include "LimitOrder.h"

MarketOrder::MarketOrder(std::string on, Person* p, int q, bool b)
    : Order(on,p,q,b)
{}

void MarketOrder::print() {
    std::cout<<"Market, ";
    printInfo();
    std::cout<<"\n\n";
}

void MarketOrder::debug()
{
    std::cout<<"Market order\n";
    Order::debug();
}

void MarketOrder::action(MatchingEngine& meng)
{
    OrderBook& orders = buy ? meng.sellOrders :meng.buyOrders;
    int market_price = orders.price();
    LimitOrder* lo = new LimitOrder(this, market_price);
    lo->action(meng);
    delete this;
}