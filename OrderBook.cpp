#include "OrderBook.h"
#include "LimitOrder.h"
#include <iostream>

// Compare function
bool OrderBook::Compare::operator()(PriceLevel* below, PriceLevel* above)
{
    return above->price >= below->price;
}

// PriceLevel functions
OrderBook::PriceLevel::PriceLevel(LimitOrder* lo)
    : price(lo->price)
    , head(lo)
    , tail(lo)
{}

void OrderBook::PriceLevel::adjust()
{
    if (head == nullptr && tail != nullptr) head = tail;
    if (head != nullptr && tail == nullptr) tail = head;
}

LimitOrder* OrderBook::PriceLevel::peek()
{
    return head;
}

void OrderBook::PriceLevel::pop()
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

void OrderBook::PriceLevel::insert(LimitOrder* lo)
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

void OrderBook::PriceLevel::cancel(LimitOrder* lo)
{
    if (head == tail) tail = nullptr;
    LimitOrder* prev = lo->prev;
    LimitOrder* next = lo->next;
    if (prev != nullptr) prev->next = next;
    if (next != nullptr) next->prev = prev;
    adjust();
    delete lo;
}

bool OrderBook::PriceLevel::isEmpty()
{
    return head == nullptr && tail == nullptr;
}

void OrderBook::PriceLevel::print()
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

OrderBook::PriceLevel::~PriceLevel()
{
    LimitOrder* cur = head;
    while (cur != nullptr)
    {
        LimitOrder* next = cur->next;
        delete cur;
        cur = next;
    }
}

// OrderBook functions

OrderBook::OrderBook(bool b)
    : buy(b)
{}

int OrderBook::price()
{
    return prices.top()->price;
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
    prices.top()->pop();
    adjust();
}

void OrderBook::insert(LimitOrder* lo)
{
    auto it = price_map.find(lo->price);
    PriceLevel* pl;
    if (it != price_map.end())
    {
        pl = it->second;
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
    PriceLevel* pl = price_map.find(lo->price)->second;
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
    for (const auto& [key, value] : price_map)
    {
        value->print();
    }
    std::cout<<"\n";
}

bool OrderBook::isEmpty()
{
    for (const auto& [key, value] : price_map)
    {
        if (!(value->isEmpty())) return false;
    }
    return true;
}

OrderBook::~OrderBook()
{
    for (const auto& [key, value] : price_map)
    {
        delete value;
    }
}

void OrderBook::debug()
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
    for (const auto& [key, value] : price_map)
    {
        value->print();
    }
    std::cout<<"\n";
}