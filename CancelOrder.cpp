#include "CancelOrder.h"
#include "MatchingEngine.h"

CancelOrder::CancelOrder(std::string on,LimitOrder* order)
    : Order(on, order->person, order->quantity, order->buy)
    , order(order)
{}

void CancelOrder::print() {
    std::cout<<"Cancel ";
    order->print();
}

void CancelOrder::action(MatchingEngine& meng)
{
    OrderBook& orders = buy ? meng.buyOrders : meng.sellOrders;
    orders.cancel(order);
    delete this;
}