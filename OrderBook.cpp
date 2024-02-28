#include "OrderBook.h"
#include <iostream>

bool Compare::operator(PriceLevel* below, PriceLevel* above)
{
    // sell orders (bids) are in ascending order by price
    // buy orders (asks) are in descending order by price
    return buy ? above->price >= below->price : above->price <= below->price
}

// PriceLevel functions

PriceLevel::PriceLevel(LimitOrder* lo)
    : price(lo->price)
    , head(lo)
    , tail(lo)
{}

void PriceLevel::adjust()
{
    if (head == nullptr && tail != nullptr) head = tail;
    if (head != nullptr && tail == nullptr) tail = head;
}

LimitOrder* PriceLevel::peek()
{
    return head;
}

void PriceLevel::pop()
{
    if (head == tail) tail = nullptr;
    LimitOrder* lo = head;
    LimitOrder* next = head->next;
    head = next;
    next->prev = nullptr;
    lo->prev = nullptr;
    lo->next = nullptr;
    delete lo;
    adjust();
}

void PriceLevel::insert(LimitOrder* lo)
{
    if (isEmpty())
    {
        head = lo;
    }
    else
    {
        tail->next = lo;
        lo->prev = tail;
    }
    tail = lo;
}

void PriceLevel::cancel(LimitOrder* lo)
{
    if (head == tail) tail = nullptr;
    LimitOrder* prev = lo->prev;
    LimitOrder* next = lo->next;
    if (prev != nullptr) prev->next = next;
    if (next != nullptr) next->prev = prev;
    adjust();
    delete lo;
}

bool PriceLevel::isEmpty()
{
    return head == nullptr && tail == nullptr;
}

void PriceLevel::print()
{
    std::cout<<"Price level for $"<<price<<":\n";
    std::cout<<"Orders:\n";
    LimitOrder* cur = head;
    while (cur != nullptr)
    {
        cur->print();
        cur = cur->next;
    }
    std::cout<<"\n";
}

// OrderBook functions

int OrderBook::price()
{
    return prices->top()->price;
}

void OrderBook::adjust()
{
    PriceLevel* pl = prices.top();
    while (pl->isEmpty())
    {
        prices.pop();
        delete pl;
        pl = prices.top();
    }
}

LimitOrder* OrderBook::peek()
{
    adjust();
    PriceLevel* pl = prices.top();
    LimitOrder* lo = pl->peek();
    return lo;
}

void OrderBook::pop()
{
    adjust();
    LimitOrder* lo = peek();
    adjust();
    delete lo;

void OrderBook::insert(LimitOrder* lo)
{
    PriceLevel* pl;
    if (price_map.contains(lo->price))
    {
        pl = price_map.find(price);
        pl->insert(lo);
    }
    else
    {
        pl = new PriceLevel(lo);
        prices.push(pl);
        price_map.insert({lo->price, pl});
    }
}

void OrderBook::cancel(LimitOrder* lo)
{
    PriceLevel* pl = price_map.find(lo->price);
    pl->cancel(lo);
    adjust();
}

void OrderBook::print()
{
    if (buy)
    {
        std::cout<<"Buy";
    }
    else
    {
        std::cout<<"Sell";
    }
    std::cout<<" order book:\n";
    for (auto* pl : prices)
    {
        pl->print();
    }
    std::cout<<"\n";
}