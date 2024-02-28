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
    buyOrders.printAllOrders();
    sellOrders.printAllOrders();
}

double MatchingEngine::buyPrice() {
    return buyOrders.peek()->price;
}

double MatchingEngine::sellPrice() {
    return sellOrders.peek()->price;
}

void MatchingEngine::trade(Order* sell, Order* buy) {
    int q = sell->quantity <= buy->quantity ? sell->quantity : buy->quantity;
    double price = buy->price;
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
    if (!(sell->person->canSell(name, q, price))) 
    {
        std::cout<<"Order "<<sell->orderName<<" failed\n";
        cancel(sell);
    }
    else if (!(buy->person->canBuy(q, price)))
    {
        std::cout<<"Order "<<buy->orderName<<" failed\n";
        cancel(buy);
    }
    else
    {
        sell->execute(name,q,price);
        buy->execute(q,price);
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

void MatchingEngine::add(LimitOrder* lo)
{
    OrderBook& orders = lo->buy ? buyOrders : sellOrders;
    orders.insert(lo);
    matchLimitOrders();
}

void MatchingEngine::add(MarketOrder* mo)
{
    OrderBook& orders = mo->buy ? sellOrders : buyOrders;
    int market_price = orders->price();
    LimitOrder* lo = new LimitOrder*(mo, market_price);
    add(lo);
    delete mo;
    matchLimitOrders();
}

void MatchingEngine::add(CancelOrder* co)
{
    OrderBook& orders = co->buy ? buyOrders : sellOrders;
    orders.cancel(co->order);
    delete co;
    matchLimitOrders();
}