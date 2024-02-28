#pragma once
#include "LimitOrder.h"
#include <queue>
#include <deque>
#include <unordered_map>

class LimitOrder;

class OrderBook 
{
    public:
    OrderBook(bool b) : buy(b) {};
	~OrderBook();
    int price();
    LimitOrder* peek();
    void pop();
    void cancel(LimitOrder* lo);
    void insert(LimitOrder* lo);
    void print();

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
        bool operator(PriceLevel* below, PriceLevel* above);
    };
    std::priority_queue<PriceLevel*, std::deque<PriceLevel*>, Compare> prices;
    std::unordered_map<int, PriceLevel*> price_map;
    void adjust();
};