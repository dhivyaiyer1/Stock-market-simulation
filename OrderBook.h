#pragma once
#include <queue>
#include <deque>
#include <unordered_map>
#include "TestObject.h"

class LimitOrder;
class OrderBook : public TestObject
{
    private:
    bool buy;
    class PriceLevel
    {
        private:
        LimitOrder* head;
        LimitOrder* tail;
        void adjust();

        public:
        int price;
        PriceLevel(LimitOrder* lo);
        ~PriceLevel();
        LimitOrder* peek();
        void pop();
        void insert(LimitOrder* lo);
        void cancel(LimitOrder* lo);
        bool isEmpty();
        void print();
    };
    class Compare
    {
        public:
        bool operator()(PriceLevel* below, PriceLevel* above);
    };
    std::priority_queue<OrderBook::PriceLevel*, std::deque<OrderBook::PriceLevel*>, OrderBook::Compare> prices;
    std::unordered_map<int, PriceLevel*> price_map;
    void adjust();

    public:
    OrderBook(bool b);
	~OrderBook();
    int price();
    LimitOrder* peek();
    void pop();
    void cancel(LimitOrder* lo);
    void insert(LimitOrder* lo);
    void print();
    bool isEmpty();
    void debug();
};