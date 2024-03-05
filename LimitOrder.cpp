#include "LimitOrder.h"
#include "MarketOrder.h"
#include "MatchingEngine.h"

LimitOrder::LimitOrder(std::string on, Person* p, double pr, unsigned int q, bool b)
    : Order(on,p,q,b)
    , price(pr)
    , prev(nullptr)
    , next(nullptr)
{
    if (!b) price = (-price);
}

LimitOrder::LimitOrder(MarketOrder* lo, double pr)
    //: Order(lo->orderName,lo->person,lo->quantity,lo->buy)
    //, price(pr)
    //, prev(nullptr)
    //, next(nullptr)
    : LimitOrder(lo->orderName, lo->person, pr, lo->quantity, lo->buy)
{}

void LimitOrder::print() {
    std::cout<<"Limit, ";
    printInfo();
    std::cout<<", $"<<price<<"\n\n";
}

void LimitOrder::action(MatchingEngine& meng)
{
    OrderBook& orders = buy ? meng.buyOrders : meng.sellOrders;
    orders.insert(this);
}

void LimitOrder::debug()
{
    std::cout<<"Limit order\n";
    Order::debug();
    std::cout<<"Price: $"<<price<<"\n";
}