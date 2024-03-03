#include "MatchingEngine.h"
#include <iostream>
#include "Person.h"


MatchingEngine::MatchingEngine(std::string name)
    : buyOrders(1)
    , sellOrders(0)
    , name(name)
{}

void MatchingEngine::print() {
	std::cout<<"Printing matching engine for "<<name<<":\n";
    buyOrders.print();
    sellOrders.print();
}

double MatchingEngine::buyPrice() {
    return buyOrders.peek()->price;
}

double MatchingEngine::sellPrice() {
    return sellOrders.peek()->price;
}

void MatchingEngine::trade(LimitOrder* sell, LimitOrder* buy) {
    int q = sell->quantity <= buy->quantity ? sell->quantity : buy->quantity;
    double price = buy->price;
    if (!(sell->person->canSell(name, q))) 
    {
        std::cout<<"Order "<<sell->orderName<<" failed\n";
        sell->quantity = 0;
    }
    else if (!(buy->person->canBuy(q, price)))
    {
        std::cout<<"Order "<<buy->orderName<<" failed\n";
        buy->quantity = 0;
    }
    else
    {
        sell->execute(name,q,price);
        buy->execute(name,q,price);
        std::cout<<"Traded "<<q<<" of "<<sell->orderName<<" and "<<buy->orderName<<" @ $"<<price<<"\n";
    }
        
}

void MatchingEngine::matchLimitOrders() {
    while (!buyOrders.isEmpty() && !sellOrders.isEmpty() && buyPrice()>=sellPrice()) {
        LimitOrder* sell = sellOrders.peek();
        LimitOrder* buy = buyOrders.peek();
        trade(sell,buy);
        if (sell->quantity==0) {
			sellOrders.pop();
        }
        if (buy->quantity==0) {
			buyOrders.pop();
        }
    }
}

void MatchingEngine::add(Order* order)
{
    order->action(*this);
    matchLimitOrders();
}