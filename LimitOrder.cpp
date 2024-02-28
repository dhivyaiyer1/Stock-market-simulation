#include "LimitOrder.h"
#include <iostream>
#include "MarketOrder.h"

LimitOrder::LimitOrder(std::string on, Person* p, double pr, unsigned int q, bool b)
    : Order(on,p,q,b)
    , price(pr)
    , prev(nullptr)
    , next(nullptr)
{}

LimitOrder::LimitOrder(MarketOrder* lo, double pr)
    : Order(lo->on,lo->p,lo->q,lo->b)
    , price(pr)
    , prev(nullptr)
    , next(nullptr)
{}

void LimitOrder::print() {
    std::cout<<"Limit, ";
    printInfo();
    std::cout<<"$"<<price<<"\n\n";
}