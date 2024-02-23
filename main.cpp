#include <iostream>
#include "Company.h"
#include "LimitOrder.h"
#include "Person.h"
#include "MarketOrder.h"
#include "CancelOrder.h"

using namespace std;

void placeOrder(Company& c, Order* o, bool print)
{
    std::cout<<"Placing order "<<o->orderName<<"\n";
	o->add(c.meng);
    c.meng.matchLimitOrders();
    if (print)
    {
        c.print();
    }
}

void changePrice(Company&c, LimitOrder* o, double new_price)
{
    OrderBook& orders = o->buy ? c.meng.buyOrders : c.meng.sellOrders;
    orders.changePrice(o,new_price);
    c.print();
}

void test()
{
    Company appl ("Apple");
    Person panda ("Pan Da");
    Person polu ("Polu");
    Person penguin ("Penguin");
    LimitOrder* order1 = new LimitOrder("a",&panda,10,5,1);
    LimitOrder* order2 = new LimitOrder("b",&panda,15,2,1);
    LimitOrder* order3 = new LimitOrder("c",&polu,20,3,1);
    LimitOrder* order4 = new LimitOrder("d",&polu,15,7,1);
    LimitOrder* order5 = new LimitOrder("e",&polu,13,13,1);
    LimitOrder* order6 = new LimitOrder("f",&panda,20,9,1);
    placeOrder(appl, order1,0);
    placeOrder(appl, order2,0);
    placeOrder(appl, order3,0);
    placeOrder(appl, order4,0);
    placeOrder(appl, order5,0);
    placeOrder(appl, order6,0);
    LimitOrder* order7 = new LimitOrder("g",&polu, 10,10,0);
    placeOrder(appl, order7,0);
    CancelOrder* order8 = new CancelOrder("h",order2);
    placeOrder(appl, order8,1);
    changePrice(appl, order5,25);
}

int main() {
    test();
}
