#include "CancelOrder.h"
#include "MatchingEngine.h"
#include <iostream>

CancelOrder::CancelOrder(std::string on,LimitOrder* order)
    : Order(on, order->person, order->quantity, order->buy)
    , order(order)
{}

void CancelOrder::add(MatchingEngine& meng)
{
    OrderBook& orders = buy ? meng.buyOrders : meng.sellOrders;
    orders.cancel(order);
    delete order;
    delete this;
}

void CancelOrder::print() {
    std::cout<<"Cancel ";
    order->print();
}