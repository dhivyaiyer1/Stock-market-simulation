#pragma once
#include "Test.h"

class OrderBook;

class TestOrderBook : public Test
{
    private:
    bool buy;
    OrderBook* ob;
    double top_price;
    void tests2run();

    public:
    TestOrderBook();
};