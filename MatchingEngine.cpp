#include "MatchingEngine.h"
#include <iostream>
#include <typeinfo>
#include "Person.h"


MatchingEngine::MatchingEngine(std::string name)
    : buyOrders(1)
    , sellOrders(0)
    , companyName(name)
{}

void MatchingEngine::print() {
	std::cout<<"Printing matching engine:\n";
    buyOrders.printAllOrders();
    sellOrders.printAllOrders();
}

double MatchingEngine::buyPrice() {
    return buyOrders.peek()->price;
}

double MatchingEngine::sellPrice() {
    return sellOrders.peek()->price;
}

void MatchingEngine::trade(Order* o1, LimitOrder* o2) {
    int q = o1->quantity<=o2->quantity ? o1->quantity : o2->quantity;
    double price = o2->price;
    /*
    o1->quantity-=q;
    o2->quantity-=q;
    int mult = o1->buy ? -1 : 1;
    unsigned int q_exchange = mult*q;
    double cash_exchange = q_exchange*price;
    o1->person->shares -= q_exchange;
    o1->person->money += cash_exchange;
    o2->person->shares += q_exchange;
    o2->person->money -= cash_exchange;*/
    if (!(o1->execute(companyName,q,price)))
    {
        cancel(o1);
    }
    else if (!(o2->execute(companyName,q,price)))
    {
        cancel(o2);
    }
    else
    {
        std::cout<<"Traded "<<q<<" of "<<o1->orderName<<" and "<<o2->orderName<<" @ $"<<price<<"\n";
    }
}

void MatchingEngine::matchLimitOrders() {
    while (!buyOrders.isEmpty() && !sellOrders.isEmpty() && buyPrice()>=sellPrice()) {
        LimitOrder* l1 = sellOrders.peek();
        LimitOrder* l2 = buyOrders.peek();
        trade(l1,l2);
        if (l1->quantity==0) {
			sellOrders.poll();
			delete l1;
        }
        if (l2->quantity==0) {
			buyOrders.poll();
			delete l2;
        }
    }
}

void MatchingEngine::cancel(LimitOrder* lo)
{
    OrderBook& orders = lo->buy ? buyOrders : sellOrders;
    orders.cancel(lo);
    delete lo;
}

void MatchingEngine::cancel(MarketOrder* mo) 
{
    int x = 0;
}
