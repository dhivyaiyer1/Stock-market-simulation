#include "CancelOrder.h"
#include <iostream>

CancelOrder::CancelOrder(std::string on,LimitOrder* order)
    : Order(on, order->person, order->quantity, order->buy)
    , order(order)
{}

void CancelOrder::print() {
    std::cout<<"Cancel ";
    order->print();
}