#include "MarketOrder.h"
#include "MatchingEngine.h"

MarketOrder::MarketOrder(std::string on, Person* p, int q, bool b)
    : Order(on,p,q,b)
{}

void MarketOrder::print() {
    std::cout<<"Market ";
    printInfo();
    std::cout<<"\n\n";
}